#pragma once;
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
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
        
        void Initialise(std::vector<std::string> asciiMap, int cellSize)

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
        void Draw()
        {
            // red color for the blocks
            Color cellColor = RED;
            Color lineColor = RAYWHITE;

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
        std::vector<node*> dijkstrassearch(node* startnode, node* endnode);

        void dijkstrassearch(node* startnode, node* endnode)
        {
            // validate the input
            if (startnode  == nullptr || endnode == nullptr)
                throw run_time

                if startnode == endnode
                    return empty path

                    // initialise the starting node
                    set startnode.gscore to 0
                    set startnode.parent to null

                    // create our temporary lists for storing nodes we’re visiting/visited
                    let openlist be a list of nodes
                    let closedlist be a list of nodes

                    add startnode to openlist

                    while openlist is not empty
                    sort openlist by node.gscore

                    let currentnode = first item in openlist

                    // if we visit the endnode, then we can exit early.
                    // sorting the openlist above guarantees the shortest path is found,
                    // given no negative costs (a prerequisite of the algorithm).
                    // this is an optional optimisation that improves performance,
                    // but doesn’t always guarantee the shortest path.
                    if currentnode is endnode
                    exit while loop

                    remove currentnode from openlist
                    add currentnode to closedlist

                    for all connections c in currentnode
                    if c.target not in closedlist
                    let gscore = currentnode.gscore + c.cost

                    // have not yet visited the node.
                    // so calculate the score and update its parent.
                    // also add it to the openlist for processing.
                    if c.target not in openlist
                    let c.target.gscore = gscore
                    let c.target.parent = currentnode
                    add c.target to openlist

                    // node is already in the openlist with a valid score.
                    // so compare the calculated score with the existing
                    // to find the shorter path.
                    else if (gscore < c.target.gscore)
                    let c.target.gscore = gscore
                    let c.target.parent = currentnode

                    // create path in reverse from endnode to startnode
                    let path be a list of nodes
                    let currentnode = endnode

                    while currentnode is not null
                    add currentnode to beginning of path
                    let currentnode = currentnode.parent

                    // return the path for navigation between startnode/endnode
                    return path //tempory list 
        }
    };
}