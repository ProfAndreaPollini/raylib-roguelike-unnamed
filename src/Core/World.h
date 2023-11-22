#pragma once

#include "Entity.h"
#include "IntVector2.h"

#include <map>
#include <vector>

class Grid;

class World
{
public:
    explicit World(Grid *grid) : grid(grid)
    {
    }

    Entity *CreateEntity();

    template <typename T>
    void Execute(T *cmd)
    {
        if (cmd == nullptr)
            return;
        cmd->Execute(this);
    }

    Entity *GetEntity(size_t id);

private:
    Grid *grid;
    std::map<IntVector2, std::vector<size_t>> entityMap;
    std::map<int, Entity *> entities;
    int nextEntityId = 0;
};