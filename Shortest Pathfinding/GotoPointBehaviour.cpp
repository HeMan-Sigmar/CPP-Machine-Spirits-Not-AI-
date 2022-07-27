#pragma once
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include "Behaviour.h"
#include "PathAgent.h"
#include "Agent.h"
#include "GotoPointBehaviour.h" 


namespace AIEForGames 
{
    void GotoPointBehaviour::Update(Agent* agent, float deltaTime)
    {
        // read mouseclicks, left for start node, end for right node
        if (IsMouseButtonPressed(0))
        {
            Vector2 mousePos = GetMousePosition();
            agent->GoTo(glm::vec2(mousePos.x, mousePos.y));
        }
    }

}