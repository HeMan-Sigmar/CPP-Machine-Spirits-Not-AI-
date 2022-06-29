#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include "PathFinder.h"


namespace AIForGames 
{

    class NodeMap
    {
        int m_width, m_height;
        int m_cellSize;

        Node** m_nodes;
        Node* GetNode(int x, int y) { return m_nodes[x + m_width * y]; }
    };
}