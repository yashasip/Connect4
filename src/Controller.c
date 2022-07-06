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

    int row = unfilledTop[column];
    boardSlotsMatrix[row][column] = fillColor;
    unfilledTop[column]++;

    return true;
}

color getSlotColor(int row, int column)
{ // returns color of the token in the slot
    return boardSlotsMatrix[row][column];
}

bool isFourConnect(int column, color tokenColor)
{
    int row = unfilledTop[column] - 1; // last filled row is before the unfilled column
    int connectCount = 0;
    int startRow, startCol; // for diagonal and anti digonal check
    for (int boardCol = 0; boardCol < BOARD_COLUMN_COUNT; boardCol++)
    { // check the placed token row
        if (boardSlotsMatrix[row][boardCol] != tokenColor) // boardCol changes
            connectCount = 0; // reset count when connection lost
        else if (boardSlotsMatrix[row][boardCol] == tokenColor)
            connectCount++; // increment connection count
        if (connectCount == 4)
            return true;
    }

    connectCount = 0; // reset count
    for (int boardRow = 0; boardRow < BOARD_ROW_COUNT; boardRow++) // check the placed token column
    {
        if (boardSlotsMatrix[boardRow][column] != tokenColor) // boardRow changes
            connectCount = 0;
        else if (boardSlotsMatrix[boardRow][column] == tokenColor)
            connectCount++;
        if (connectCount == 4)
            return true;
    };

    connectCount = 0;
    startCol=column, startRow=row; 

    while(startCol>0 && startRow>0)
    { // find points diagonal start points
        startCol--;
        startRow--;
    }
    for (int boardCol = startCol, boardRow = startRow; boardRow < BOARD_ROW_COUNT && boardCol < BOARD_COLUMN_COUNT; boardCol++, boardRow++) // diagonal
    {
        if (boardSlotsMatrix[boardRow][boardCol] != tokenColor)
            connectCount = 0;
        else if (boardSlotsMatrix[boardRow][boardCol] == tokenColor)
            connectCount++;
        if (connectCount == 4)
            return true;
    }

    connectCount = 0;
    startCol=column, startRow=row; 
    while (startCol < BOARD_COLUMN_COUNT-1 && startRow > 0) // terminates when anti-diagonal endpoints reached
    {
        startCol++;
        startRow--;
    }
    for (int boardCol = startCol, boardRow = startRow; boardCol >= 0 && boardRow < BOARD_ROW_COUNT; boardCol--, boardRow++) // anti-diagonal
    {
        if (boardSlotsMatrix[boardRow][boardCol] != tokenColor)
            connectCount = 0;
        else if (boardSlotsMatrix[boardRow][boardCol] == tokenColor)
            connectCount++;
        if (connectCount == 4)
            return true;
    }

    return false;
}