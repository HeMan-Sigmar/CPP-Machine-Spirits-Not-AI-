#pragma once
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include "Agent.h"
#include "PathFinder.h"
#include "Pathfinding.h"
#include "PathAgent.h"
#include "GotoPointBehaviour.h"
#include "WanderBehaviour.h"


using namespace AIForGames;

int main()

{
    InitWindow(800, 450, "raylib [core] example - basic window");

    std::vector<std::string> asciiMap;
    asciiMap.push_back("000000000000");
    asciiMap.push_back("011111111110");
    asciiMap.push_back("011111111110");
    asciiMap.push_back("011011000000");
    asciiMap.push_back("011011011110");
    asciiMap.push_back("011011011110");
    asciiMap.push_back("011111111110");
    asciiMap.push_back("000000000000");

    NodeMap memes;
    memes.Initialise(asciiMap, 32);

    Node* start = memes.GetNode(1, 1);
    Node* end = memes.GetNode(10, 2);
    std::vector<Node*> nodeMapPath = NodeMap::DijkstraSearch(start, end);
    Color lineColor = { 255, 255, 255, 255 };

    PathAgent agent(&memes, new GotoPointBehaviour());
    agent.SetNode(start);
    agent.SetSpeed(4);
    Agent agent2(&memes, new WanderBehaviour());
    agent2.SetNode(memes.GetRandomNode());

    float deltaTime;
    while (!WindowShouldClose())
    {

        deltaTime = GetFrameTime();

        BeginDrawing();
        ClearBackground(BLACK);
        
        if (IsMouseButtonPressed(1))
        {
            Vector2 mousePos = GetMousePosition();
            start = memes.GetClosestNode(glm::vec2(mousePos.x, mousePos.y));
            nodeMapPath = NodeMap::DijkstraSearch(start, end);
            agent.GoToNode(end);
        }
        if (IsMouseButtonPressed(0))
        {
            Vector2 mousePos = GetMousePosition();
            end = memes.GetClosestNode(glm::vec2(mousePos.x, mousePos.y));
            nodeMapPath = NodeMap::DijkstraSearch(start, end);
            agent.GoToNode(end);
        }

        agent.Update(deltaTime);
        agent.Draw();
        memes.Draw();
        memes.DrawPath(agent.m_path, RED);
       //memes.DrawPath(nodeMapPath, lineColor);
        EndDrawing();
    }


    CloseWindow();

    return 0;
}



    