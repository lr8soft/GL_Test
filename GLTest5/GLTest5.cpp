#include "GLClass.cpp"
#include "glut.h"
#include <gl/GL.h>
#include <iostream>
using namespace std;
double point[5][3]={{0,1,0},\
					{1,0,0},\
					{0,0,1},\
					{1,1,0},\
					{0,1,1}};
double point2[3][3]={{0,0,0},{-1,-1,0},{-1,0,0}};
double angle=0,delta=0.1;
double x=0,y=255,z=1;
LineLoop3d l=LineLoop3d(point,5);
LineLoop3d l2=LineLoop3d(point2,3);
void init(){
	glClear(GL_COLOR_BUFFER_BIT);
}
void showScreen(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	/*glPushMatrix();
	glLineWidth(5.0);
	glRotated(angle,1,1,1);
	glColor4ub(x,y,z,1);
	glBegin(GL_TRIANGLES);
	glVertex3d(0.5,0,0);
	glVertex3d(0,-0.5,0);
	glVertex3d(0.25,0.25,-0.25);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
	glFlush();*/
	glPushMatrix();
	l.showLine();
	l2.showLine();
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
	angle+=delta;
	
}
void KeyPress(unsigned char key,int x,int y){
	
	switch(key){
		case 27:
			exit(0);break;
		case 'q':
			delta=100;break;
		case 'w':
			l.letRGB();l2.letRGB();break;
		case 's':
			l.letSpin();l2.letSpin();break;
	}
	cout<<"RGB"<<" "<<x<<" "<<y<<" "<<z<<"\n";
}
int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutCreateWindow("GLTest5");
	glutInitWindowSize(600,400);
	glutInitDisplayMode(GL_RGBA|GL_DOUBLE|GL_DEPTH);
	glutDisplayFunc(showScreen);
	glutIdleFunc(showScreen);
	glutKeyboardFunc(KeyPress);
	//glutFullScreen();
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}

