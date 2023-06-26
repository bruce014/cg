#include<GL/glut.h>
#include<stdio.h>

float light_pos[] = {2,2,2,1};
float ambient[] = {1,1,1,1};

void align()
{
	glRotated(50,0,1,0);
	glRotated(10,-1,0,0);
	glRotated(10,0,0,-1);
}

void obj(float tx,float ty,float tz,float sx,float sy,float sz)
{
	align();
	glTranslatef(tx,ty,tz);
	glScalef(sx,sy,sz);
	glutSolidCube(1);
	glLoadIdentity();
}
void display()
{
	//glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	obj(0,0,0.5,1,1,0.04); //wall
	obj(-0.5,0,0,0.04,1,1); //wall
	obj(0,-0.5,0,1,0.04,1);//floor
	
	//legs
	obj(0,-0.3,0,0.02,0.2,0.02);
	obj(0.3,-0.3,0,0.02,0.2,0.02);
	obj(0.3,-0.3,-0.3,0.02,0.2,0.02);
	obj(0,-0.3,-0.3,0.02,0.2,0.02);
	
	obj(0,-0.2,0,0.7,0.04,0.7);//table top
	
	glPushMatrix();
	align();
	//glTranslatef(-0.17,-0.09,-0.5);
	glTranslatef(0.1,-0.1,-0.1);
	glutSolidTeapot(0.09);
	
	glPopMatrix();
	
	glFlush();
	
}


int main(int argc, char **argv)
{


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	
	glutInitWindowSize(700,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("1CR20CS155 Tea Pot");

	glutDisplayFunc(display);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	glLightfv(GL_LIGHT0,GL_POSITION, light_pos);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);

	glEnable(GL_DEPTH_TEST);


	glutMainLoop();
	return 0;
}
