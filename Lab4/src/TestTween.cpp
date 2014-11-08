/*
 * TestTween.cpp
 *
 *  Created on: Oct 18, 2014
 *      Author: admin
 */

#include "TestTween.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <GL/glut.h>

#define RATIO 1.618          //Golden Raito 1:1.618
#define WW    100            //Width of viewport
#define WH    (WW/RATIO)     //Height of viewport
#define HALFX ((int)(WW/2))  //X coordinate  min/max
#define HALFY ((int)(WH/2))  //Y coordinate  min/max
#define deltat .0005	         //increment of t
//Globals
int WindowWidth;             //Window width in pixels
int WindowHeight;            //Window height in pixels

//Prototypes
void InitGL();
void Display();
void Reshape(int,int);

int main(int argc, char **argv)
{

    //initialize glut
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);

    //initialize window width and height using the golden ratio
    WindowWidth  = (int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.8);
    WindowHeight = (int)(WindowWidth/RATIO);

    //Create window
    glutInitWindowSize(WindowWidth,WindowHeight);
    glutInitWindowPosition((int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.1)
    		,(glutGet((GLenum)GLUT_SCREEN_HEIGHT)/2)-(WindowHeight/2));
    glutCreateWindow("Tween Demo");

    //register callback functons
    glutDisplayFunc(Display);               //display a frame
    glutReshapeFunc(Reshape);               //resize the window size

    InitGL();								//initialize open gl

    glutMainLoop();							//begin event processing

}//end main

/////////////////////////////////////////////////////////////////////////////
//Display is the callback glut display function.  This
//function causes the starting shape to change into the ending
//shape.
/////////////////////////////////////////////////////////////////////////////
void Display()
{
    //Data for the shapes and colors
    float StartShape[9][2]={{0,10},{-25,10},{-25,  0},{-5,0},{-5,  -20},{5,-20},{5,  0},{25,  0},{25,10}};
    float EndShape[9][2]=  {{-25,10},{-25,-20},{-5,-20},{-5,-10},{5,-10},{5,-20},{25,-20},{25,10},{0,20}};
    float IntermediateShape[9][2];
    float VertexColors[9][3]={{1,0,0},{1,0,0},{1,0,0},{0,1,0},{0,1,0},{0,1,0},{0,0,1},{0,0,1},{0,0,1}};

    static float Tween=0.0-deltat;//initial value of Tween so the first point is correct
    if(Tween<1)
    {
        Tween+= deltat;           //actual value of Tween
    }

    //calculate intermediate shape
    for (int Vtx=0;Vtx<9;Vtx++)
    {
        IntermediateShape[Vtx][0]=(1.0-Tween)*StartShape[Vtx][0]+Tween*EndShape[Vtx][0];
        IntermediateShape[Vtx][1]=(1.0-Tween)*StartShape[Vtx][1]+Tween*EndShape[Vtx][1];
    }

    //set open GL vertex array pointer and color array pointer
    glVertexPointer(2,GL_FLOAT,0,IntermediateShape);
    glColorPointer(3,GL_FLOAT,0,VertexColors);

	for (int i = 0; i < 1000000; i++);  //lazy man's loop

    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_LINE_LOOP,0,9);//draw the shape

    glutSwapBuffers();             //display frame on screen
    glutPostRedisplay();           //request draw next frame

}//end Display

/////////////////////////////////////////////////////////////////////
//Reshape is the callback glut reshape function.
//Reshape prevents the user from changing the aspect
//ratio of the window.
//
//w = window width
//h = window height required by glut but unused here
//////////////////////////////////////////////////////////////////
void Reshape(int w,int h)
{
    glutReshapeWindow(w,(int)(w/RATIO));
    WindowWidth=w;
    WindowHeight=(int)(w/RATIO);
    InitGL();   //reinitialize openGL
}

///////////////////////////////////////////////
//InitGl sets open gl to its initial state.
/////////////////////////////////////////////
void InitGL()
{

    //center view around orgin
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-HALFX,HALFX,-HALFY,HALFY);
    glMatrixMode(GL_MODELVIEW);

    //set state variables
    glClearColor(1, 1, 1, 1);
    glEnableClientState (GL_VERTEX_ARRAY);  //enable vertex array
    glEnableClientState (GL_COLOR_ARRAY);   //enable vertex color array
    glShadeModel(GL_SMOOTH);
    glViewport(0,0,WindowWidth,WindowHeight);

}//end InitGl
