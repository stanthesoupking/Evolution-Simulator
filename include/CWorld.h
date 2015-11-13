#pragma once
#include <vector>
#include "COrganism.h"

class CWorld
{
  private:
    std::vector<COrganism*>* organisms;
  public:
    CWorld();
    ~CWorld();

    void addOrganism( COrganism* organism );
    std::vector<COrganism*>* getOrganisms();
};
