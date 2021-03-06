#pragma once
#include <iostream>
#include "raylib.h"
#include <vector>
#include "PathAgent.h"
#include "Pathfinding.h"



namespace AIForGames
{
    class Behaviour;

    class Agent
    {
        
        
    public:
        Agent() {}
        Agent(NodeMap* _nodeMap, Behaviour* _behaviour) : m_current(_behaviour), m_nodeMap(_nodeMap), m_color({ 255, 255, 0, 255 }) {}
        ~Agent() { delete m_current; }
        
        void Update(float deltaTime);
        void Draw();
        void GoTo(glm::vec2 point);
        bool PathComplete();
        void SetNode(Node* position);
        Agent* GetTarget();
        Agent* SetTarget();
        void SetSpeed(int speed) { m_speed = speed; }
        void SetColor(Color color) { m_color = color; }
        glm::vec2 GetPosition() { return m_pathAgent.GetPosition(); }
        void Reset();
        Agent* GetNodeMap();
        Agent* GetCellSize();
        void GoToNode(Node* node);
    private:
        PathAgent m_pathAgent;
        Behaviour* m_current;
        NodeMap* m_nodeMap;
        Color m_color;
        float m_speed;

    };
    

}