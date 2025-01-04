#include "../../inc/class/World.hpp"
#include "../../inc/class/Engine.hpp"

World *getEngineWorld() { return getEngine()->getWorld(); }

World::World()
{
	log( "World::World(1)", INFO );

	initiateOrbiters();
}

World::World( Orbiter **orbiters )
{
	log( "World::World(2)", INFO );

	for ( int i = 0; i < ORBITER_COUNT; i++ )
	{
		_orbiters[ i ] = new Orbiter( *orbiters[ i ]);
	}
}

World::~World()
{
	log( "World::~World()", INFO );


}

// ================================ ACCESSORS

// ================================ BOOLEAN METHODS

// ================================ CORE METHODS

void World::initiateOrbiters()
{
	log( "World::initiateOrbiters()", DEBUG );

	for ( int i = 0; i < ORBITER_COUNT; i++ )
	{
		_orbiters[ i ] = new Orbiter();
	}
}

void World::generateOrbiters()
{
	log( "World::generateOrbiters()", DEBUG );

	for ( int i = 0; i < ORBITER_COUNT; i++ )
	{
		Orbiter *orb = _orbiters[ i ];

		if ( orb && !orb->isGenerated() )
		_orbiters[ i ]->generate();
	}
}

void World::activateOrbiters()
{
	log( "World::activateOrbiters()", DEBUG );

	for ( int i = 0; i < ORBITER_COUNT; i++ )
	{
		Orbiter *orb = _orbiters[ i ];

		if ( orb && !orb->isActivated() )
		_orbiters[ i ]->activate();
	}
}

void World::deactivateOrbiters()
{
	log( "World::deactivateOrbiters()", DEBUG );

	for ( int i = 0; i < ORBITER_COUNT; i++ )
	{
		Orbiter *orb = _orbiters[ i ];

		if ( orb && orb->isActivated() )
		_orbiters[ i ]->deactivate();
	}
}

void World::drawActivatedOrbiters()
{
	//log( "World::drawActivatedOrbiters()", DEBUG );

	for ( int i = 0; i < ORBITER_COUNT; i++ )
	{
		Orbiter *orb = _orbiters[ i ];

		if ( orb && orb->isActivated() )
		_orbiters[ i ]->drawSelf();
	}
}