#pragma once
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include "Behaviour.h"
#include "Agent.h"




namespace AIEForGames 
{
    class GotoPointBehaviour : public Behaviour
    {
    public:
        virtual void Update(Agent* agent, float deltaTime);
    };
}