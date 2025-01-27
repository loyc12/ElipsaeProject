#ifndef ORBITER_HPP
# define ORBITER_HPP

# include "../deps.hpp"
#include <raylib.h>
#include <string>

class World;

class Orbiter
{
	private:

	Vector2 _position;
	Vector2 _velocity;
	string  _posStr;

	bool _canMove; // Whether the orbiter can move
	bool _isGenerated; // Whether the orbiter mesh is up to date
	bool _isActivated; // Whether the orbiter is currently visible


	public:

	// ================================ CONSTRUCTORS
	Orbiter();
	Orbiter( bool canMove );
	Orbiter( Vector2 position, Vector2 velocity );
	Orbiter( const Orbiter &other );
	Orbiter &operator=( const Orbiter &other );
	~Orbiter();

	// ================================ ACCESSORS

	World *getWorld() const;

	Vector2 getPosition() const;
	string getPosString();
	string getPosSentence( const char* str);

	Vector2 getVelocity() const;
	string getVelString();
	string getVelSentence( const char* str);

	void setMovability( bool canMove );
	void setPosition( float x, float y );
	void setVelocity( float x, float y );

	// ================================ BOOLEAN METHODS

	bool CanMove() const;
	bool isGenerated() const;
	bool isActivated() const;

	// ================================ CORE METHODS

	bool initiate();
	bool generate();
	bool activate();
	bool deactivate();

	void drawSelf();
};


#endif // ORBITER_HPP