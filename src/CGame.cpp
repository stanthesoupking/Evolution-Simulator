#include "CRenderer.h"

#include "CGame.h"
#include "CEngine.h"
#include "CWorld.h"
#include "COrganism.h"
#include "CMutator.h"
#include "base_behaviours.h"

CGame::CGame( CEngine* _engine ):
    engine(_engine),
    renderer(_engine->getRenderer())
{

    world = new CWorld();

    COrganism* testOrganism = CMutator::newRockCreature( CVector3(128,128,0), CColor(255,0,0) );
    CMutator::ReplaceBehaviour(testOrganism, 0, new Behaviour::WalkSouthEast());
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

    //get everything to think without moving, so that there is no first-strike advantage
    for (COrganism* organism: organisms)
        organism->brain.think(deltaTime, organism, world);
    
    //Do rendering
	for (COrganism* organism: organisms)
	{
        organism->act(deltaTime, world);
        renderer->renderOrganism(organism, cameraPos);
	}

    renderer->present();
}
