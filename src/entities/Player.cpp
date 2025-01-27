#include "../../inc/class/Player.hpp"

Player::Player() : Orbiter()
{
	log( "Player::Player(1)", INFO );

	_viewPort = ViewPort( _position, 1.0f );
}

Player::Player( Vector2 pos, Vector2 vel, angle_t rot ) : Orbiter( pos, vel, rot )
{
	log( "Player::Player(2)", INFO );

	_viewPort = ViewPort( _position, 1.0f );
}

Player::Player( Player &other ) : Orbiter( other )
{
	_viewPort = *other.getViewport();
}

Player &Player::operator=( Player &other )
{
	_position = other.getPosition();
	_velocity = other.getVelocity();
	_rotation = other.getRotation();

	_viewPort = *other.getViewport();

	_canMove = true;
	_isGenerated = true;
	_isActivated = true;

	return *this;
}

Player::~Player()
{
	log( "Player::~Player()", INFO );
}

// ================================ ACCESSORS

ViewPort *Player::getViewport() { return &_viewPort; }

void Player::setViewPortZoom( float zoom ) { _viewPort.setZoom( zoom ); }

// ================================ UPDATE METHODS

void Player::updateViewPort()
{
	_viewPort.setCenter( _position );
	_viewPort.updateSelf();
}

void Player::updatePosition()
{
	_position.x += _velocity.x;
	_position.y += _velocity.y;

	updateViewPort();
}

void Player::updateVelocity()
{
	// WIP
}

void Player::updateRotation()
{
	// WIP
}

void Player::updateSelf()
{
	registerInputs();

	updateRotation();
	updateVelocity();
	updatePosition();
}

// ================================ CORE METHODS

void Player::drawSelf()
{
	// WIP
}

void Player::registerInputs() // TODO : refactor this shit m8
{
	//float rotFactor = 1.0f; // TEMP
	float accFactor = 1.0f;

	if( IsKeyDown( KEY_LEFT_CONTROL )) { accFactor *= 2; }
	if( IsKeyDown( KEY_LEFT_SHIFT ))   { accFactor /= 4; }

	if( IsKeyDown( KEY_W ) || IsKeyDown( KEY_UP ))
	{
		// ACCELERATE FORWARDS
		log( "Player accelerating forwards", INFO );
	}
	if( IsKeyDown( KEY_S ) || IsKeyDown( KEY_DOWN ))
	{
		// ACCELERATE BACKWARDS
		log( "Player accelerating backwards", INFO );
	}
	if( IsKeyDown( KEY_D ) || IsKeyDown( KEY_RIGHT ))
	{
		log( "Player turning right", INFO );
		// TURN RIGHT
	}
	if( IsKeyDown( KEY_A ) || IsKeyDown( KEY_LEFT ))
	{
		log( "Player turning left", INFO );
		// TURN LEFT
	}

	if( IsKeyDown( KEY_SPACE ) || IsKeyDown( KEY_ENTER ) || IsKeyDown( KEY_KP_ENTER ))
	{
		log( "Player slowing down", INFO );
		// DECELERATE
	}

	if( IsKeyDown( KEY_E ) || IsKeyDown( KEY_KP_0 ))
	{
		log( "Player acting", INFO );
		// INTERACT
	}


}