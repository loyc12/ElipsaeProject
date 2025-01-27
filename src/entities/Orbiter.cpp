#include "../../inc/class/Orbiter.hpp"
#include "../../inc/class/Engine.hpp"

Orbiter::Orbiter()
{
	log( "Orbiter::Orbiter(1)", DEBUG );

	_orbiterPos = { 0, 0 };
	_isGenerated = false;
	_isActivated = false;
}

Orbiter::Orbiter( pos2_s orbiterPos )
{
	log( "Orbiter::Orbiter(2)", DEBUG );

	_orbiterPos = orbiterPos;
	_isGenerated = false;
	_isActivated = false;
}

Orbiter::Orbiter( const Orbiter &other )
{
	_orbiterPos = other.getOrbiterPos();

	_isGenerated = other.isGenerated();
	_isActivated = other.isActivated();
}

Orbiter &Orbiter::operator=( const Orbiter &other )
{
	_orbiterPos = other.getOrbiterPos();

	_isGenerated = other.isGenerated();
	_isActivated = other.isActivated();

	return *this;
}

Orbiter::~Orbiter()
{
	log( getOrbiterPosSentence( "Orbiter::~Orbiter()" ).c_str(), DEBUG );
	//if ( _orbiterMesh ) delete _orbiterMesh; // TMP
}

// ================================ ACCESSORS

World *Orbiter::getWorld() const { return ( getEngine()->getWorld()); }
pos2_s Orbiter::getOrbiterPos() const { return _orbiterPos; }

string Orbiter::getOrbiterPosString()
{
	if ( _posStr.empty() )
	{
		stringstream ss;
		ss << "[" << _orbiterPos.x << ":" << _orbiterPos.y << "]";
		_posStr = ss.str();
	}

	return _posStr;
}

string Orbiter::getOrbiterPosSentence( const char* str )
{
	stringstream ss;
	ss << "Orbiter " << getOrbiterPosString() << " : " << str;
	return ss.str();
}

void Orbiter::setOrbiterPos( int x, int y )
{
	_orbiterPos.x = x;
	_orbiterPos.y = y;

	_posStr.clear();
}



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

	log( getOrbiterPosSentence( "Orbiter::initiate() failed" ).c_str(), WARN );

	return false;
}

bool Orbiter::generate()
{

	if ( _isGenerated )
	{
		log( getOrbiterPosSentence( "Orbiter already generated" ).c_str(), WARN );
		return true;
	}
	log( getOrbiterPosSentence( "Orbiter::generate()" ).c_str(), DEBUG );

	// Generate the relevant OrbiterData here

	_isGenerated = true;

	return true;
}

bool Orbiter::activate()
{
	if ( !_isGenerated )
	{
		log( getOrbiterPosSentence( "Orbiter not yet generated" ).c_str(), WARN );
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