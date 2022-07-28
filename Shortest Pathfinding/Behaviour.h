#pragma once
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>


namespace AIForGames
{
    class Agent;
    class Behaviour
    {
    public:
        virtual void Update(Agent* agent, float deltaTime) = 0;
    };
}