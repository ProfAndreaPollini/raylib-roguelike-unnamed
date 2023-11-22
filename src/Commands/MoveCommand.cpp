#include "MoveCommand.h"

#include "World.h"

void MoveCommand::Execute(World *world)
{
    auto e = world->GetEntity(entityId);
    if (e == nullptr)
        return;

    e->position += direction;
}