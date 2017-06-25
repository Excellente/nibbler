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

bool food = true;
int foodX, foodY;
float gridInt = 0.618;
float randR = 1.0, randG = 1.0, randB = 1.0;

IDisplay *instance;

void glIntit(int *argc, char **argv)
{
	::glutInit(argc, argv);
}

/*void windowInit()
  {
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(800, 800);
  glutCreateWindow("SNAKE");
  glutDisplayFunc(display_callback);
  }*/

void	IDisplay::display_callback()
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

void IDisplay::initialize(int *argc, char **argv)
{
	::instance = this;
	::glutInit(argc, argv);
	::glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	::glutInitWindowSize(800, 800);
	::glutCreateWindow("SNAKE");
	// ::glutDisplayFunc(IDisplay::display_callback);
}

Food::~Food(){
}

Food::Food()
{
	this->_resetPos = false;
	this->_color.snkR = 1.0;
	this->_color.snkG = 1.0;
	this->_color.snkB = 1.0;
	this->setPos(this->_xCoord, this->_yCoord);
}

int Food::getXcoord(){
	return (this->_xCoord);
}

int Food::getYcoord(){
	return (this->_yCoord);
}

float Food::getRed(){
	return (this->_color.snkR);
}

float Food::getGreen(){
	return (this->_color.snkG);	
}

float Food::getBlue(){
	return (this->_color.snkB);	
}

void Food::drawFood()
{
	if (food)
		this->setPos(foodX, foodY);
	food = false;
	this->setColor(randR, randG, randB);
	glColor3f(randR, randG, randB);
	glRectf(foodX, foodY, foodX + 1, foodY + 1);
}

void Food::setPos(int &x, int &y)
{
	int maxX = gridX - 2;
	int maxY = gridY - 2;
	int min = 1;

	srand(time(NULL));
	x = min + rand() % (maxX - min);
	y = min + rand() % (maxY - min);
}

void Food::setResetPos(bool b){
	this->_resetPos = b;
}

void Food::setColor(float &rr, float &rg, float &rb)
{
	int max = 1.0;
	int min = 0.0;

	srand(time(NULL));
	rr = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	rg = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	rb = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

//////////////////////////////////////////food code end////////////////////////////////////////////////////////////

//initialiazes the grid dimensions
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
