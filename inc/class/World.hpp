#ifndef WORLD_HPP
# define WORLD_HPP

# include "../deps.hpp"
# include "./Orbiter.hpp"

#define ORBITER_COUNT 1000

class Orbiter;

class World
{
	private:

	Orbiter *_orbiters[ ORBITER_COUNT ]; // NOTE : fixed size for now

	public:

	// ================================ CONSTRUCTORS
	World();
	World( Orbiter **orbiters );
	~World();

	// ================================ ACCESSORS
	Orbiter *getOrbiter( pos2_s orbiterPos );
	Orbiter *getOrbiter( int x, int y );

	bool setOrbiter( pos2_s orbiterPos,   Orbiter *orbiter );
	bool setOrbiter( int x, int y, Orbiter *orbiter );

	// ================================ BOOLEAN METHODS

	bool isVoxelInWorld( pos2_s voxelWorldPos ) const;
	bool isVoxelInWorld( int x, int y ) const;

	bool isOrbiterInWorld( pos2_s OrbiterPos ) const;
	bool isOrbiterInWorld( int x, int y ) const;

	bool isOrbiterGenerated( pos2_s orbiterPos );
	bool isOrbiterGenerated( int x, int y );

	bool isOrbiterActivated( pos2_s orbiterPos );
	bool isOrbiterActivated( int x, int y );

	// ================================ CORE METHODS

	void initiateOrbiters();
	void populateOrbiters();

	void generateOrbiters();
	void offloadOrbiters();

	void activateOrbiters();
	void deactivateOrbiters();

	void drawActivatedOrbiters();
};

Orbiter		 *getWorldOrbiter( pos2_s orbiterPos );
World			 *getEngineWorld();

#endif // WORLD_HPP