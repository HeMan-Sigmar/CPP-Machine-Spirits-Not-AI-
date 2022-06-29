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

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        memes.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}



    