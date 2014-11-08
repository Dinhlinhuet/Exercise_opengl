#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

#include <iostream>
#include <fstream>

using namespace std;

void MyInit (void)
{
    glClearColor (1.0,1.0,1.0,0.0);
    glColor3f (0.5f, 0.5f, 0.9f);
    glLineWidth (1.0);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (0.0,640.0,0.0,480.0);
}

void drawDinosaur (void)
{
    fstream inStream;
    inStream.open ("dinosaur.dat", ios :: in);
    if (inStream.fail ()) return;
    glClear (GL_COLOR_BUFFER_BIT);
    float numpolys, numlines;
    GLint x, y;
    inStream >> numpolys;
    for (int j = 0; j <numpolys; j++)
    {
        inStream >> numlines;
        glBegin (GL_LINE_STRIP);
    for (int i = 0; i <numlines; i++)
    {
        inStream >> x >> y;
        glVertex2i (x, y);
    }
    glEnd ();
    }
    glFlush ();
    inStream.close ();
}

int main (int argc, char ** argv)
{
    glutInit (& argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640,640);
    glutInitWindowPosition (100,150);
    glutCreateWindow ("dinosaur");
    glutDisplayFunc (drawDinosaur);
    MyInit ();
    glutMainLoop ();
    return 0;
}
