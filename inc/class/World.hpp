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
	Orbiter *getOrbiter( pos3_s orbiterPos );
	Orbiter *getOrbiter( int x, int y, int z );

	bool setOrbiter( pos3_s orbiterPos,   Orbiter *orbiter );
	bool setOrbiter( int x, int y, int z, Orbiter *orbiter );

	// ================================ BOOLEAN METHODS

	bool isVoxelInWorld( pos3_s voxelWorldPos ) const;
	bool isVoxelInWorld( int x, int y, int z ) const;

	bool isOrbiterInWorld( pos3_s OrbiterPos ) const;
	bool isOrbiterInWorld( int x, int y, int z ) const;

	bool isOrbiterGenerated( pos3_s orbiterPos );
	bool isOrbiterGenerated( int x, int y, int z );

	bool isOrbiterActivated( pos3_s orbiterPos );
	bool isOrbiterActivated( int x, int y, int z );

	// ================================ CORE METHODS

	void initiateOrbiters();
	void populateOrbiters();

	void generateOrbiters();
	void offloadOrbiters();

	void activateOrbiters();
	void deactivateOrbiters();

	void drawActivatedOrbiters();
};

Orbiter		 *getWorldOrbiter( pos3_s orbiterPos );
World			 *getEngineWorld();

#endif // WORLD_HPP