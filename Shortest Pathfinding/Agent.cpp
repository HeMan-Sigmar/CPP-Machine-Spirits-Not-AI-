#pragma once
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include "PathFinder.h"
#include <set>
#include <algorithm>
#include "Agent.h"
#include "Behaviour.h"


namespace AIForGames
{
    void Agent::Update(float deltaTime)
    {
        if (m_current)
            m_current->Update(this, deltaTime);
        m_pathAgent.Update(deltaTime);
    }

    void Agent::GoTo(glm::vec2 point)
    {
        Node* end = m_nodeMap->GetClosestNode(point);
        m_pathAgent.GoToNode(end);
    }
    bool Agent::PathComplete()
    {
        return m_pathAgent.GetPath().empty();
    }
    void SetTarget()
    {

    }

    void Reset()
    {

    }
}