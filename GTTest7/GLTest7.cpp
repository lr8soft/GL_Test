#include "GLTestClass.cpp"
#include <iostream>
void main(int line,char *input[]) {
	GLTDraw test(600,400,"GLTest7");
	test.GLInit(&line,input);
	test.~GLTDraw();
	system("pause");
}