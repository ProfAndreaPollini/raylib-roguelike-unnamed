#pragma once

class World;

struct Command
{
    virtual ~Command() = default;
    virtual void Execute(World *world) = 0;
};
