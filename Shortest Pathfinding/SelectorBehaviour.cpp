#pragma once
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include "Agent.h"
#include "Behaviour.h"
#include "SelectorBehaviour.h"
using namespace AIForGames;


void SelectorBehaviour::SetBehaviour(Behaviour* b, Agent* agent)
{
    if (m_selected != b)
    {
        m_selected = b;
        agent->Reset();
    }
}
void SelectorBehaviour::Update(Agent* agent, float deltaTime)
{
    if (Vector2Distance(agent->GetPosition(), agent->GetTarget()->GetPosition()) < agent->GetNodeMap()->GetCellSize() * 5)
    {
        SetBehaviour(m_b1, agent);
        agent->SetColor({ 255, 0, 0, 255 }); //red
        
    }
    else
    {
        SetBehaviour(m_b2, agent);
        agent->SetColor({ 0, 255, 255, 255 }); // cyan
    }
    m_selected->Update(agent, deltaTime);
}

float Vector2Distance(glm::vec2 position1, glm::vec2 position2)
{
    //calculate distance
}