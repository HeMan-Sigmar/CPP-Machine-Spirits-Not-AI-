#pragma once
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include "Agent.h"
#include "Behaviour.h"



namespace AIForGames 
{
    class GotoPointBehaviour : public Behaviour
    {
    public:
        virtual void Update(Agent* agent, float deltaTime);
    };
}