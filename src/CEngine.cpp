#include <CEngine.h>

CEngine::CEngine( int _sWidth, int _sHeight )
{
	SDL_Init( SDL_INIT_EVERYTHING );
    renderer = new CRenderer( _sWidth, _sHeight );
}

CEngine::~CEngine( void )
{

}

CRenderer* CEngine::getRenderer() {
    return renderer;
}
