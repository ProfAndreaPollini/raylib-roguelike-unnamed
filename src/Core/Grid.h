#pragma once

#include "IntVector2.h"

/**
 * @brief Represents a grid with specified dimensions and cell sizes.
 */
class Grid
{
public:
    /**
     * @brief Constructs a Grid object with the given parameters.
     *
     * @param width The width of the grid.
     * @param height The height of the grid.
     * @param cellWidth The width of each cell in the grid.
     * @param cellHeight The height of each cell in the grid.
     */
    Grid(int width, int height, int cellWidth, int cellHeight);

    IntVector2 center() const;

    /**
     * @brief Draws the grid.
     */
    void Draw() const;

private:
    int width;      /**< The width of the grid. */
    int height;     /**< The height of the grid. */
    int cellWidth;  /**< The width of each cell in the grid. */
    int cellHeight; /**< The height of each cell in the grid. */
};