#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <gl/freeglut.h>
#include <gl/GL.h>
using namespace std;
class GLTDraw {
private:
	string title;
	int width, height;
public:
	GLTDraw(int w, int h, string t) :width(w), height(h), title(t) {}
	~GLTDraw() {
		cout << "GLTest End." << endl;
	}
	void GLInit(int *argv,char *argc[]) {
		char t[0xff] = {0};
		strcpy(t,title.c_str());
		glutInit(argv, argc);
		glutCreateWindow(t);
		glutInitWindowSize(width, height);
		glutInitDisplayMode(GL_RGBA | GL_DOUBLE | GL_DEPTH);
		glutSetColor(0,0,0,0);
		glutDisplayFunc(GLScreen);
		glutIdleFunc(GLScreen);
		glutKeyboardFunc(KeyInput);
		glEnable(GL_DEPTH_TEST);
		glutMainLoop();
		
	}
	static void GLScreen() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
		glLineWidth(5.0);
		glColor4ub(1, 128, 64, 1);
		glBegin(GL_TRIANGLES);
		glVertex2d(0.5, 0);
		glVertex2d(0, -0.5);
		glVertex2d(0.25, 0.25);
		glEnd();
		glPopMatrix();
		glutSwapBuffers();
		glFlush();
		
	}
	static void KeyInput(unsigned char key, int x, int y) {
		switch (key) {
			case 27:
				exit(0); break;
		}
	}
};