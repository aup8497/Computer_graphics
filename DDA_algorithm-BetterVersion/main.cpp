#include<Windows.h>
#include <GL/glut.h>

#include<stdio.h>
void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void display(void)
{   float fx,fy;
    int x0,x1,y0,y1;
    x0=10;y0=10;x1=100;y1=90;
    float m;
    m=float(y0-y1)/float(x0-x1);
    printf("%f",m);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	int a,b,c;
	a=(y1-y0);b=(x0-x1);c=x1*y0-x0*y1;

	//draw two points
	glBegin(GL_POINTS);
			glVertex2i(10,10);
            fx=x0;fy=y0;
            while(fx!=x1)
            {
            float res=a*(fx+1)+b*(fy+1/2)+c;
            if(res>0){fx=fx+1;fy=fy+1;
                glVertex2i(fx,fy);
            }else{
            fx=fx+1;fy=fy;
            glVertex2i(fx,fy);
            }
            }



	glEnd();

	//draw a line

	glFlush();
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
