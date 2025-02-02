#include "../../inc/class/Orbiter.hpp"
#include "../../inc/class/Engine.hpp"

Orbiter::Orbiter()
{
	log( "Orbiter::Orbiter(1)", DEBUG );

	_position = { 0, 0 };
	_velocity = { 0, 0 };


	_isGenerated = false;
	_isActivated = false;
}

Orbiter::Orbiter( bool canMove ) : Orbiter() { _canMove = canMove; }

Orbiter::Orbiter( Vector2 pos, Vector2 vel, angle_t rot ) : Orbiter()
{
	_position = pos;
	_velocity = vel;
	_rotation = rot;
}

Orbiter::Orbiter( const Orbiter &other )
{
	_position = other.getPosition();
	_velocity = other.getVelocity();

	_canMove = other.CanMove();
	_isGenerated = other.isGenerated();
	_isActivated = other.isActivated();
}

Orbiter &Orbiter::operator=( const Orbiter &other )
{
	_position = other.getPosition();
	_velocity = other.getVelocity();

	_canMove = other.CanMove();
	_isGenerated = other.isGenerated();
	_isActivated = other.isActivated();

	return *this;
}

Orbiter::~Orbiter()
{
	log( getPosSentence( "Orbiter::~Orbiter()" ).c_str(), DEBUG );
}

// ================================ ACCESSORS

World *Orbiter::getWorld() const { return ( getEngine()->getWorld()); }

// ================ POSITION

Vector2 Orbiter::getPosition() const { return _position; }

string Orbiter::getPosString()
{
	if( _posStr.empty() )
	{
		stringstream ss;
		ss << "[" << _position.x << ":" << _position.y << "]";
		_posStr = ss.str();
	}

	return _posStr;
}

string Orbiter::getPosSentence( const char* str )
{
	stringstream ss;
	ss << "Orbiter " << getPosString() << " : " << str;
	return ss.str();
}

void Orbiter::setPosition( float x, float y )
{
	_position.x = x;
	_position.y = y;

	_posStr.clear();
}

// ================ VELOCITY

Vector2 Orbiter::getVelocity() const { return _velocity; }

string Orbiter::getVelString()
{
	if( _velStr.empty() )
	{
		stringstream ss;
		ss << "[" << _velocity.x << ":" << _velocity.y << "]";
		_velStr = ss.str();
	}

	return _velStr;
}

string Orbiter::getVelSentence( const char* str )
{
	stringstream ss;
	ss << "Orbiter " << getPosString() << " : " << str;
	return ss.str();
}

void Orbiter::setVelocity( float x, float y )
{
	_velocity.x = x;
	_velocity.y = y;

	_velStr.clear();
}

// ================ ROTATION

angle_t Orbiter::getRotation() const { return _rotation; }

string Orbiter::getRotString()
{
	if( _rotStr.empty() )
	{
		stringstream ss;
		ss << "[" << _rotation << "]";
		_rotStr = ss.str();
	}

	return _rotStr;
}

string Orbiter::getRotSentence( const char* str )
{
	stringstream ss;
	ss << "Orbiter " << getPosString() << " : " << str;
	return ss.str();
}

void Orbiter::setRotation( angle_t rotation )
{
	_rotation = rotation;
}

// ================================ BOOLEAN METHODS

void Orbiter::setMovability( bool val ) { _canMove = val; }

bool Orbiter::CanMove()     const { return _canMove; }
bool Orbiter::isGenerated() const { return _isGenerated; }
bool Orbiter::isActivated() const { return _isActivated; }

// ================================ MOVEMENT

void Orbiter::moveBy( Vector2 movement )
{
	_position.x += movement.x;
	_position.y += movement.y;
}

void Orbiter::moveTowards( Vector2 target, float dist )
{
	(void)target;
	(void)dist;

	// find normalized vector from position to target
	// multiply by dist
	// add to position

	// WIP
}

void Orbiter::accelerateBy( Vector2 speed )
{
	_velocity.x += speed.x;
	_velocity.y += speed.y;
}

void Orbiter::accelerateTowards( Vector2 target, float speed )
{
	(void)target;
	(void)speed;

	// find normalized vector from position to target
	// multiply by speed
	// add to velocity

	// WIP
}

void Orbiter::rotateBy( angle_t angle )
{
	(void)angle;

	// WIP
}

void Orbiter::rotateTowards( Vector2 target, angle_t angle )
{
	(void)target;
	(void)angle;

	// find normalized vector from position to target
	// find shortest rotation angle to that vector
	// rotate by angle * direction

	// WIP
}

// ================================ UPDATE METHODS

void Orbiter::updatePosition()
{
	_position.x += _velocity.x;
	_position.y += _velocity.y;

	_posStr.clear();
}

void Orbiter::updateVelocity()
{
	// WIP
}

void Orbiter::updateRotation()
{
	// WIP
}

// ================================ CORE METHODS

bool Orbiter::initiate()
{
	// log( getOrbiterPosSentence( "Orbiter::initiate()" ).c_str(), DEBUG );

	if ( generate() )
	{
		if ( activate() )
		{
			return true;
		}
	}

	log( getPosSentence( "Orbiter::initiate() failed" ).c_str(), WARN );

	return false;
}

bool Orbiter::generate()
{

	if ( _isGenerated )
	{
		log( getPosSentence( "Orbiter already generated" ).c_str(), WARN );
		return true;
	}
	log( getPosSentence( "Orbiter::generate()" ).c_str(), DEBUG );

	// Generate the relevant OrbiterData here

	_isGenerated = true;

	return true;
}

bool Orbiter::activate()
{
	if ( !_isGenerated )
	{
		log( getPosSentence( "Orbiter not yet generated" ).c_str(), WARN );
		return false;
	}

	_isActivated = true;

	return true;
}

bool Orbiter::deactivate()
{
	if ( !_isActivated ) return false;

	_isActivated = false;

	return true;
}


void Orbiter::drawSelf() // NOTE : too costly to call every frame. use stashed mesh instead ( how?? )
{
	if ( !_isActivated ) return;

	// WIP
}