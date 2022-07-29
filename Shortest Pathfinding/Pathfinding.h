#pragma once

#include "PathFinder.h"

namespace AIForGames
{
    class NodeMap
    {
    public:
        int m_width, m_height;
        int m_cellSize;

        Node** m_nodes;
        Node* GetNode(int x, int y) { return m_nodes[x + m_width * y]; }
        Node* GetRandomNode();
        void Initialise(std::vector<std::string> asciiMap, int cellSize);
        void Draw();
        static std::vector<Node*> DijkstraSearch(Node* startnode, Node* endnode);
        void DrawPath(std::vector<Node*> path, Color LineColor);        
        Node* GetClosestNode(glm::vec2 worldPos);

    };
}