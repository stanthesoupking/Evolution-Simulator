#include "CWorld.h"
#include "COrganism.h"

// I am become death, destructor of worlds
CWorld::~CWorld() {
	//C++11 iterator-based for loop
    for (COrganism *each: organisms)
		delete each;
}

void CWorld::addOrganism( COrganism* organism ) {
    organisms.push_back(organism);
}
