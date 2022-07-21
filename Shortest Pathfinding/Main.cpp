#pragma once
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>

#include "PathFinder.h"
#include "Pathfinding.h"
#include "PathAgent.h"


using namespace AIForGames;

int main()

{
    InitWindow(800, 450, "raylib [core] example - basic window");

    std::vector<std::string> asciiMap;
    asciiMap.push_back("000000000000");
    asciiMap.push_back("010111011100");
    asciiMap.push_back("010101110110");
    asciiMap.push_back("010100000000");
    asciiMap.push_back("010111111110");
    asciiMap.push_back("010000000000");
    asciiMap.push_back("011111111110");
    asciiMap.push_back("000000000000");

    NodeMap memes;
    memes.Initialise(asciiMap, 32);

    Node* start = memes.GetNode(1, 1);
    Node* end = memes.GetNode(10, 2);
    std::vector<Node*> nodeMapPath = NodeMap::DijkstraSearch(start, end);
    Color lineColor = { 255, 255, 255, 255 };

    PathAgent agent;
    agent.SetNode(start);
    agent.SetSpeed(1);
    float time = (float)GetTime();
    float deltaTime;
    while (!WindowShouldClose())
    {
        float fTime = (float)GetTime();
        deltaTime = fTime - time;
        time = fTime;
        BeginDrawing();
        ClearBackground(BLACK);
        
        if (IsMouseButtonPressed(0))
        {
            Vector2 mousePos = GetMousePosition();
            start = memes.GetClosestNode(glm::vec2(mousePos.x, mousePos.y));
            nodeMapPath = NodeMap::DijkstraSearch(start, end);
            agent.GoToNode(end);
        }
        if (IsMouseButtonPressed(1))
        {
            Vector2 mousePos = GetMousePosition();
            end = memes.GetClosestNode(glm::vec2(mousePos.x, mousePos.y));
            nodeMapPath = NodeMap::DijkstraSearch(start, end);
            agent.GoToNode(end);
        }

        agent.Update(deltaTime);
        agent.Draw();
        memes.Draw();
        //DrawPath(agent.path, lineColor);
       memes.DrawPath(nodeMapPath, lineColor);
        EndDrawing();
    }


    CloseWindow();

    return 0;
}



    