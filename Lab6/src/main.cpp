#include <GL/glut.h>

float camera[3] = {1,1,7};
float temp = 0.1;


                     
//==============================================================================           
void display (void)
{
     glClear(GL_COLOR_BUFFER_BIT);
     glLoadIdentity( );
     gluLookAt(camera[0], camera[1], camera[2],1, 1, 1,
               1, 0,0 );
     //glutWireCube(2.0f); 
     glutWireSphere(2,20,20);
     glutWireCube(5);
     glFlush(); 
     glutSwapBuffers();
}
//==============================================================================
void eventKeyboard(int key, int x, int y)
{
     switch(key)
     {
                case GLUT_KEY_LEFT:
                     camera[1] -= temp;
                     display();
                     break;
                case GLUT_KEY_RIGHT:
                     camera[1] += temp;
                     display();
                     break;
                case GLUT_KEY_UP:
                     camera[0] +=  temp;
                     display();
                     break;
                case GLUT_KEY_DOWN:
                     camera[0] -=  temp;
                     display();
                     break;
                case GLUT_KEY_F1:
                     camera[2] -= temp;
                     display();
                     break;
                case GLUT_KEY_F2:
                     camera[2] += temp;
                     display();
                     break;
     }
}
//==============================================================================
void reshape (int width, int height)
{
     glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window
     glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed
     glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
     gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes
     glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly

}

//==============================================================================

int main (int argc, char *argv[]) 
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode (GLUT_DOUBLE); // Set up a basic display buffer (only single buffered for now)
    glutInitWindowSize (640, 480); // Set the width and height of the window
    glutInitWindowPosition (100, 100); // Set the position of the window
    glutCreateWindow ("Lab 06"); // Set the title for the window

    glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering

    glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for reshaping

    //glutKeyboardFunc(keyPressed); 
    //glutKeyboardUpFunc(keyUp); // Tell GLUT to use the method "keyUp" for key up events
    glutSpecialFunc(eventKeyboard);
    glutMainLoop(); // Enter GLUT's main loop
}
