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

/*
 ** object oriented code begin
 */

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
	::glutDisplayFunc(IDisplay::display_callback);
}

/*
 ** object oriented code end
 */

//line width
float gridInt = 1.0;

//random colors
float randR = 1.0, randG = 1.0, randB = 1.0;

//food var to tell if food needs to be reset
bool food = true;
//variables for food coordinate
int foodX, foodY;

//////////////////////////////////////////food code start//////////////////////////////////////////////////////////

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
	{
		this->setPos(foodX, foodY);
		/*for (int i = 0; i < Snake::getLength(); i++)
		  {
		  if (snakeX[i] == foodX && snakeY[i] == foodY)
		  {
		  drawFood();
		  return;
		  }
		  }*/
	}
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

//////////////////////////////////////////snake code start/////////////////////////////////////////////////////////

Snake::~Snake(){
}

Snake::Snake()
{
	this->_life = 2;
	this->_length = 4;
	this->_speed = 2;
	this->_food = Food();
	this->_color.snkR = 0.8;
	this->_color.snkG = 0.8;
	this->_color.snkB = 0.8;
	this->_direction = RIGHT;
	for (int i = 0; i < 4; i++)
		this->_xCoord[i] = 20;
	for (int j = 0, i = 20; i > 16; i--, j++)
		this->_yCoord[j] = i;
}

int Snake::getDirection(){
	return (this->_direction);
}

int Snake::getSpeed(){
	return (this->_speed);
}

Food Snake::getFood(){
	return (this->_food);
}

s_color Snake::getColor(){
	return (this->_color);
}

void Snake::setSpeed(int s){
	this->_speed = s;
}

void Snake::setDirection(int d){
	this->_direction = d;
}

void Snake::setColor(float r, float g, float b)
{
	this->_color.snkR = r;
	this->_color.snkG = g;
	this->_color.snkB = b;
}

void Snake::collision()
{

	gridInt  = 1.0;
	this->_life -= 1;
	if (!this->_life)
	{
		this->_isAlive = false;
		gameOver = true;
	}
	this->_speed = 2;
	this->_length = 4;
	this->_xCoord[0] = 20;
	this->_yCoord[0] = 20;
	this->_direction = RIGHT;
}

void Snake::moveBody()
{

	for (int i = this->_length - 1; i > 0; i--)
	{
		this->_xCoord[i] = this->_xCoord[i - 1];
		this->_yCoord[i] = this->_yCoord[i - 1];
	}
}

void Snake::moveHead()
{
	if (!gpause)
	{
		if (this->_direction == RIGHT)
			this->_xCoord[0]++;
		else if (this->_direction == LEFT)
			this->_xCoord[0]--;
		else if (this->_direction == UP)
			this->_yCoord[0]++;
		else if (this->_direction == DOWN)
			this->_yCoord[0]--;
	}
}

void Snake::drawSnake()
{

	for (int i = 0; i < this->_length - 1; i++)
	{
		if (i == 0 || (((this->_xCoord[i] == this->_xCoord[0])
		&& (this->_yCoord[i] == this->_yCoord[0])) && gpause))
			glColor3f(1.0, 0.0, 0.0);
		else
			glColor3f(this->_color.snkR, this->_color.snkG, this->_color.snkB);
		glRectd(this->_xCoord[i], this->_yCoord[i], this->_xCoord[i] + 1, this->_yCoord[i] + 1);
		if (i != 0 && ((this->_xCoord[0] == this->_xCoord[i])
					&& (this->_yCoord[0] == this->_yCoord[i])) && !gpause)
			this->collision();
	}
}

void Snake::updateSnake()
{
	this->moveBody();
	this->moveHead();
	this->drawSnake();
	if (this->_xCoord[0] == 0 || this->_yCoord[0] == 0 
	|| this->_xCoord[0] == (gridX - 1)
	|| this->_yCoord[0] == (gridY - 1))
		this->collision();
	if (this->_xCoord[0] == foodX && this->_yCoord[0] == foodY)
	{
		food = true;
		this->_speed += 1;
		if (this->_length < 60)
			this->_length += 1;
		if (gridInt != 0.0)
			gridInt -= 0.09;
		this->setColor(randR, randG, randB);
	}
	printf("____Debugging____\n");
	printf("snake_length = %d\nsnake_direction = %d\nsnake_speed = %d\n",
			this->_length, this->_direction, this->_speed);
}


void random(int &x, int &y)
{
	int maxX = gridX - 2;
	int maxY = gridY - 2;
	int min = 1;

	srand(time(NULL));
	x = min + rand() % (maxX - min);
	y = min + rand() % (maxY - min);
}

void randColor(float &rr, float &rg, float &rb)
{
	int max = 1.0;
	int min = 0.0;

	srand(time(NULL));
	rr = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	rg = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	rb = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

/*
 **snake object code end
 */

//initialiazes the grid dimensions
void initGrid(int x, int y)
{
	gridX = x;
	gridY = y;
}

//draws an entire grid
void drawGrid()
{
	for (int i = 0; i < gridX; i++)
	{
		for (int j = 0; j < gridY; j++)
			drawUnit(i, j);
	}
}

//draws single square unit given a point
void drawUnit(int x, int y)
{
	//condition to draw border differently
	if ((x == 0 || y == 0) || (x == gridX - 1 || y == gridY - 1))
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
