#include <GL/glut.h>
#include <iostream> 
#include <fstream> 


const int Max=2000;

using namespace std;

float zoom, rootx, rooty, tx, ty;

void myInit( void )  {
  glClearColor( 1.0, 1.0, 1.0, 0.0 );
  glColor3f( 0.0, 0.0, 0.0 );
  glPointSize( 1.0 );
}

void setWindow(GLdouble left,GLdouble right,GLdouble bottom,GLdouble top,GLdouble f,GLdouble n){
            glMatrixMode(GL_PROJECTION); 
            glLoadIdentity(); 
            glOrtho(left, right, bottom, top, f, n); 
     }

void myDisplay( void )  {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  setWindow(-10,15,-10,15, -10, 15);
  //rotated and zoom.
  glTranslatef(0.0,0.0,zoom);
  glTranslatef(tx,ty,0.0);
  glRotatef(rootx, 1.0, 0.0, 0.0);
  glRotatef(rooty, 0.0, 1.0, 0.0);
  glPushMatrix();
  
  float A[Max][3];
  float B[Max][3];
  ifstream data("face.dat");
    int n,m;
    if(!data){
          cout << "file wasn't opened" << endl;
    }else {
          data >> n;
          for(int i=0;i<n;i++){                  
                  data >> A[i][0] >>  A[i][1] >> A[i][2] ; 
                  B[i][0] = -A[i][0]; 
                  B[i][1] =  A[i][1];  
                  B[i][2] =  A[i][2];    
          }
          data >> m;
          for(int i=0;i<m;i++){   
                  int x,y,z;
                  data >> x >> y >> z ;                                    
                  glBegin(GL_LINE_STRIP); 
                  glVertex3f(A[x][0],A[x][1],A[x][2]);
                  glColor3f(1.0,0.4,0.3);
                  glVertex3f(A[y][0],A[y][1],A[y][2]);
                  glVertex3f(A[z][0],A[z][1],A[z][2]);
                  glEnd();
                  glBegin(GL_LINE_STRIP);
                  glVertex3f(B[x][0],B[x][1],B[x][2]);
                  glVertex3f(B[y][0],B[y][1],B[y][2]);
                  glColor3f(0.0,0.4,0.7);
                  glVertex3f(B[z][0],B[z][1],B[z][2]);
                  glEnd();
          }
          glFlush();
    }
    data.close();
    glPopMatrix();
    glutSwapBuffers();
}

void reshape (int w,int h) {
            glViewport (0, 0, (GLsizei) w, (GLsizei) h);
            glMatrixMode (GL_PROJECTION);
            glLoadIdentity ();
            gluPerspective(0.0, (GLfloat) w/(GLfloat) h, 0.0,0.0);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt (0.0,0.0,10.0,0.0,0.0,0.0,0.0,1.0,0.0);
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'm' :
            zoom = zoom -0.1 ;
            glutPostRedisplay();
            break;
        case 'n' :
            zoom = zoom +0.1 ;
            glutPostRedisplay();
            break;
        case 'q' :
            rootx = (rootx + 1);
            glutPostRedisplay();
            break;
        case 'Q' :
            rootx = (rootx - 1);
            glutPostRedisplay();
            break;
        case 'e':
            rooty = (rooty + 1);
            glutPostRedisplay();
            break;
        case 'E':
            rooty = (rooty - 1);
            glutPostRedisplay();
            break;
        case 'w' :
            tx = ty ;
            ty = ty + 0.1;
            glutPostRedisplay();
            break;
        case 's' :
            tx = ty ;
            ty = ty - 0.1;
            glutPostRedisplay();
            break;
        case 'd' :
            tx = tx + 0.1;
            ty = tx ;
            glutPostRedisplay();
            break;
        case 'a' :
            tx = tx - 0.1;
            ty = tx ;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}


int main( int argc, char *argv[] )  {
  // Initialize GLUT.
  glutInit( &argc, argv );
  // Set the mode to draw in.
  glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
  // Set the window size in screen pixels.
  glutInitWindowSize( 800, 600 );
  // Set the window position in screen pixels.
  glutInitWindowPosition( 00, 0 );
  // Create the window.
  glutCreateWindow( "Lab 07" );
  // Set the callback funcion to call when we need to draw something.
  glutDisplayFunc( myDisplay );
  
  glutReshapeFunc(reshape);
  // Initialize some things.
  glutKeyboardFunc(keyboard);
  
  myInit( );
  // Now that we have set everything up, loop responding to events.
  glutMainLoop( );
}

/* ----------------------------------------------------------------------- */

