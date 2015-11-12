#include <CRenderer.h>

CRenderer::CRenderer( int _sWidth, int _sHeight ) {
    sWidth = _sWidth;
    sHeight = _sHeight;

	vSurface = NULL;
	vSurface = SDL_SetVideoMode( sWidth, sHeight, 32, SDL_SWSURFACE ); //Create display surface

	if (vSurface == NULL) {
		//std::cout << "Error: SDL failed to create display surface.";
		SDL_Quit();
	}
}

CRenderer::~CRenderer( void ) {
	
}

void CRenderer::update() {
	//Update Display
    SDL_Flip( vSurface );
}
