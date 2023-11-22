

#include "Entity.h"
#include "Commands/MoveCommand.h"

std::unique_ptr<Command> Entity::SetPosition(IntVector2 newPosition)
{

    return std::make_unique<MoveCommand>(id, newPosition);
}

void Entity::Update(float dt)
{
    if (timeToNextMove > 0.0)
    {
        timeToNextMove -= dt;
        return;
    }
    if (IsKeyDown(KEY_LEFT))
    {
        position.x -= 1;
        timeToNextMove = speed;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        position.x += 1;
        timeToNextMove = speed;
    }
    if (IsKeyDown(KEY_UP))
    {
        position.y -= 1;
        timeToNextMove = speed;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        position.y += 1;
        timeToNextMove = speed;
    }
}

void Entity::Draw() const
{
    DrawRectangle(position.x * width, position.y * height, width, height, color);
}