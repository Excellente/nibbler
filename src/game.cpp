/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:24:25 by emsimang          #+#    #+#             */
/*   Updated: 2017/06/22 12:12:33 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

Snake s = Snake();
ILibrary *instance;
float gridInt = 0.618;

int gridY = ROW;
int	gridX = COLUMN;
bool gpause = false;
bool LIB1, LIB2, LIB3;
bool gameOver = false;

void display()
{
	::glutDisplayFunc(display_callback);
	::glutReshapeFunc(reshape_callback);
	::glutTimerFunc(0, timer_callback, 0);
}

void keyboard()
{
	::glutKeyboardFunc(keyboard_normal);
	::glutSpecialFunc(keyboard_special);
}

void windowInit()
{
	::glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	::glutInitWindowSize(800, 800);
	::glutCreateWindow("SNAKE");
}

void	init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	initGrid(COLUMN, ROW);
}

void	eventLoop()
{
	::glutMainLoop();
}

void ILibrary::initialize(int *argc, char **argv)
{
	::instance = this;
	::glutInit(argc, argv);
	::windowInit();
	::display();
	::keyboard();
	::init();
	::eventLoop();
}

void	keyboard_normal(unsigned char k, int x, int y)
{
	switch (k)
	{
		case 80:
		case 112:
			if (gpause == true)
				gpause = false;
			else
				gpause = true;
			break;
		case 27:
			exit(0);
			break;
		case 49:
			LIB1 = true;
			LIB2 = false;
			LIB3 = false;
			break;
		case 50:
			LIB2 = true;
			LIB1 = false;
			LIB3 = false;
			break;
		case 51:
			LIB3 = true;
			LIB2 = false;
			LIB1 = false;
			break;
		default:
			printf("key: %d not handled\n", k);
			break;		
	}
}

void	display_callback()
{
	//updates or resets the color buffer
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid(s.getScore());
	s.updateSnake();
	s.getFood().drawFood();
	glutSwapBuffers();
	if (gameOver)
		EXIT;
}

void initGrid(int x, int y)
{
	gridX = x;
	gridY = y;
}

void print(int x, int y,int z, char *string)
{
	int len = (int) strlen(string);

	glRasterPos2f(x,y);
	for (int i = 0; i < len; i++) 
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);

}


//draws an entire grid
void drawGrid(t_score sc)
{
	char high[10] = {'\0'};
	char score[10] = {'\0'};
	sprintf(high, "%d", sc.high_score);
	sprintf(score, "%d", sc.current_score);
	for (int i = 0; i < gridX; i++)
	{
		for (int j = 0; j < gridY - 2; j++)
			drawUnit(i, j);
	}
	glColor3f(0.3, 0.5, 0.2);
	print(1, 39, -10, "press p to pause game");
	glColor3f(1.0, 1.0, 1.0);
	print(12, 39, 0, "score");
	glColor3f(1.0, 0.6, 0.0);
	print(15, 39, 0, score);
	glColor3f(1.0, 1.0, 1.0);
	print(18, 39, 0, "high score");
	glColor3f(1.0, 0.6, 0.0);
	print(23, 39, 0, high);
}

void	timer_callback(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / s.getSpeed(), timer_callback, 0);
}

void	reshape_callback(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMN, 0.0, ROW, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

//draws single square unit given a point
void drawUnit(int x, int y)
{
	//condition to draw border differently
	if ((x == 0 || y == 0) || (x == gridX - 1 || y == gridY - 3))
	{
		glLineWidth(3.0);
		glColor3f(1.0, 0.5, 0.2);
	}
	else
	{
		glLineWidth(1.0);
		glColor3f(gridInt, gridInt, gridInt);
	}

	//specifiy what geometric object to draw
	//gl_line_loop draws a connected object. 
	::glBegin(GL_LINE_LOOP);

	//draws a vertes at a specified point
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);

	//ends the drawing of a particular geometric object
	glEnd();
}

void	keyboard_special(int key, int, int)
{
	if (!gpause)
	switch (key)
	{
		case GLUT_KEY_UP:
			if (s.getDirection() != DOWN)
				s.setDirection(UP);
			break;
		case GLUT_KEY_DOWN:
			if (s.getDirection() != UP)
				s.setDirection(DOWN);
			break;
		case GLUT_KEY_RIGHT:
			if (s.getDirection() != LEFT)
				s.setDirection(RIGHT);
			break;
		case GLUT_KEY_LEFT:
			if (s.getDirection() != RIGHT)
				s.setDirection(LEFT);
			break;
		case GLUT_KEY_ESC:
			exit(0);
			break;
		defualt:
			printf("pressed key: %d\n", key);
			break;
	}	
}