#include <windows.h>
#include <Gl/glut.h>
#include "siam.h"

void display()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    //start typing your code from here

    //such as I am going to draw a rectangle here

    glColor3ub(0,200,0);
    glRectd(20,20,60,60);



    //comment out below line to stop showing grids
    drawGrid();

    glutSwapBuffers();
}

int main(int argc, char ** argv)
{
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1200,750);
    glutInitWindowPosition(0,0);
    glutCreateWindow("");
    glutDisplayFunc(display);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
