#include "../../inc/class/Orbiter.hpp"
#include "../../inc/class/Engine.hpp"

Orbiter::Orbiter()
{
	log( "Orbiter::Orbiter(1)", DEBUG );

	_position = { 0, 0 };
	_velocity = { 0, 0 };

	_canMove = true;
	_isGenerated = false;
	_isActivated = false;
}

Orbiter::Orbiter( bool canMove )
{
	log( "Orbiter::Orbiter(2)", DEBUG );

	_position = { 0, 0 };
	_velocity = { 0, 0 };

	_canMove = canMove;
	_isGenerated = false;
	_isActivated = false;
}

Orbiter::Orbiter( Vector2 position, Vector2 velocity )
{
	log( "Orbiter::Orbiter(3)", DEBUG );

	_position = position;
	_velocity = velocity;

	_canMove = true;
	_isGenerated = false;
	_isActivated = false;
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
	//if ( _orbiterMesh ) delete _orbiterMesh; // TMP
}

// ================================ ACCESSORS

World *Orbiter::getWorld() const { return ( getEngine()->getWorld()); }

// ================ POSITION

Vector2 Orbiter::getPosition() const { return _position; }

string Orbiter::getPosString()
{
	if ( _posStr.empty() )
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
	stringstream ss;
	ss << "[" << _velocity.x << ":" << _velocity.y << "]";
	return ss.str();
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
}

// ================ OTHERS

bool Orbiter::CanMove()     const { return _canMove; }
bool Orbiter::isGenerated() const { return _isGenerated; }
bool Orbiter::isActivated() const { return _isActivated; }

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