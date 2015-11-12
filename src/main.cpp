#include <SDL2/SDL.h>
#include "CEngine.h"
#include "CRenderer.h"
#include "CGame.h"

int main( int argc, char* args[] )
{
    CEngine* engine = new CEngine( 640, 480, "Evolution-Simulator" );
    CRenderer* renderer = engine->getRenderer();
    CGame* game = new CGame( engine );

    game->start();
    while ( game->running ) {
        game->update();
    }

    return 0;
}
