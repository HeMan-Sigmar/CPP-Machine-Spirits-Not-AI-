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
    void PathAgent::SetNode(Node* position)
    {
        m_currentNode->position;
        m_position = position;
    }
    void PathAgent::SetSpeed(int speed)
    {
       m_speed = speed;
    }
    void PathAgent::Update(float deltaTime)
    {
        if (m_path.empty()) 
        {
            return;
        }
        
        glm::vec2 direction = glm::normalize(m_path[m_currentIndex + 1]->position - m_position);
        float m_distance = glm::distance(m_position, m_path[m_currentIndex + 1]->position);
        direction - m_speed * deltaTime;

        if (m_distance > 0)
        {
            m_speed* deltaTime* ;
        }
        else
        {
            m_currentIndex + 1;
            /*if(we’ve reached the end of our path)
            {
            snap to the final node and empty the path so future updates do nothing.
            }*/
        }
        //if (we have a next node)
        //{
        //    then distance with the subtracted speed* deltaTime tells us how far we’ve overshot the node if we invert it.Find the unit vector from our previous node to the new next node, and move along this vector by the overshoot distance from the previous next node.

        //}
    }

    void PathAgent::Draw()
    {
        DrawCircle((int)m_position.x, (int)m_position.y, 8, { 255,255,0,255 });
    }
}