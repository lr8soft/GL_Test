#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "glut.h"
typedef void (*displayfunc)(void);
void init() {
	glClearColor(0, 0, 0, 0);//设置背景颜色
}
void testdisplay() {
	glClear(GL_COLOR_BUFFER_BIT);//使用清除颜色
/*1 glRectf(-0.5f,-0.5f,0.5f,0.5f);//glRectf画一个矩形
	glFlush();//保证gl命令立刻执行*/

	glBegin(GL_TRIANGLES);//画一个三角形
	glVertex3f(-0.5,-0.5,0);
	glVertex3f(0.5,0,0);
	glVertex3f(0,0.5,0);
	glEnd();
	glFlush();

/*3	double x,y;
	glPointSize(3.0f);//点大小3.0f
	glBegin(GL_POINTS);
	glVertex2f(0,0);
	for (x = 0; x < 1;x+=0.01) {
		for (y = 0; y< 1; y += 0.01) {
			glVertex2f(x, y);//坐标么
			glVertex2f(-x, y);
			glVertex2f(x, -y);
			glVertex2f(-x, -y);
		}
	}
	glEnd();
	glFlush();*/


}
void main(int line,char *input[])
{
	displayfunc func = testdisplay;
	glutInit(&line,input);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);//RGB 模式，GLUT_SINGLE单缓冲
	glutInitWindowPosition(100,100);
	glutInitWindowSize(600,400);
	glutCreateWindow("My first OpenGL program.");
	init();
	glutDisplayFunc(func);
	glutMainLoop();

}
