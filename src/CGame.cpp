#include "CRenderer.h"

#include "CGame.h"
#include "CEngine.h"
#include "CWorld.h"
#include "COrganism.h"
#include "base_stimuli.h"

CGame::CGame( CEngine* _engine ):
    engine(_engine),
    renderer(_engine->getRenderer())
{

    world = new CWorld();

    testOrganism = new COrganism( CVector3(128,128,0), CColor(255,0,0) );
    CStimulus* testStimulus = new SEnergyInRange();
    testOrganism->addStimulus( testStimulus );
    world->addOrganism( testOrganism );
    
    cameraPos = CVector3(0,0,0);

    running = false;

    pTime = SDL_GetTicks(); //TODO: Make this non-SDL dependant
}

CGame::~CGame() {
    delete world; 
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

    std::vector<COrganism*>& organisms = world->getOrganisms();
    
    long cTime = SDL_GetTicks(); //TODO: Make this non SDL-dependant

    double deltaTime = (pTime - cTime) / 1000.0; //Delta Time in Seconds
    pTime = cTime;

    //Do rendering
	for (COrganism* organism: organisms)
	{
        organism->update(deltaTime, world);
        renderer->renderOrganism(organism, cameraPos);
	}

    renderer->present();
}
