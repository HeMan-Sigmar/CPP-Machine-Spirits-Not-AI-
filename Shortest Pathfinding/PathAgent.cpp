#pragma once
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include "PathFinder.h"
#include <set>
#include <algorithm>
#include "PathAgent.h"
#include "Agent.h"
#include "Pathfinding.h"




namespace AIForGames 
{

    void PathAgent::GoToNode(Node* node)
    {
        m_path = NodeMap::DijkstraSearch(m_currentNode, node);
        m_currentIndex = 0;
    }
    void PathAgent::SetNode(Node* node)
    {
        m_currentNode = node;
        m_position = node->position;
    }
    void PathAgent::SetSpeed(float speed)
    {
       m_speed = speed;
    }
    std::vector<Node*> PathAgent::GetPath()
    {
        return m_path;
    }
    void PathAgent::Update(float deltaTime)
    {
        //int i = 1;
        //int j = 0;
        //j += i;

        //glm::vec2 direction(1, 0);
        //m_position += direction * deltaTime * m_speed;

        if (m_path.empty()) 
        {
            return;
        }
        
        glm::vec2 direction = glm::normalize(m_position - m_path[m_currentIndex + 1]->position);
        float distance = glm::distance(m_position, m_path[m_currentIndex + 1]->position);
        //direction /= distance;

        float distancethisframe = distance - (m_speed * deltaTime);

        if (distancethisframe > 0)
        {
            m_position -= direction * deltaTime * m_speed; // multiply by speed
        }
        else
        {
            m_currentIndex++;
            m_currentNode = m_path[m_currentIndex];
            if(m_currentIndex == m_path.size() - 1)
            {
                m_position = m_currentNode->position;
                m_path.clear();
            }
            else
            {
              
              float distance = glm::distance(m_position, m_path[m_currentIndex + 1]->position - m_currentNode->position);
              direction = glm::normalize(direction);
              m_position += -distancethisframe * direction;
            }
        }

    }

    void PathAgent::Draw()
    {
        DrawCircle((int)((m_position.x + 0.5f) * 32), (int)((m_position.y + 0.5f) * 32), 8, { 255,255,0,255 });
    }



}