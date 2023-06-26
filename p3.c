#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

float triangle[3][3] = {{200,250,300}, {200,300,200}, {1,1,1}};
float rotate[3][3] = {{0},{0},{0}};
float result[3][3] = {{0},{0},{0}};
float theta, h, k;
int flag = 0;

void create_triangle(float a[3][3])
{
	glBegin(GL_TRIANGLES);
		glVertex2f(a[0][0], a[1][0]);
		glVertex2f(a[0][1], a[1][1]);
		glVertex2f(a[0][2], a[1][2]);
	glEnd();
}

void multiply()
{
	int i,j,k;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			result[i][j] = 0;
			for(k=0;k<3;k++)
			{
				result[i][j] += rotate[i][k] * triangle[k][j];
			}
		}
	}
}

void rrotate(float m, float n)
{
	rotate[0][0] = cos(theta);
	rotate[0][1] = -sin(theta);
	rotate[0][2] = m;
	
	rotate[1][0] = sin(theta);
	rotate[1][1] = cos(theta);
	rotate[1][2] = n;
	
	rotate[2][0] = 0;
	rotate[2][1] = 0;
	rotate[2][2] = 1;
	
	multiply();
}

void display()
{
	float p,q;
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1,0,0);
	create_triangle(triangle);

	if(flag == 1)
	{
	glColor3f(0,1,0);
	rrotate(0,0);
	create_triangle(result);	
	}
	if(flag == 2)
	{
	p = h*(1-cos(theta)) + k*(sin(theta));
	q = k*(1-cos(theta)) - h*(sin(theta));
	
	glColor3f(0,1,1);
	rrotate(p,q);
	create_triangle(result);	
	}
	
	if(flag == 3)
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
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);
		gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	printf("Enter rotation angle\n");
	scanf("%f", &theta);
	theta = theta* (3.14/180);
	
	printf("Enter fixed point\n");
	scanf("%f %f", &h, &k);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("1CR20CS155 TRIANGLE ROTATION");
	
	myinit();
	glutDisplayFunc(display);
	
	glutCreateMenu(menu);
	glutAddMenuEntry("Rotation : Origin", 1);
	glutAddMenuEntry("Rotation : Fixed Point", 2);
	glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
	return 0;
}

























