// GLTest2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "glut.h"
double angle = 0.0;
double r = 0, g = 0, b =0,delta=0.8;
double px=0, py=0;
void init() {	
	glClear(GL_COLOR_BUFFER_BIT);
}
void showscreen() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glLineWidth(5.0);
	glBegin(GL_LINE_LOOP);
	glRotated(angle,0,0,0);
	glColor4ub(r,g,b,128);
	glVertex2d(1,1);
	glVertex2d(1, -1);
	glVertex2d(-1, -1);
	glVertex2d(-1,1);
	glBegin(GL_POINTS);
	glVertex2d(px,py);
	glEnd();

	glEnd();
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
	angle++;
	if (r<255) {
		r++;
	}
	else {
		if (g < 255) {
			g++;
		}
		else {
			if (b < 255) {
				b++;
			}
			else {
				r = b = g = 0;
			}
		}
		
	}
}

void eb(unsigned char key,int x,int y) {
	switch (key) {
		case 27:
			exit(0); break;
		case '1':
			delta=100; break;
		case '2':
			delta = 0.1; break;
		case 'w':
			py += 0.1; break;
		case 's':
			py -= 0.1; break;
		case 'a':
			px -= 0.1; break;
		case 'd':
			px += 0.1; break;

	}
}
void main(int input, char *inchar[])
{
	glutInit(&input, inchar); 
	glutCreateWindow("Title");
	glutInitWindowSize(400,300);
	glutPositionWindow(50,50);
	glutInitDisplayMode(GL_DEPTH|GLUT_DOUBLE|GL_RGBA);/*双缓冲区通过在后一个缓冲区里绘画，\
	并不停交换前后缓冲区（可见缓冲区），来产生平滑的动画。使用双缓冲区可以预防闪烁。*/
	init();
	glutDisplayFunc(showscreen);
	glutIdleFunc(showscreen);/*这个函数使另一个函数在程序空闲的时候就会被调用。*/
	glutFullScreen();
	//glutSpecialFunc(function);
	glutKeyboardFunc(eb);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
