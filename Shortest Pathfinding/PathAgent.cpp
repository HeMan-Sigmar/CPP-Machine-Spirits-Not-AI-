#pragma once
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include "PathFinder.h"
#include <set>
#include <algorithm>
#include "PathAgent.h"




namespace AIForGames 
{

    void PathAgent::GoToNode(Node* node)
    {
        m_path = dijkstrassearch(m_currentNode, node);
        m_currentIndex = 0;
    }

    void PathAgent::Update(float deltaTime)
    {
        if (m_path.empty()) 
        {
            return;
        }
        float m_distance;
        glm::vec2 direction = glm::normalize(m_path[m_currentIndex + 1]->position - m_position);
        m_distance = glm::distance(m_path[m_currentIndex + 1]->position + m_position);

        if (m_distance > 0)
        {

        }
        else
        {

        }
    }

    void PathAgent::Draw()
    {
        DrawCircle((int)m_position.x, (int)m_position.y, 8, { 255,255,0,255 });
    }
}