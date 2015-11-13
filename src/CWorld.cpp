#include "CWorld.h"

CWorld::CWorld() {
    organisms = new std::vector<COrganism*>();
}

CWorld::~CWorld() {
    delete organisms;
}

void CWorld::addOrganism( COrganism* organism ) {
    organisms->push_back(organism);
}

std::vector<COrganism*>* CWorld::getOrganisms() {
    return organisms;
}
