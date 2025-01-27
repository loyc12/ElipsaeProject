#ifndef ORBITER_HPP
# define ORBITER_HPP

# include "../deps.hpp"
#include <raylib.h>
#include <string>

class World;

class Orbiter
{
	protected:

	Vector2 _position;
	Vector2 _velocity;
	angle_t _rotation;

	string  _posStr;
	string  _velStr;
	string  _rotStr;

	bool _canMove; // Whether the orbiter can move
	bool _isGenerated; // Whether the orbiter mesh is up to date
	bool _isActivated; // Whether the orbiter is currently visible


	public:

	// ================================ CONSTRUCTORS
	Orbiter();
	Orbiter( bool canMove );
	Orbiter( Vector2 pos, Vector2 vel, angle_t rot );
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

	angle_t getRotation() const;
	string getRotString();
	string getRotSentence( const char* str);

	void setPosition( float x, float y );
	void setVelocity( float x, float y );
	void setRotation( angle_t rotation );

	// ================================ BOOLEAN METHODS

	void setMovability( bool val );

	bool CanMove() const;
	bool isGenerated() const;
	bool isActivated() const;

		// ================================ MOVEMENT

	void moveBy( Vector2 movement );
	void moveTowards( Vector2 target, float dist );

	void accelerateBy( Vector2 speed );
	void accelerateTowards( Vector2 target, float speed );

	void rotateBy( angle_t angle );
	void rotateTowards( Vector2 target, angle_t angle );

	// ================================ UPDATE METHODS

	void updatePosition();
	void updateVelocity();
	void updateRotation();

	// ================================ CORE METHODS

	bool initiate();
	bool generate();
	bool activate();
	bool deactivate();

	void drawSelf();
};


#endif // ORBITER_HPP