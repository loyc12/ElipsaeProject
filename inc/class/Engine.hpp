#ifndef ENGINE_HPP
# define ENGINE_HPP

# include "../deps.hpp"
# include "./World.hpp"
# include "./Player.hpp"


class Engine
{
	private:

	World  *_world;
	Player *_player;
	Noise  *_noise;

	bool _running;

	public:

	// ================================ CONSTRUCTORS

	Engine();
	Engine( World &world, Player &player );
	~Engine();

	// ================================ ACCESSORS

	World *getWorld();

	Player *getPlayer() ;
	Camera2D *getCamera();

	Noise *getNoise();
	Noise *setNoiseSeed( int64_t seed );

	Orbiter *getOrbiterInWorld( pos2_s orbiterPos );
	Orbiter *getOrbiterInWorld( int x, int y );

	vox_type_e getVoxelInWorld( pos2_s voxelWorldPos ) const;
	vox_type_e getVoxelInWorld( int x, int y ) const;

	bool setOrbiterInWorld( pos2_s orbiterPos, Orbiter *orbiter );
	bool setOrbiterInWorld( int x, int y, Orbiter *orbiter );

	bool setVoxelInWorld( pos2_s voxelWorldPos, vox_type_e type );
	bool setVoxelInWorld( int x, int y, vox_type_e type );

	// ================================ BOOLEAN METHODS
	bool isRunning() const;
	bool isRunning( bool b );

	// ================================ CORE METHODS
	void init();
	void start();
	void stop();
	void close();

	// ================================ STEP METHODS
	void launch();
	void inputs();
	void update();
	void render();
};

Engine *getEngine(); // Singleton for the engine

#endif // ENGINE_HPP

