
#include "raylib.h"

#include "Grid.h"
#include "IntVector2.h"

Grid::Grid(int width, int height, int cellWidth, int cellHeight)
    : width(width), height(height), cellWidth(cellWidth), cellHeight(cellHeight)
{
}

IntVector2 Grid::center() const
{
    auto w = width / cellWidth;
    auto h = height / cellHeight;

    return IntVector2{w / 2, h / 2};
}

void Grid::Draw() const
{
    for (int x = 0; x < width; x += cellWidth)
    {
        DrawLine(x, 0, x, height, LIGHTGRAY);
    }

    for (int y = 0; y < height; y += cellHeight)
    {
        DrawLine(0, y, width, y, LIGHTGRAY);
    }
}