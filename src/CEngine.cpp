#include <CEngine.h>

CEngine::CEngine( int sWidth, int sHeight, const char* title )
{
	SDL_Init( SDL_INIT_EVERYTHING );

    // Create a window.
    window = SDL_CreateWindow( title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sWidth, sHeight, SDL_WINDOW_SHOWN );
    renderer = new CRenderer( window );
}

CEngine::~CEngine( void )
{

}

CRenderer* CEngine::getRenderer() {
    return renderer;
}
