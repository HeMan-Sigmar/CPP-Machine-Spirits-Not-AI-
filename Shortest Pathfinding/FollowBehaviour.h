#pragma once
#include <iostream>
#include "raylib.h"
#include <glm/glm.hpp>
#include <vector>
#include "Behaviour.h"
using namespace AIForGames;

class FollowBehaviour : public Behaviour
{
private:
    glm::vec2 lastTargetPosition;
public:
    virtual void Update(Agent* agent, float deltaTime);
};