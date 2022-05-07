#include <GL/glut.h>
#include<math.h>
#include<stdio.h>
#include "Constants.h"

void draw_circle(int radius, int offset,color color_value)
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
            x = radius * cos(i * PI / 180);
            y = radius * sin(i * PI / 180);
            glVertex2d(offset + radius + x, offset + radius + y); // circle drawn at distance of offset + radius from window border
        }
    }
    glEnd();
}

void make_haunch(int radius, int offset){
    glBegin(GL_QUADS);
    printf("hello");
    {
        glColor3f(0.3255, 0.2235, 0.9961);
        glVertex2i(100, 10);
        glVertex2i(600, 10);
        glVertex2i(600, 600);
        glVertex2i(100, 600);
    }
    glEnd();
}
