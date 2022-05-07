#include <GL/glut.h>
#include "Constants.h"
#include "Shapes.h"

void init();
void startGame();
void drawSlots();

void Connect4(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(glutGet(GLUT_SCREEN_HEIGHT) / 2, 0);
    glutCreateWindow("Connect 4");
    init(); // initialize parameters
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
}

void startGame()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawBoard();
    drawSlots();

    glFlush();
}
