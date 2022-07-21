#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include "PathFinder.h"
#include "Pathfinding.h"
#include <set>
#include <algorithm>


namespace AIForGames
{
    void NodeMap::Initialise(std::vector<std::string> asciiMap, int cellSize)

    {
        m_cellSize = cellSize;
        const char emptySquare = '0';

        // assume all strings are the same length, so we'll size the map according
        // to the number of strings and the length of the first one
        m_height = asciiMap.size();
        m_width = asciiMap[0].size();

        m_nodes = new Node * [m_width * m_height];

        // loop over the strings, creating Node entries as we go
        for (int y = 0; y < m_height; y++)
        {
            std::string& line = asciiMap[y];
            // report to the use that you have a mis-matched string length
            if (line.size() != m_width)
                std::cout << "Mismatched line #" << y << " in ASCII map (" << line.size() << " instead of " << m_width << ")" << std::endl;

            for (int x = 0; x < m_width; x++)
            {
                // get the x-th character, or return an empty node if the string         
                // isn't long enough
                char tile = x < line.size() ? line[x] : emptySquare;

                // create a node for anything but a '.' character
                m_nodes[x + m_width * y] = tile == emptySquare ? nullptr : new Node(x, y);
            }
        }
        // now loop over the nodes, creating connections between each node and its      
// neighbour to the West and South on the grid. this will link up all nodes
        for (int y = 0; y < m_height; y++)
        {
            for (int x = 0; x < m_width; x++)
            {
                Node* node = GetNode(x, y);
                if (node)
                {
                    // see if there's a node to our west, checking for array overruns      
                    // first if we're on the west-most edge
                    Node* nodeWest = x == 0 ? nullptr : GetNode(x - 1, y);
                    if (nodeWest)
                    {
                        node->ConnectTo(nodeWest, 1); // TODO weights
                        nodeWest->ConnectTo(node, 1);
                    }

                    // see if there's a node south of us, checking for array index
                    // overruns again
                    Node* nodeSouth = y == 0 ? nullptr : GetNode(x, y - 1);
                    if (nodeSouth)
                    {
                        node->ConnectTo(nodeSouth, 1);
                        nodeSouth->ConnectTo(node, 1);
                    }
                }
            }
        }
    }
    void NodeMap::Draw()
    {
        // red color for the blocks
        Color cellColor = RED;
        Color lineColor = GREEN;

        for (int y = 0; y < m_height; y++)
        {
            for (int x = 0; x < m_width; x++)
            {
                Node* node = GetNode(x, y);
                if (node == nullptr)
                {
                    // draw a solid block in empty squares without a navigation node
                    DrawRectangle((int)(x * m_cellSize), (int)(y * m_cellSize),
                        (int)m_cellSize - 1, (int)m_cellSize - 1, cellColor);
                }
                else
                {
                    // draw the connections between the node and its neighbours
                    for (int i = 0; i < node->connections.size(); i++)
                    {

                        Node* other = node->connections[i].target;
                        DrawLine((x + 0.5f) * m_cellSize, (y + 0.5f) * m_cellSize,
                            (other->position.x + 0.5f) * m_cellSize,
                            (other->position.y + 0.5f) * m_cellSize,
                            lineColor);
                    }
                }
            }
        }
    }

    std::vector<Node*> NodeMap::DijkstraSearch(Node* startnode, Node* endnode)
    {
        // validate the input
        if (startnode == nullptr || endnode == nullptr)
        {
            throw std::runtime_error("Both start and end  must be Specified!!!");
        }
        // initialise the starting node
        startnode->gScore = 0;
        startnode->previous = nullptr;

        // create our temporary lists for storing nodes we’re visiting/visited
        std::vector<Node*>openlist;
        std::set<Node*>closedlist;


        openlist.push_back(startnode);

        while (!openlist.empty())
        {

            std::sort(openlist.begin(), openlist.end(), [](Node* n1, Node* n2)
                {
                    return n1->gScore < n2->gScore;
                });
            Node* currentNode = openlist.back();
            if (currentNode == endnode)
            {
                break;
            }
            openlist.pop_back();
            closedlist.insert(currentNode);

            for (Edge& c : currentNode->connections)
            {
                if (closedlist.count(c.target) == 0)
                {
                    float gScore = currentNode->gScore + c.cost;

                    // have not yet visited the node.
                    // so calculate the score and update its parent.
                    // also add it to the openlist for processing.
                    if (std::find(openlist.begin(), openlist.end(), c.target) == openlist.end())
                    {
                        c.target->gScore = gScore;
                        c.target->previous = currentNode;
                        openlist.push_back(c.target);
                    }
                    // node is already in the openlist with a valid score.
                    // so compare the calculated score with the existing
                    // to find the shorter path.
                    else if (gScore < c.target->gScore)
                    {
                        c.target->gScore = gScore;
                        c.target->previous = currentNode;
                    }
                }
            }
        }

        // create path in reverse from endnode to startnode
        std::vector<Node*>path;
        Node* currentNode = endnode;

        while (currentNode != nullptr)
        {
            path.push_back(currentNode);
            currentNode = currentNode->previous;
        }
        std::reverse(path.begin(), path.end());
        // return the path for navigation between startnode/endnode
        return path; //tempory list 

    }
    void NodeMap::DrawPath(std::vector<Node*> path, Color LineColor)
    {
        for (int i = 1; i < path.size(); i++)
        {
            float p1 = (path[i - 1]->position.x + 0.5f) * m_cellSize;
            float p2 = (path[i - 1]->position.y + 0.5f) * m_cellSize;
            float p3 = (path[i]->position.x + 0.5f) * m_cellSize;
            float p4 = (path[i]->position.y + 0.5f) * m_cellSize;
            DrawLine(p1, p2, p3, p4, LineColor);

            if (i == 1)
            {
                DrawCircle(p1, p2, 4, WHITE);
            }
            if (i == path.size() - 1)
            {
                DrawCircle(p1, p2, 4, WHITE);
            }
        }
    }
    Node* NodeMap::GetClosestNode(glm::vec2 worldPos)
    {
        int i = (int)(worldPos.x / m_cellSize);
        if (i < 0 || i >= m_width)
        {
            return nullptr;
        }
        int j = (int)(worldPos.y / m_cellSize);
        if (j < 0 || j >= m_width)
        {
            return nullptr;
        }
        return GetNode(i, j);
    }

}