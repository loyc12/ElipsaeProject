#include "../inc/core.hpp"

int main()
{
	start_clock();

	Engine *engine = getEngine();

	engine->setNoiseSeed( 69420 );
	engine->getWorld()->initiateOrbiters();
	engine->launch();

	delete engine;

	log( "Exiting main()", INFO );

	return 0;
}