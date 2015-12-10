#pragma once
#include <vector>

class COrganism;

class CWorld
{
  private:
    std::vector<COrganism*> organisms;
  public:
    CWorld() = default;
    ~CWorld();

    void addOrganism( COrganism* organism );
    std::vector<COrganism*>& getOrganisms();
};
