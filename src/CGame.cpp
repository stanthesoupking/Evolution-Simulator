#include "CGame.h"

CGame::CGame( CEngine* _engine ) {
    engine = _engine;
    renderer = engine->getRenderer();
    
    testOrganism = new COrganism( CVector3(128,128,0), new CColor(255,0,0) );

    world = new CWorld();
    world->addOrganism( testOrganism );
    
    cameraPos = CVector3(0,0,0);

    running = false;

    pTime = SDL_GetTicks();
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

    std::vector<COrganism*>* organisms = world->getOrganisms();
    
    long cTime = SDL_GetTicks();

    double deltaTime = (pTime - cTime) / 1000.0; //Delta Time in Milliseconds
    pTime = cTime;

    //Do rendering
    for(int i = 0; i < organisms->size(); i++) {
        COrganism* organism = organisms->at(i);
        organism->update(deltaTime);
        renderer->renderOrganism(organism, cameraPos);
    }

    renderer->present();
}
