#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "glut.h"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGTH 640
#define WINDOW_POSITION_X 100
#define WINDOW_POSITION_Y 100

#define POINTA_X 0.0f
#define POINTA_Y 1.0f
#define POINTB_X -1.0f
#define POINTB_Y -1.0f
#define POINTC_X 1.0f
#define POINTC_Y -1.0f

#define POINT0_X 0.25f
#define POINT0_Y 0.25f

float triangle_points[3][2];

#define NUM_OF_POINTS 5000
float vertices[NUM_OF_POINTS][2];

void myDisplay(void);
void init(int *argc, char *argv[]);
void generate_all_points(float vertices[][2], int num);
void displayTriangle(float points[3][2]);
void displayPoints(float points[3][2], int num);

int main(int argc, char *argv[])
{
	init(&argc, argv);
	
	glutCreateWindow("第一个OpenGL程序");
	
	glutDisplayFunc(&myDisplay);

	generate_all_points(vertices, NUM_OF_POINTS);

	glutMainLoop();

	return 0;
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	//绘制初始三角形
	displayTriangle(triangle_points);

	//绘制所有随机点
	displayPoints(vertices, NUM_OF_POINTS);

	glFlush();
}
void init(int *argc, char *argv[])
{
	glutInit(argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGTH);
	glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

	srand(time(0));
}
void generate_all_points(float vertices[][2], int num)
{
	//三角形的三个点
	triangle_points[0][0] = POINTA_X;
	triangle_points[0][1] = POINTA_Y;
	triangle_points[1][0] = POINTB_X;
	triangle_points[1][1] = POINTB_Y;
	triangle_points[2][0] = POINTC_X;
	triangle_points[2][1] = POINTC_Y;
	
	//初始随机点P0
	vertices[0][0] = POINT0_X;
	vertices[0][1] = POINT0_Y;

	//剩下的随机点
	for(int i = 1; i < num; i++)
	{
		int rand_num = rand()%3;
		vertices[i][0] = (vertices[i-1][0] + triangle_points[rand_num][0]) / 2;
		vertices[i][1] = (vertices[i-1][1] + triangle_points[rand_num][1]) / 2;
	}

}

void displayTriangle(float points[3][2])
{
	glBegin(GL_LINE_STRIP);
	glVertex2f(triangle_points[0][0], triangle_points[0][1]);
	glVertex2f(triangle_points[1][0], triangle_points[1][1]);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(triangle_points[1][0], triangle_points[1][1]);
	glVertex2f(triangle_points[2][0], triangle_points[2][1]);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(triangle_points[2][0], triangle_points[2][1]);
	glVertex2f(triangle_points[0][0], triangle_points[0][1]);
	glEnd();
}
void displayPoints(float points[3][2], int num)
{
	glBegin(GL_POINTS);
	for(int i = 0; i < num; i++)glVertex2f(triangle_points[i][0], triangle_points[i][1]);
	glEnd();
}