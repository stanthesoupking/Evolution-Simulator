#include <CRenderer.h>

#include "COrganism.h"
#include <SDL2/SDL.h>

CRenderer::CRenderer( SDL_Window* _window ):
    grass_color (32, 160, 32),
    window (_window)
{
    MARKER_SIZE = 16.0f;

	renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "SDL failed to create renderer.", nullptr);
		SDL_Quit();
	}

}

CRenderer::~CRenderer() {
	delete renderer;
}

void CRenderer::clear() {
	//Clear Renderer
    setRenderColor(grass_color);
    SDL_RenderClear(renderer);
}

void CRenderer::present() {
    //Present Renderer
    SDL_RenderPresent(renderer);
}

void CRenderer::setRenderColor( CColor color ) {
    SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, 0xFF );
}

void CRenderer::renderOrganism( COrganism* organism, CVector3 cameraPos ) {
    //Render organism relative to the camera's position
    CVector3 onScreenPosition = organism->position;
    onScreenPosition.displace( cameraPos );
        
    SDL_Rect fillRect = { (int) (onScreenPosition.x-MARKER_SIZE/2.0f), (int) (onScreenPosition.y-MARKER_SIZE/2.0f),
                          (int)MARKER_SIZE, (int)MARKER_SIZE };

    CColor const &color = organism->getColor();    
    setRenderColor( color ); 
       
    SDL_RenderFillRect( renderer, &fillRect );
}
