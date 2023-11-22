#pragma once

#include "raylib.h"
#include "IntVector2.h"

#include "MoveCommand.h"

#include <memory>

class Entity
{
public:
    Entity(int width = 16, int height = 16, float speed = 1.0f, Color color = RED)
        : width(width), height(height), speed(speed), timeToNextMove(speed), color(color)
    {
    }

    std::unique_ptr<Command> SetPosition(IntVector2);

    void Update(float dt);

    void Draw() const;

    size_t Id() const { return id; }

    void SetId(size_t newId) { id = newId; }

    IntVector2 Position() const { return position; }

private:
    IntVector2 position = IntVector2::ZERO;
    int width;
    int height;
    float speed;
    float timeToNextMove = 0.0f;
    Color color;
    size_t id;

    friend class MoveCommand;
};