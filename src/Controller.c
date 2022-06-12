#include "Constants.h"

color boardSlotsMatrix[][BOARD_COLUMN_COUNT] = {
    {NONE, NONE, NONE, NONE, NONE, NONE, NONE},
    {NONE, NONE, NONE, NONE, NONE, NONE, NONE},
    {NONE, NONE, NONE, NONE, NONE, NONE, NONE},
    {NONE, NONE, NONE, NONE, NONE, NONE, NONE},
    {NONE, NONE, NONE, NONE, NONE, NONE, NONE},
    {NONE, NONE, NONE, NONE, NONE, NONE, NONE},
}; // initializing board slots with No color

int unfilledTop[BOARD_COLUMN_COUNT] = {}; // holds the lowest empty slot row number of a column

bool isSlotFilled(int column, color fillColor) // update board slots matrix
{
    if (unfilledTop[column] == BOARD_ROW_COUNT) // if board column is filled
        return false;

    boardSlotsMatrix[unfilledTop[column]][column] = fillColor;
    unfilledTop[column]++;

    return true;
}

color getSlotColor(int row, int column)
{ // returns color of the token in the slot
    return boardSlotsMatrix[row][column];
}