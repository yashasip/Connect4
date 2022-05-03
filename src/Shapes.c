#include <GL/glut.h>
#include<math.h>
#include "Constants.h"

void draw_circle(int radius, int offset,color color_value)
{
    double y, x;
    glBegin(GL_POLYGON);
    {
        glEnable(GL_POLYGON_SMOOTH);
        if (color_value == YELLOW)
            glColor3f(0.9216, 0.8784, 0);
        else if (color_value == RED)
            glColor3f(0.9216, 0.1961, 0.3608);
        else
            glColor4f(0, 0, 0, 0); // transparent color

        for (double i = 0; i <= 360; i += 0.1)
        {
            x = radius * cos(i * PI / 180);
            y = radius * sin(i * 3.142 / 180);
            glVertex2d(offset + radius + x, offset + radius + y);
        }
    }
    glEnd();
}

