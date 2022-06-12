#include <GL/glut.h>
#include "Constants.h"
#include "Shapes.h"

// place token initial parameters
int placeTokenX = OFFSET_X + SLOT_MARGIN;
int placeTokenY = OFFSET_Y + BOARD_HEIGHT + RADIUS;
color placeTokenColor = YELLOW;

void init();
void startGame();
void drawSlots();
void keyboardInput(int, int, int);

void Connect4(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(glutGet(GLUT_SCREEN_HEIGHT) / 2, 0);
    glutCreateWindow("Connect 4");
    init();                          // initialize parameters
    glutSpecialFunc(keyboardInput);  // special keyboard keys input process
    glutKeyboardFunc(keyboardInput); // keyboard input process
    glutDisplayFunc(startGame);
    glutMainLoop();
}

void init()
{
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
}

void drawSlots()
{
    for (int j = OFFSET_Y + SLOT_MARGIN, row = 0; row < 6; j += 2 * RADIUS + SLOT_MARGIN, row++)
        for (int i = OFFSET_X + SLOT_MARGIN, column = 0; column < 7; i += 2 * RADIUS + SLOT_MARGIN, column++)
            drawCircle(RADIUS, i, j, NONE);
    drawCircle(RADIUS, placeTokenX, placeTokenY, placeTokenColor); // place token
}

// keyboard input process function
void keyboardInput(int key, int x, int y)
{

    switch (key)
    {
    case GLUT_KEY_RIGHT: // right arrow key
        placeTokenX = placeTokenX + 2 * RADIUS + SLOT_MARGIN;
        if (placeTokenX > OFFSET_X + BOARD_WIDTH - SLOT_MARGIN) // when last column reached, set next column to start column
            placeTokenX = OFFSET_X + SLOT_MARGIN;
        break;
    case GLUT_KEY_LEFT: // left arrow key
        placeTokenX = placeTokenX - 2 * RADIUS - SLOT_MARGIN;
        if (placeTokenX < OFFSET_X + SLOT_MARGIN) // when in first column, set previous column to last column
            placeTokenX = OFFSET_X + BOARD_WIDTH - SLOT_MARGIN - 2 * RADIUS;
        break;
    case 13:                           // enter key
        if (placeTokenColor == YELLOW) // switch token color
            placeTokenColor = RED;
        else if (placeTokenColor == RED)
            placeTokenColor = YELLOW;
        break;
    default: // unassigned keys
        return;
    }

    glutPostRedisplay();
}

void startGame()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawBoard();
    drawSlots();

    glFlush();
}
