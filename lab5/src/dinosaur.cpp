/*
 * dinosaur.cpp
 *
 *  Created on: Oct 18, 2014
 *      Author: admin
 */

#include "dinosaur.h"

/* -- INCLUDE FILES ------------------------------------------------------ */
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <fstream.h>
/* ----------------------------------------------------------------------- */
struct point{
	int x;
	int y;
};
using namespace std;
void readFile(){
	  fstream inStream;
	    inStream.open ("dinosaur.dat", ios :: in);
	    if (inStream.fail ()) return;
	    glClear (GL_COLOR_BUFFER_BIT);
	    float numpolys, numlines, x, y;
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
void myInit(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 1.0);
	glPointSize(3.0);
	glMatrixMode( GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glShadeModel(GL_FLAT);
}

/* ----------------------------------------------------------------------- */

/* ----------------------------------------------------------------------- */
void myDisplay(void) {
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glutSwapBuffers();
	readFile();
}

/* ----------------------------------------------------------------------- */

int main( int argc, char *argv[] )  {
 glutInit( &argc, argv );
 glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
 glutInitWindowSize( 640, 480 );
 glutInitWindowPosition( 100, 150 );
 glutCreateWindow( "Lab05" );
 myInit( );
 glutDisplayFunc( myDisplay );
 glutMainLoop( );
 }

 /* ------------------------------------- */

