#include "CGame.h"

CGame::CGame( CEngine* _engine ) {
    engine = _engine;
    renderer = engine->getRenderer();
    running = new bool;
    running = false;
}

CGame::~CGame() {
    
}

void CGame::start() {
    running = true;
}

void CGame::doEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) { 
        switch(event.type) {
            case SDL_QUIT:
                running = false;
        }
    }
}

void CGame::update() {
    doEvents();

    renderer->clear();

    //Do rendering

    renderer->present();
}
