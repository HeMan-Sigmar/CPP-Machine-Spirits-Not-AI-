#pragma once
#include <iostream>
#include "raylib.h"
#include "Agent.h"
#include <glm/glm.hpp>
#include <vector>


namespace AIForGames
{
    class Behaviour
    {
    public:
        virtual void Update(Agent* agent, float deltaTime) = 0;
    };
}