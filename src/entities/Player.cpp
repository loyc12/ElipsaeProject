#include "../../inc/class/Player.hpp"

Player::Player()
{
	log( "Player::Player(1)", INFO );

	_position  = { 0, 0 };
	_direction = { 0, 1 };
	_velocity  = { 0, 0 };
}

Player::Player( Vector2 pos, Vector2 dir, Vector2 vel )
{
	log( "Player::Player(2)", INFO );

	_position = pos;
	_direction = dir;
	_velocity = vel;
}

Player::Player( Player &other )
{
	_position = other.getPosition();
	_direction = other.getDirection();
	_velocity = other.getVelocity();

	_viewPort = *other.getViewport();
}

Player &Player::operator=( Player &other )
{
	_position = other.getPosition();
	_direction = other.getDirection();
	_velocity = other.getVelocity();

	_viewPort = *other.getViewport();

	return *this;
}

Player::~Player()
{
	log( "Player::~Player()", INFO );
}

// ================================ ACCESSORS

Camera2D *Player::getCamera() { return _viewPort.getCamera(); }

void Player::setPosition( Vector2 pos ) { _position = pos; }
void Player::setDirection( Vector2 dir ) { _direction = dir; }
void Player::setVelocity( Vector2 vel ) { _velocity = vel; }

void Player::setViewPortZoom( float zoom ) { _viewPort.setZoom( zoom ); }

void Player::moveBy( Vector2 movement )
{
	_position.x += movement.x;
	_position.y += movement.y;

	updateViewPort();
}

void Player::moveTowards( Vector2 target )
{
	(void)target;
	// WIP

	updateViewPort();
}

void Player::accelerateBy( Vector2 acceleration )
{
	_velocity.x += acceleration.x;
	_velocity.y += acceleration.y;
}

void Player::accelerateTowards( Vector2 target )
{
	(void)target;
	// WIP
}

void Player::rotateBy( float angle )
{
	(void)angle;
	// WIP
}

void Player::rotateTowards( Vector2 target )
{
	(void)target;
	// WIP
}

Vector2 Player::getPosition()  const { return _position; }
Vector2 Player::getDirection() const { return _direction; }
Vector2 Player::getVelocity()  const { return _velocity; }

ViewPort *Player::getViewport() { return &_viewPort; }

// ================================ CORE METHODS

void Player::updatePosition()
{
	_position.x += _velocity.x;
	_position.y += _velocity.y;

	updateViewPort();
}

void Player::updateDirection()
{
	// WIP
}

void Player::updateVelocity()
{
	// WIP
}

void Player::updateViewPort()
{
	_viewPort.setCenter( _position );
	_viewPort.updateSelf();
}

void Player::updateSelf()
{
	registerInputs();

	updateDirection();
	updateVelocity();

	updatePosition();
	updateViewPort();
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