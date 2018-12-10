#include <GL/glut.h>
#include <iostream>
#include <string>
using namespace std;
int width=600, height=400;
double a = 0;
void glInit() {
	glClear(GL_COLOR_BUFFER_BIT);
}
void showScreen() {
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glColor4ub(128,128,0,0);
	glVertex2d(0,0);
	glVertex2d(0,0.5);
	glVertex2d(0.5, 0);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}

void reShape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);//left right,buttom,up (left,buttom),(right,up)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main(int line,char *input[]) {
	char title[0xff];
	sprintf_s(title,"GLTest4 -%s -LT_lrsoft",input[0]);
	glutInit(&line,input);
	glutCreateWindow(title);
	glutInitWindowSize(width,height);
	glInit();
	glutInitDisplayMode(GL_RGBA|GL_DEPTH|GL_DOUBLE);
	glutDisplayFunc(showScreen);
	glutIdleFunc(showScreen);	
	glEnable(GL_DEPTH_TEST);
//	glutReshapeFunc(reShape);
	glutMainLoop();
}