#include "../inc/class/Engine.hpp"

Engine *getEngine()
{
	static Engine *ng;

	if( !ng )
	{
		ng = new Engine();
		ng->init();
	}

	return ng;
}

Engine::Engine()
{
	log( "Engine::Engine(1)", INFO );
	_world = new World();
	_player = new Player();
	this->_running = false;
}

Engine::Engine( World &world, Player &player )
{
	log( "Engine::Engine(2)", INFO );
	_world = &world;
	_player = &player;
	this->_running = false;
}

Engine::~Engine()
{
	log( "Engine::~Engine()", INFO );

	if ( _world != nullptr )  { delete _world; }
	if ( _player != nullptr ) { delete _player; }
	if ( _noise != nullptr )  { delete _noise; }
}

// ================================ ACCESSORS

World *Engine::getWorld() { return _world; }

Player *Engine::getPlayer() { return _player; }
Camera3D *Engine::getCamera() { return _player->getCamera(); }

Noise *Engine::getNoise()
{
	if ( _noise == nullptr )
	{
		log( "No seed provided for noise, using default seed.", WARN );
		_noise = new Noise();
	}
	return _noise;
}
Noise *Engine::setNoiseSeed( int64_t seed )
{
	if ( _noise != nullptr ) { delete _noise; }
	_noise = new Noise( seed );
	return _noise;
}
// ================================ BOOLEAN METHODS

bool Engine::isRunning() const { return this->_running; }
bool Engine::isRunning( bool b )
{
	this->_running = b;
	return this->_running;
}

// ================================ CORE METHODS

void Engine::init()
{
	log( "Engine::init()", INFO );
	InitWindow( SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE );
	SetTargetFPS( MAX_FPS );
}

void Engine::start()
{
	log( "Engine::start()", INFO );
	isRunning( true );
}
void Engine::stop()
{
	log( "Engine::stop()", INFO );
	isRunning( false );
}

void Engine::close()
{
	log( "Engine::close()", INFO );
	isRunning( false );
	CloseWindow();
}

// ================================ STEP METHODS

void Engine::launch()
{
	log( "Engine::launch()", INFO );

	if ( !isRunning() )
		start();

	//generateGeometry(); // NOTE : TEMP

	//DisableCursor();
	while( !WindowShouldClose() )
	{
		if ( !isRunning() )
			continue;

		inputs();
		update();
		render();
	}
	//EnableCursor();

	if ( isRunning() )
		stop();
}

void Engine::inputs()
{
	if ( IsKeyPressed( KEY_ESCAPE ) )
		stop();

	if ( IsKeyPressed( KEY_ENTER ) )
		log( "Enter key pressed", INFO );

	_player->update();
}

void Engine::update()
{

}

void Engine::render()
{
	BeginDrawing();
	{
		ClearBackground( BKGRND );

		_world->drawActivatedOrbiters();

		drawInfoBox( getCamera() ); // NOTE : TEMP
	}
	EndDrawing();
}