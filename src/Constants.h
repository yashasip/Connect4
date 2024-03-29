#ifndef CONSTANTS_H
#define CONSTANTS_H

#define PI 3.14159265358979323846
#define RADIUS 30.0  // radius of circle token
#define OFFSET_X 100 // the drawing of objects starts from offset
#define OFFSET_Y 10
#define WINDOW_WIDTH 820.0
#define WINDOW_HEIGHT 660.0
#define BOARD_WIDTH 620
#define BOARD_HEIGHT 535
#define BOARD_COLUMN_COUNT 7
#define BOARD_ROW_COUNT 6
#define SLOT_MARGIN 25

typedef enum color
{
    NONE,
    RED,
    YELLOW
} color; // color palette

typedef enum bool
{
    false,
    true
} bool; // user-defined boolean

#endif
