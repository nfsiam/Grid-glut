#include <windows.h>
#include <Gl/glut.h>
#include "siam.h"

GLfloat p=100;


void reshape(int width,int height)
{
    if (height==0){height =1;} //preventing divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0,0,(GLsizei)width,(GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(width >= height)
    {
        gluOrtho2D((-1*p) * aspect, (1*p) * aspect, (-1*p), (1*p));
    }
    else
    {
        gluOrtho2D((-1*p), (1*p), (-1*p) / aspect, (1*p) / aspect);
    }
    glMatrixMode(GL_MODELVIEW);
}

void drawGrid()
{
    glLineWidth(1);
    glColor4ub(0,0,0,60);
    glBegin(GL_LINES);

    for(int i= -160 ;i<=160;i=i+20)
    {
        glLineWidth(0.1);
        glVertex2f(i,100);
        glVertex2f(i,-100);

        glVertex2f(160,i);
        glVertex2f(-160,i);


    }

    glLineWidth(0.5);
    glColor4ub(0,0,0,30);
    glBegin(GL_LINES);

    for(int i= -160 ;i<=160;i=i+10)
    {
        glLineWidth(0.1);
        glVertex2f(i,100);
        glVertex2f(i,-100);

        glVertex2f(160,i);
        glVertex2f(-160,i);


    }

    glColor3ub(0,0,0);


    glEnd();



    for(int i=-160;i<160;i+=20)
    {
        for(int j=-100;j<100;j+=20)
        {
            char ii[10];
            itoa(i,ii,10);
            char jj[10];
            itoa(j,jj,10);

            char text[10]="";
            strcat(text,ii);
            strcat(text,",");
            strcat(text,jj);
            drawBitmapText(text,i,j,0);
        }
    }
}

void drawBitmapText(char *string,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x, y,z);

	for (c=string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
	}
}
