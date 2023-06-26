#include<GL/glut.h>
#include<stdio.h>

float v[8][3] = {{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1},{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1}};

int view[] = {0,0,5};

void polygon(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
		glVertex3f(v[a][0], v[a][1], v[a][2]);
		glVertex3f(v[b][0], v[b][1], v[b][2]);
		glVertex3f(v[c][0], v[c][1], v[c][2]);
		glVertex3f(v[d][0], v[d][1], v[d][2]);
		glEnd();
}

void cube()
{
	glColor3f(0.5,0.5,0);
	polygon(0,1,5,4);
	
	glColor3f(0,0.9,0.1);
	polygon(2,3,7,6);
	
	glColor3f(0.1,0,0.9);
	polygon(0,3,7,4);
	
	glColor3f(1,0.5,0);
	polygon(1,2,6,5);
	
	glColor3f(0.5,1,1);
	polygon(0,1,2,3);
	
	glColor3f(1,0.5,1);
	polygon(4,5,6,7);
}

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	gluLookAt(view[0], view[1], view[2],0,0,0,0,1,0);
	cube();
	
	glutSwapBuffers();
	glFlush();
	
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);
		glFrustum(-2,2,-2,2,2,20);
	glMatrixMode(GL_MODELVIEW);
}

void mykey(unsigned char ch, int x, int y)
{
	if(ch == 'x') view[0]-=1;
	if(ch == 'X') view[0]+=1;
	
	if(ch == 'y') view[1]-=1;
	if(ch == 'Y') view[1]+=1;
	
	if(ch == 'z') view[2]-=1;
	if(ch == 'Z') view[2]+=1;
	
	glutPostRedisplay();
}

int main(int argc, char **argv)
{

	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("1CR20CS155 CAMERA CUBE");
	
	myinit();
	glutDisplayFunc(display);
	
	glutKeyboardFunc(mykey);
	glEnable(GL_DEPTH_TEST);


	glutMainLoop();
	return 0;
}
