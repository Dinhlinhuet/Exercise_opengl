#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0,shoulder1 = 0, elbow1 = 0;
int x,y,z;
void DrawTorso(){
	glPushMatrix();
	gluCylinder(object, baseRadius, topRadius, lenght, slices, stacks);
	glTranslatef(0.0, 0.0, lenght);
	gluDisk(object, 0.0, topRadius, slices, stacks); // top cover
	glRotatef(180, 0.0, 1.0, 0.0); // flip
	glTranslatef(0.0, 0.0, lenght);
	gluDisk(object, 0.0, baseRadius, slices, stacks); // base cover
	glPopMatrix();
}
void DrawArm(){
	glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		glTranslatef(-3.0, 0.0, 0.0);
		glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
		glTranslatef(1.0, 0.0, 0.0);
		glPushMatrix();
		glScalef(2.0, 0.4, 1.0);
		glutWireCube(1.0);
		glPopMatrix();

		glTranslatef(-1.0, 0.0, 0.0);
		glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
		glTranslatef(1.0, 0.0, 0.0);
		glPushMatrix();
		glScalef(2.0, 0.4, 1.0);
		glutWireCube(1.0);
		glPopMatrix();

		glTranslatef(1.0, 0.0, 0.0);
		glRotatef((GLfloat) shoulder1, 0.0, 0.0, 2.0);
		glTranslatef(1.0, 0.0, 0.0);
		glPushMatrix();
		glScalef(2.0, 0.4, 1.0);
		glutWireCube(1.0);
		glPopMatrix();

		glPopMatrix();
		glutSwapBuffers();
}
void DrawHand(){

}
void DrawFinger(){

}
void display(void){
	 glTranslatef(x,y,z);          //  1) position for drawing torso
	 DrawTorso();                  //  2) draw torso
	 glPushMatrix();               //  3) save torso matrix
	    glTranslatef(x,y,z);       //  4) position for drawing arm
	    DrawArm();                 //  5) draw arm
	    glPushMatrix();            //  6) save arm matrix
	       glTranslatef(x,y,z);    //  7) position for drawing hand
	       DrawHand();             //  8) draw hand
	       glPushMatrix();         //  9) save hand matrix
	          glTranslatef(x,y,z); // 10) position for drawing first finger
	          DrawFinger();        // 11) draw first finger
	       glPopMatrix();          // 12) load hand matrix
	       glPushMatrix();         // 13) save hand matrix again
	          glTranslatef(x,y,z); // 14) position for drawing second finger
	          DrawFinger();        // 15) draw second finger
	       glPopMatrix();          // 16) load hand matrix
	       glPushMatrix();         // 17) save hand matrix again
	          glTranslatef(x,y,z); // 18) position for drawing third finger
	          DrawFinger();        // 19) draw third finger
	       glPopMatrix();          // 20) load hand matrix
	    glPopMatrix();             // 21) load arm matrix
	 glPopMatrix();                // 22) load torso matrix
};
void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 's':
		shoulder = (shoulder + 5) % 360;
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5) % 360;
		glutPostRedisplay();
		break;
	case 'e':
		elbow = (elbow + 5) % 360;
		glutPostRedisplay();
		break;
	case 'E':
		elbow = (elbow - 5) % 360;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
