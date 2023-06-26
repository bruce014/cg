#include<GL/glut.h>
#include<stdio.h>

float x0,y0,x1,y1;
void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	float dx,dy,x,y,df, incrx=1, incry=1;
	int i;
	dy = abs(y1-y0);
	dx = abs(x1-x0);
	
	df = (2*dy)-dx;
	
	if(x1<x0)
		incrx=-1;
		
	if(y1<y0)
		incry=-1;
	
	x=x0;
	y=y0;
	
	glColor3f(0,0,1);
	if(dx>dy)
	{
		glBegin(GL_POINTS);
			for(i=0;i<dx;i++)
			{
				if(df>0)
				{
					x = x + incrx;
					y = y + incry;
					df = df + (2*dy) - (2*dx);
				}
				else
				{
					x = x + incrx;
					df = df + (2*dy);	
				}
				printf("%f %f\n",x,y);
				glVertex2f(x,y);
			}
		glEnd();
	}
	else
	{
		glBegin(GL_POINTS);
			for(i=0;i<dy;i++)
			{
				if(df>0)
				{
					x = x + incrx;
					y = y + incry;
					df = df + (2*dx) - (2*dy);
				}
				else
				{
					x = x + incrx;
					df = df + (2*dx);	
				}
				printf("%f %f\n",x,y);
				glVertex2f(x,y);
			}
		glEnd();
	}
	
	
	glFlush();
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);
		gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	printf("Enter the line vertex values\n");
	scanf("%f %f %f %f", &x0, &y0, &x1, &y1);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("1CR20CS155 Bresenham's Line Drawing algorithm");
	
	myinit();
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
}



























