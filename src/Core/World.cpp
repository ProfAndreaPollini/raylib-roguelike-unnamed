#include "World.h"

#include "Entity.h"
#include "Grid.h"

Entity *World::GetEntity(size_t id)
{
    return entities[id];
}

Entity *World::CreateEntity()
{
    auto [it, inserted] = entities.emplace(nextEntityId, new Entity());
    it->second->SetId(nextEntityId);
    nextEntityId++;
    return it->second;
}