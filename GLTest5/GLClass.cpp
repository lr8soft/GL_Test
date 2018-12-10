#include "glut.h"
#include <iostream>
#include <gl/GL.h>
class LineLoop3d{
private:
	double angle;
	double r,g,b;
	bool useRGB;
public:
	double point[10][3];
	int pointcount;
	LineLoop3d(double SrcPoint[10][3],int count){
		//if(count>10) count=10;
		int i,j;
		angle=0;useRGB=false;
		r=0,g=64,g=128;
		for(i=0;i<count;i++){
			for(j=0;j<3;j++){
				point[i][j]=SrcPoint[i][j];
				pointcount=count;
				printf("%lf",SrcPoint[i][j]);
			}
			printf("\n");
		}
	}
	void showLine(){
		int i, x,y,z;
		glLineWidth(10);
		glBegin(GL_LINE_LOOP);
		glRotated(angle,0,1,1);
		glColor4ub(r,g,128,1);
		for(i=0;i<pointcount;i++){
			x=point[i][0];
			y=point[i][1];
			z=point[i][2];
			glVertex3d(x,y,z);
		}
		if(useRGB==true){
			if(r<255){
				r++;
			}else{
				if(g<255){
					g++;
				}else{
					if(b<255){
						b++;
					}else{
						r=b=g=0;
					}
				}
					
			}
		}
		glEnd();
	}
	void letRGB(){
		useRGB=true;
	}
	void showInfo(){
		int i,x,y,z;
		for(i=0;i<pointcount;i++){
			x=point[i][0];
			y=point[i][1];
			z=point[i][2];
			std::cout<<"x:"<<x<<" y:"<<y<<" z:"<<z<<"\n";
		}
	}
	void letSpin(){
		int i;
		for(i=0;i<pointcount;i++){
			point[i][0]=-point[i][0];
			point[i][1]=-point[i][1];
			point[i][2]=-point[i][2];
		}
	}
};