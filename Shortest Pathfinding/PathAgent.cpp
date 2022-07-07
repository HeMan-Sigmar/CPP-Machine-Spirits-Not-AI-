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
        m_path = NodeMap.dijkstrassearch(m_currentNode, node);
        m_currentIndex = 0;
    }
    void PathAgent::SetNode()
    {

    }
    void PathAgent::SetSpeed(int m_speed)
    {
       speed = m_speed;
    }
    void PathAgent::Update(float deltaTime)
    {
        if (m_path.empty()) 
        {
            return;
        }
        
        glm::vec2 direction = glm::normalize(m_path[m_currentIndex + 1]->position - m_position);
        float m_distance = glm::distance(m_position, m_path[m_currentIndex + 1]->position);


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