#include "Agent.h"

#include "FollowBehaviour.h"
 
void FollowBehaviour::Update(Agent* agent, float deltaTime)
    {
        // check if the agent has moved significantly from its last position
        // if so we want to repath towards it
        Agent* target = agent->GetTarget();

        float dist = glm::distance(target->GetPosition(), lastTargetPosition);
        if (dist > agent->GetNodeMap()->GetCellSize())
        {
            lastTargetPosition = target->GetPosition();
            agent->GoTo(lastTargetPosition);
        }
    }

float Vector2Distance(glm::vec2 position1, glm::vec2 position2)
{
    //calculate distance
}