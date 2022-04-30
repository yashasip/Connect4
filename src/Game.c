#include <GL/glut.h>

void init();
void startGame();

void Connect4(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(700, 200);
    glutCreateWindow("Connect 4");
    init(); // initialize parameters
    glutDisplayFunc(startGame);
    glutMainLoop();
}

void init()
{
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0.0, 500.0, 500.0, 0.0);
}

void startGame()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}
