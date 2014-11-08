
#include <math.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include "bai2.h"

static const GLfloat PI = 3.14159265358979323846; 
void MyInit (void)
{
    glClearColor (0.0,0.0,0.0,0.0);
    //glLineWidth (1.0);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (10.0,-5.0,10.0,-4.0);
}

void veham (void)
{
        glClear (GL_COLOR_BUFFER_BIT);
	    glShadeModel(GL_SMOOTH);
	    float y,x;
	    glBegin (GL_LINE_STRIP);
	    glColor3f (1.0f, 0.0f, 1.0f);
	    for ( x = -2.4; x < 1; x += 0.01) {
	    	 y=x*x*x + 2*x*x + 3;
			 glVertex2f (x, y);
			}
		glEnd();
		glBegin (GL_LINE_STRIP);
		glColor3f (0.0f, 0.0f, 1.0f);  
		for ( x = 0; x < 2*PI; x += PI/1000) {
	    	 y=2*sin(x) + 0.5*cos(x);
			 glVertex2f (x, y);
			}
		glEnd();  
		glFlush(); 
	}

int main (int argc, char ** argv)
{
    glutInit (& argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600,600);
    glutInitWindowPosition (200,50);
    glutCreateWindow ("veham");
    glutDisplayFunc (veham);
    MyInit ();
    glutMainLoop ();
    return 0;
}
