#pragma once
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include "PathFinder.h"
#include "Pathfinding.cpp"


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
    asciiMap.push_back("010000001000");
    asciiMap.push_back("011111111110");
    asciiMap.push_back("000000000000");

    NodeMap memes;
    memes.Initialise(asciiMap, 32);

    Node* start = memes.GetNode(1, 1);
    Node* end = memes.GetNode(10, 2);
    std::vector<Node*> nodeMapPath = memes.dijkstrassearch(start, end);
    Color lineColor = { 255, 255, 255, 255 };

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        memes.Draw();
        memes.DrawPath(nodeMapPath, lineColor);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}



    