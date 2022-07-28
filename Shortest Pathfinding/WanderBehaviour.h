#pragma once
#include "Behaviour.h"
#include "PathFinder.h"
#include "Pathfinding.h"

using namespace AIForGames;

class WanderBehaviour : public Behaviour
{
public:
    virtual void Update(Agent* agent, float deltaTime);
    
};