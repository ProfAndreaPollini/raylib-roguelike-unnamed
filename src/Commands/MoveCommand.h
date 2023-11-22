#pragma once

#include "Command.h"
#include "IntVector2.h"

class World;

struct MoveCommand : public Command
{
    MoveCommand(size_t entityId, IntVector2 direction) : entityId(entityId), direction(direction) {}

    ~MoveCommand() override = default;

    void Execute(World *world) override;

    size_t entityId;
    IntVector2 direction;
};