#pragma once
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include "PathFinder.h"
#include <set>
#include <algorithm>

namespace AIForGames
{
    class PathAgent
    {
    private:
        glm::vec2 m_position;

        std::vector<Node*> m_path;
        int m_currentIndex;
        Node* m_currentNode;

        float m_speed;
    
    public:
        void Update(float deltaTime);
        void GoToNode(Node* node);
        void Draw();
        void SetSpeed(int m_speed);
        void SetNode(Node* position);
        std::vector<Node*> dijkstrassearch(Node* m_currentNode, Node* node);
    };
}
