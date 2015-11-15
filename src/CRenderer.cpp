#include <CRenderer.h>

CRenderer::CRenderer( SDL_Window* _window ) {
    MARKER_SIZE = 16.0f;

    window = _window;

	renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "SDL failed to create renderer.", NULL);
		SDL_Quit();
	}

    grass_color = new CColor( 32,160,32 );
}

CRenderer::~CRenderer( void ) {
	
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

void CRenderer::setRenderColor( CColor* color ) {
    SDL_SetRenderDrawColor( renderer, color->r, color->g, color->b, 0xFF );
}

void CRenderer::renderOrganism( COrganism* organism, CVector3 cameraPos ) {
    //Render organism relative to the camera's position
    CVector3 onScreenPosition = organism->position;
    onScreenPosition.displace( cameraPos );
        
    SDL_Rect fillRect = { (int) (onScreenPosition.x-MARKER_SIZE/2.0f), (int) (onScreenPosition.y-MARKER_SIZE/2.0f),
                          (int)MARKER_SIZE, (int)MARKER_SIZE };

    CColor* color = organism->getColor();    
    setRenderColor( color ); 
       
    SDL_RenderFillRect( renderer, &fillRect );
}
