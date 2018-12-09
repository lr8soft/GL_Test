#include <iostream>
#include "glut.h"
#include <windows.h>
class sline {
public:
	double *p1=NULL, *p2=NULL, r, g, b;
	double angle = 0; bool spin = false;
	sline(double ip1[],double ip2[],double ir,double ig,double ib) {
		p1 = ip1;
		p2 = ip2;
		r = ir;  g = ig;
		b = ib;
	}
	void showInfo() {
		printf("%lf %lf\n",p1[0],p1[1]);
		printf("%lf %lf\n", p2[0], p2[1]);
		printf("RGB:%lf %lf %lf\n",r,g,b);
	}
	void showLine() {
		glPushMatrix();
		glLineWidth(5);
		if (spin == true) glRotated(angle++,0,0,0);
		glBegin(GL_LINE_LOOP);
		glColor4ub(r, g, b,0);
	//	glColor3b(r,b,g);
		glVertex2dv(p1);
		glVertex2dv(p2);
		glEnd();
		glPopMatrix();
		glutSwapBuffers();
		glFlush();
	}
	void lineSpin() {
		int i;
		for (i = 0; i < 2; i++) {
			p1[i] = -p1[i];
			p2[i] = -p2[i];
		}
	}
	void coordSwap() {
		int i,temp;
		for (i = 0; i < 2; i++) {
			temp = p1[i];
			p1[i] = p2[i];
			p2[i] = temp;
		}
	}
	void CalculateFrameRate(){
		static float framesPerSecond = 0.0f;
		static float lastTime = 0.0f;
		float currentTime = GetTickCount() * 0.001f;
		++framesPerSecond;
		if (currentTime - lastTime > 1.0f)
		{
			lastTime = currentTime;
			printf("%f\n",framesPerSecond);
			framesPerSecond = 0;
		}
	}
};