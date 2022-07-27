#pragma once
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include "PathFinder.h"
#include <set>
#include <algorithm>
#include "PathAgent.h"
#include "Pathfinding.h"
#include "Agent.h"
#include "Pathfinding.h"
#include "Behaviour.h"


namespace AIForGames
{
    void Agent::Update(float deltaTime)
    {
        if (m_current)
            m_current->Update(this, deltaTime);
        m_pathAgent.Update(deltaTime);
    }

    void GoTo(glm::vec2 point)
    {
        Node* end = m_nodeMap.GetClosestNode(point);
        m_pathAgent->GoToNode(end);
    }
}