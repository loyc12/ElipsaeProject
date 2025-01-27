#include "../../inc/class/World.hpp"
#include "../../inc/class/Engine.hpp"

World *getEngineWorld() { return getEngine()->getWorld(); }

World::World()
{
	log( "World::World(1)", INFO );

	initiateOrbiters();
}

World::World( OrbList *orbiters )
{
	log( "World::World(2)", INFO );

	_orbiters = *orbiters;
}

World::~World()
{
	log( "World::~World()", INFO );

}

// ================================ ACCESSORS

// ================================ BOOLEAN METHODS

// ================================ CORE METHODS

void World::spawnOrbiter( Vector2 orbiterPos, Orbiter &orbiter ) { spawnOrbiter( orbiterPos.x, orbiterPos.y, orbiter ); }

void World::spawnOrbiter( float x, float y, Orbiter &orbiter )
{
	log( "World::spawnOrbiter()", DEBUG );

	// WIP
}


void World::initiateOrbiters()
{
	// WIP
}

void World::generateOrbiters()
{
	log( "World::generateOrbiters()", DEBUG );

	// WIP
}

void World::activateOrbiters()
{
	log( "World::activateOrbiters()", DEBUG );

	// WIP
}

void World::deactivateOrbiters()
{
	log( "World::deactivateOrbiters()", DEBUG );

	// WIP
}

void World::drawActivatedOrbiters()
{
	//log( "World::drawActivatedOrbiters()", DEBUG );

	// WIP
}