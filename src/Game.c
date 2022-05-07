#include <GL/glut.h>
#include "Constants.h"

void init();
void startGame();

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

void startGame()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}
