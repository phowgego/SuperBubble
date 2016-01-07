#include "transforms.h"

void gridSpaceToPlaySpace(const glm::ivec2 gridPosition, glm::ivec2 &playPosition)
{
    playPosition.x = gridPosition.x * GRID_SIZE;
    playPosition.y = gridPosition.y * GRID_SIZE;
}

void playSpaceToGridSpace(const glm::ivec2 playPosition, glm::ivec2 &gridPosition)
{    
    gridPosition.x = playPosition.x / GRID_SIZE;
    gridPosition.y = playPosition.y / GRID_SIZE;
}

void windowSpaceToPlaySpace(const glm::vec2 windowPosition, glm::ivec2 &playPosition)
{
    playPosition.x = static_cast<int16_t>(windowPosition.x - PLAY_SPACE_POS.x);
    playPosition.y = static_cast<int16_t>(windowPosition.y - PLAY_SPACE_POS.y);
}

void playSpaceToWindowSpace(const glm::ivec2 playPosition, glm::vec2 &windowPosition)
{
    windowPosition.x = static_cast<float>(playPosition.x) + PLAY_SPACE_POS.x;
    windowPosition.y = static_cast<float>(playPosition.y) + PLAY_SPACE_POS.y;
}

// Find the squares in grid space that overlap a square in play space that is of the same play sapce size as a grid space square.
// gridPosition0 and gridPosition1 are updated depending on number of matches.
// Return: number of matches (as it can overlap 1 or 2 squares).
uint8_t playSpaceToNearestVerticalGrid(const glm::ivec2 playPosition, glm::ivec2 &gridPosition0, glm::ivec2 &gridPosition1)
{
    int8_t x = playPosition.x / GRID_SIZE;
    int8_t y = playPosition.y / GRID_SIZE;

    if (playPosition.x % GRID_SIZE == 0)
    {
        gridPosition0.x = x;
    }
    else
    {
        return 0;
    }

    if (playPosition.y % GRID_SIZE == 0)
    {
        gridPosition0.y = y;
        return 1;
    }
    else
    {
        gridPosition1.x = x;
        gridPosition0.y = y;
        if (playPosition.y < 0)
        {
            gridPosition1.y = y - 1;
        }
        else
        {
            gridPosition1.y = y + 1;
        }
        return 2;
    }
}