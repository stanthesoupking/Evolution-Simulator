#include <CRenderer.h>

CRenderer::CRenderer( SDL_Window* _window ) {
    window = _window;

	renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "SDL failed to create renderer.", NULL);
		SDL_Quit();
	}
}

CRenderer::~CRenderer( void ) {
	
}

void CRenderer::clear() {
	//Update Renderer
    SDL_RenderClear(renderer);
}

void CRenderer::present() {
    //Present Renderer
    SDL_RenderPresent(renderer);
}
