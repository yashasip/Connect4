#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "Constants.h"

void drawCircle(int radius, int offset_x, int offset_y, color color_value)
{
    double y, x;
    glBegin(GL_POLYGON);
    {
        glEnable(GL_POLYGON_SMOOTH); // enabling smooth drawing of polygon edges
        /* set color of token */
        if (color_value == YELLOW)
            glColor3f(0.9216, 0.8784, 0);
        else if (color_value == RED)
            glColor3f(0.9216, 0.1961, 0.3608);
        else
            glColor4f(1, 1, 1, 1); // transparent color

        for (double i = 0; i <= 360; i += 0.1) // draw circle based on polar equation
        {
            x = radius * cos(i * PI / 180); // converting i from degree to rads
            y = radius * sin(i * PI / 180);
            glVertex2d(offset_x + radius + x, offset_y + radius + y); // circle drawn at distance of offset + radius from window border
        }
    }
    glEnd();
}

void drawBoard()
{
    glBegin(GL_QUADS);
    {
        glColor3f(0.3255, 0.2235, 0.9961);
        glVertex2i(OFFSET_X, OFFSET_Y);
        glVertex2i(BOARD_WIDTH + OFFSET_X, OFFSET_Y);
        glVertex2i(BOARD_WIDTH + OFFSET_X, OFFSET_Y + BOARD_HEIGHT);
        glVertex2i(OFFSET_X, OFFSET_Y + BOARD_HEIGHT);
    }
    glEnd();
}
