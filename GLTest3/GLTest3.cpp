#include "GLclass.cpp"
#include <iostream>
#include "glut.h"
static double p1[] = { 0,0.75 }, p2[] = {0.5,-0.25};
sline line = sline(p1, p2, 128, 0, 1);
void init() {
	glClear(GL_COLOR_BUFFER_BIT);
}
void showscreen() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	line.showLine();
	line.CalculateFrameRate();
}
void keyPress(unsigned char key,int x,int y) {
	switch (key) {
		case 27:
			exit(0); break;
		case 'w':
			p1[1]+=0.1; p2[1] += 0.1; break;
		case 's':
			p1[1]-= 0.1; p2[1]-= 0.1; break;
		case 'a':
			p1[0]-= 0.1; p2[0]-= 0.1; break;
		case 'd':
			p1[0]+= 0.1; p2[0]+= 0.1; break;
		case 'r':
			line.lineSpin(); break;
		case 't':
			line.coordSwap(); break;
			
	}
}
void main(int il,char *input[]) {
	glutInit(&il,input);
	glutCreateWindow("GLTest3");
	glutInitWindowSize(400,300);
	glutInitDisplayMode(GL_DOUBLE|GL_DEPTH|GL_RGBA);
	init();
	glutDisplayFunc(showscreen);
	glutIdleFunc(showscreen);
	glutKeyboardFunc(keyPress);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}