/*
 * Rose.cpp
 *
 *  Created on: Oct 10, 2014
 *      Author: admin
 */
#include <GL/glut.h> // GLUT stuff - includes OpenGL headers#include <gl/gl.h>
#include <gl/glu.h>
#include "Rose.h"
#include "math.h"

float x=0;
float y = 5 * cos(x);
//void drawsKose() {
//	glBegin(GL_LINES);
//	glVertex2d(50, 50);
//	glColor3f(0.1, 0.5, 0.75);
//	glVertex2d(40,40);
//	//glColor3d(0.1, 0.5, 0.75);
//	glEnd();
//}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw fractal
	glLineWidth(2.0);
	glColor3d(0.5, 0.0, 0.9);
	//drawsKose();
	glBegin(GL_LINES);
		glVertex2d(50, 50);
		glColor3f(0.1, 0.5, 0.75);
		glVertex2d(40,40);
		//glColor3d(0.1, 0.5, 0.75);
		glEnd();
	// Draw instructions
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glColor3d(0.5, 0.5, 0.0);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glFlush();  // Single-buffered!
}
void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);  // white background
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

/*int main(int argc, char ** argv) {
	// Initialize OpenGL/GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Make a window
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Koch Snowflake");

	// Initialize GL states & register callbacks
	init();
	glutDisplayFunc(display);

	// Do something
	glutMainLoop();

	return 0;
}*/
