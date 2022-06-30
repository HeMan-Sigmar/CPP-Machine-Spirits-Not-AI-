#pragma once

#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>


namespace AIForGames
{

    struct Node;

    struct Edge {
        Node* target;
        float cost;
        Edge() { target = nullptr; cost = 0; }
        Edge(Node* _node, float _cost) : target(_node), cost(_cost) {}
    };

    struct Node {

        Node(float x, float y)
        {
            position.x = x;
            position.y = y;
        }
        glm::vec2 position;
        std::vector<Edge> connections;

        float gScore;
        Node* previous;

        void ConnectTo(Node* other, float cost)
        {
            connections.push_back(Edge(other, cost));
        }
        std::vector<Node*> dijkstrassearch(Node* startnode, Node* endnode);

    };

}