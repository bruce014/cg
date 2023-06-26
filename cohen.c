#include <GL/glut.h>
#include <stdio.h>

float xmin = 100, ymin = 100, xmax = 200, ymax = 200;
int bottom = 1, left = 2, top = 4, right = 8;

int compute(float x, float y)
{
	int code = 0;
	if(x<xmin)
		code = code | left;
	if(x>xmax)
		code = code | right;
	if(y<ymin)
		code = code | bottom;
	if(y>ymax)
		code = code | top;
		
	return code;
}

void clipping(float x1, float y1, float x2, float y2)
{
	int code1, code2, codeout;
	int done = 0, accept = 0;
	float x,y;
	
	code1 = compute(x1,y1);
	code2 = compute(x2,y2);
	printf("%d %d", code1, code2);
	
	do
	{
		if((code1 | code2) == 0)
		{
			done = 1;
			accept = 1;
		}
		else if(code1 & code2)
		{
			done = 1;
		}
		else
		{
			if(code1)
				codeout = code1;
			else
				codeout = code2;
				
			if(codeout & left)
			{
				x = xmin;
				y = y1 + (xmin-x1) * ((y2-y1)/(x2-x1));
			}
			else if(codeout & right)
			{
				x = xmax;
				y = y1 + (xmax-x1) * ((y2-y1)/(x2-x1));
			}
			else if(codeout & bottom)
			{
				x = x1 + (ymin-y1) * ((x2-x1)/(y2-y1));
				y = ymin;
			}
			else
			{
				x = x1 + (ymax-y1) * ((x2-x1)/(y2-y1));
				y = ymax;
			}
			
			if(codeout==code1)
			{
				x1 = x;
				y1 = y;
				code1 = compute(x1,y1);
			}
			
			if(codeout==code2)
			{
				x2 = x;
				y2 = y;
				code2 = compute(x2,y2);
			}
		}
	}
	while(done==0);
	
	if(accept)
	{
		glPushMatrix();
		glTranslatef(120, 120, 0);
		

		glColor3f(0,0.7,0.3);
		glBegin(GL_LINE_LOOP);
			glVertex2f(xmin, ymin);
			glVertex2f(xmax, ymin);
			glVertex2f(xmax, ymax);
			glVertex2f(xmin, ymax);
		glEnd();
		
		glBegin(GL_LINES);
			glVertex2f(x1,y1);
			glVertex2f(x2,y2);
		glEnd();
		
		glPopMatrix();
	}
}

void display()
{
	float x1 = 120, y1 = 50, x2 = 160, y2 = 230;
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.7,0.3,0);
	
		glBegin(GL_LINE_LOOP);
			glVertex2f(xmin, ymin);
			glVertex2f(xmax, ymin);
			glVertex2f(xmax, ymax);
			glVertex2f(xmin, ymax);
		glEnd();
		
		glBegin(GL_LINES);
			glVertex2f(x1,y1);
			glVertex2f(x2,y2);
		glEnd();
		
		clipping(x1,y1,x2,y2);
		
		glFlush();
}

void myinit()
{
	gluOrtho2D(0,500,0,500);
}

int main(int argc, char **argv)
{

	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("1CR20CS155 Line Clipping");
	
	myinit();
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}





















