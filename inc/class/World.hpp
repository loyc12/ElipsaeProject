#ifndef WORLD_HPP
# define WORLD_HPP

# include "../deps.hpp"
# include "./Orbiter.hpp"

class Orbiter;

typedef vector< Orbiter > OrbList;

class World
{
	private:

	OrbList _orbiters;

	public:

	// ================================ CONSTRUCTORS
	World();
	World( OrbList *orbiters );
	~World();

	// ================================ ACCESSORS

	// ================================ BOOLEAN METHODS

	// ================================ CORE METHODS

	void spawnOrbiter( Vector2 orbiterPos, Orbiter &orbiter );
	void spawnOrbiter( float x, float y,   Orbiter &orbiter );

	void initiateOrbiters();
	void populateOrbiters();

	void generateOrbiters();
	void offloadOrbiters();

	void activateOrbiters();
	void deactivateOrbiters();

	void drawActivatedOrbiters();
};

Orbiter	*getWorldOrbiter( Vector2 orbiterPos );
World		*getEngineWorld();

#endif // WORLD_HPP