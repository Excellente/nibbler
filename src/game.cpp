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

float gridInt = 0.618;

ILibrary *instance;

void glIntit(int *argc, char **argv)
{
	::glutInit(argc, argv);
}

void display()
{
	::glutDisplayFunc(display_callback);
	::glutReshapeFunc(reshape_callback);
}

void windowInit()
{
	::glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	::glutInitWindowSize(800, 800);
	::glutCreateWindow("SNAKE");
}

void	ILibrary::display_callback()
{
	//updates or resets the color buffer
	::glClear(GL_COLOR_BUFFER_BIT);
	//draw a grid before swapping display buffers.
	// drawGrid();
	// drawSnake();
	// drawFood();
	// glutSwapBuffers();
	// if (gameOver)
	// {

	// 	print(20, 20, 0, gOver);
	// 	EXIT
	// }
}

void ILibrary::initialize(int *argc, char **argv)
{
	::instance = this;
	::glutInit(argc, argv);
	::windowInit();
	::display();
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
	glBegin(GL_LINE_LOOP);

	//draws a vertes at a specified point
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);

	//ends the drawing of a particular geometric object
	glEnd();
}
