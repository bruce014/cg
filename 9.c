#include<GL/glut.h>
#include<stdio.h>

float x1=200, y1=200, x2=100, y2=300, x3=200, y3=400, x4=300, y4=300;
float x5=200, y5=200, x6=100, y6=300, x7=200, y7=400, x8=300, y8=300;

float le[500], re[500];
int flag=1;

void edge(float x1, float y1,float x2, float y2)
{
	float m = (x2-x1)/(y2-y1);
	int i;
	float x;
	
	x=x1;
	for(i=y1;i<y2;i++)
	{
		if(x<le[i])
			le[i] = x;
		if(x>re[i])
			re[i] = x;
			
		x = x+m;
	}
}

void scanfill()
{
	int i,j;
	
	for(i=0;i<500;i++)
	{
		le[i] = 500;
		re[i] = 0;
	}
	
	edge(x1,y1,x2,y2);
	edge(x2,y2,x3,y3);
	edge(x3,y3,x4,y4);
	edge(x4,y4,x5,y5);
	
	edge(x5,y5,x6,y6);
	edge(x6,y6,x7,y7);
	edge(x7,y7,x8,y8);
	edge(x1,y1,x8,y8);
	
	for(i=0;i<500;i++)
	{
		if(le[i]<re[i])
		{
			for(j=le[i];j<re[i];j++)
			{
				glBegin(GL_POINTS);
					glVertex2f(j,i);
				glEnd();
			}
		}
	}
}

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1,0,1);
	
	glBegin(GL_LINE_LOOP);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
		
		glVertex2f(x5,y5);
		glVertex2f(x6,y6);
		glVertex2f(x7,y7);
		glVertex2f(x8,y8);
	glEnd();
	
	if(flag==2)
		scanfill();
	if(flag==3)
	{
		glColor3f(0,0.5,0.5);
		scanfill();
	}
	if(flag==4)
	{
		glColor3f(0.5,0.5,0);
		scanfill();
	}
	if(flag == 5)
		exit(0);
	glFlush();
}
	
void menu(int n)
{
	if(n==1)
		flag = 1;
	if(n==2)
		flag = 2;
	if(n==3)
		flag = 3;
	if(n==4)
		flag = 4;
	if(n==5)
		flag = 5;
}
	
void myinit()
{
	glMatrixMode(GL_PROJECTION);
		gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{

	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("1CR20CS155 SCANFILL");
	
	myinit();
	glutDisplayFunc(display);
	
	glutCreateMenu(menu);
	glutAddMenuEntry("Outline", 1);
	glutAddMenuEntry("Filled", 2);
		glutAddMenuEntry("color 2", 3);
			glutAddMenuEntry("color 3", 4);
	glutAddMenuEntry("Exit", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutMainLoop();
	return 0;
}

	
	
	
	
	
	
	
	
	
	
	
