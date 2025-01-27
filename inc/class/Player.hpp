#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "../deps.hpp"
# include "./Orbiter.hpp"
# include "./ViewPort.hpp"


class Player : Orbiter // NOTE : have it inherit from Orbiter class
{
	private:

	ViewPort _viewPort;

	public:

	// ================================ CONSTRUCTORS
	Player();
	Player( Vector2 pos, Vector2 vel, angle_t rot );
	Player( Player &other );
	Player &operator=( Player &other );
	~Player();

	// ================================ ACCESSORS

	ViewPort *getViewport();

	void setViewPortZoom( float zoom );

	// ================================ UPDATE METHODS

	void updateViewPort();

	void updatePosition();
	void updateVelocity();
	void updateRotation();

	void updateSelf();

	// ================================ CORE METHODS

	void drawSelf();

	void registerInputs();

};

#endif // PLAYER_HPP