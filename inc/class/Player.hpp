#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "../deps.hpp"
#include <raylib.h>

# define PLAYER_FOV 	80.0f
# define TURN_FACTOR	0.1f
# define MOVE_FACTOR	0.4f

class Player // NOTE : put camera stuff in a Screen class instead ??
{
	private:

	Vector3 _position;
	Camera3D _camera;

	public:

	// ================================ CONSTRUCTORS
	Player();
	~Player();

	// ================================ ACCESSORS
	Camera3D *getCamera();

	void setPosition( Vector3 pos );
	void moveBy( Vector3 movement );

	void setTarget( Vector3 target );
	void setDirection( Vector3 direction );
	//void turnBy( ? rotation );

	void setFOV( float fovy );

	Vector3 getPosition() const;
	Vector3 getDirection() const;
	Vector3 getTarget() const;

	// ================================ CORE METHODS

	void update();

};

#endif // PLAYER_HPP