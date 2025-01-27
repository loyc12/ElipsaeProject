#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "../deps.hpp"
# include "./ViewPort.hpp"


class Player // NOTE : have it inherit from Orbiter class
{
	private:

	Vector2  _position;
	Vector2  _direction;
	Vector2	 _velocity;

	ViewPort _viewPort;

	public:

	// ================================ CONSTRUCTORS
	Player();
	Player( Vector2 pos, Vector2 dir, Vector2 vel );
	Player( Player &other );
	Player &operator=( Player &other );
	~Player();

	// ================================ ACCESSORS

	ViewPort *getViewport();
	Camera2D *getCamera();

	Vector2 getPosition() const;
	Vector2 getDirection() const;
	Vector2 getVelocity() const;

	void setPosition( Vector2 pos );
	void setDirection( Vector2 dir );
	void setVelocity( Vector2 vel );

	void setViewPortZoom( float zoom );

	void moveBy( Vector2 movement );
	void moveTowards( Vector2 target );

	void accelerateBy( Vector2 acceleration );
	void accelerateTowards( Vector2 target );

	void rotateBy( float angle );
	void rotateTowards( Vector2 target );


	// ================================ CORE METHODS

	void updatePosition();
	void updateDirection();
	void updateVelocity();

	void updateViewPort();

	void updateSelf();
	void drawSelf();

	void registerInputs();

};

#endif // PLAYER_HPP