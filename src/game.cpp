/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:24:25 by emsimang          #+#    #+#             */
/*   Updated: 2017/06/21 11:34:47 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"

int gridX, gridY;

//line width
float colorInt = 1.0;

//random colors
float randR = 1.0, randG = 1.0, randB = 1.0;

//animate color
float snkR = 0.8, snkG = 0.8, snkB = 0.8;

//snake length variable
int snake_length = 4;

//food var to tell if food needs to reset
bool food = true;;
//variables for food coordinate
int foodX, foodY;

//life of the snake
int life = 1;
//snake direction
short snake_direction = RIGHT;

//snake blocks position
int snakeX[MAX_LEN] = {20, 20, 20, 20};
int snakeY[MAX_LEN] = {20, 19, 18, 17};

void drawFood()
{
	if (food)
	{
		random(foodX, foodY);
		for (int i = 0; i < snake_length; i++)
		{
			if (snakeX[i] == foodX && snakeY[i] == foodY)
				drawFood();
		}
	}
	food = false;
	randColor(randR, randG, randB);
	glColor3f(randR, randG, randB);
	glRectf(foodX, foodY, foodX + 1, foodY + 1);
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

void drawSnake()
{
     for (int i = snake_length - 1; i > 0; i--)
     {
	     snakeX[i] = snakeX[i - 1];
	     snakeY[i] = snakeY[i - 1];
     }
    //change snake direction
    if (snake_direction == RIGHT)
        snakeX[0]++;
    else if (snake_direction == LEFT)
        snakeX[0]--;
    else if (snake_direction == UP)
        snakeY[0]++;
    else if (snake_direction == DOWN)
        snakeY[0]--;
    //collison
    if (snakeX[0] == 0 || snakeY[0] == 0 || snakeX[0] == (gridX - 1) || snakeY[0] == (gridY - 1))
    {
	life -= 1;
	if (!life)
		gameOver = true;
        snakeX[0] = 20;
        snakeY[0] = 20;
	snake_length = 4;
        snake_direction = RIGHT;
    }
    //draws the entire snake body
    for (int i = 0; i < snake_length - 1; i++)
    {
	    if (i == 0)
		    glColor3f(1.0, 0.0, 0.0);
	    else
		    glColor3f(snkR, snkG, snkB);
	    glRectd(snakeX[i], snakeY[i], snakeX[i] + 1, snakeY[i] + 1);
	    //self collision detected;
	    if (i != 0 && ((snakeX[0] == snakeX[i]) && (snakeY[0] == snakeY[i])))
	    {
		    life -= 1;
		    if (!life)
			    gameOver = true;
		    snakeX[0] = 20;
		    snakeY[0] = 20;
		    snake_length = 4;
		    snake_direction = RIGHT;
	    }
    }
    //snake colliding with food
    if (snakeX[0] == foodX && snakeY[0] == foodY)
    {
	    food = true;
	    if (snake_length < 60)
		    snake_length += 1;
	    if (colorInt != 0.0)
		    colorInt -= 0.09;
	    snkR = randR;
	    snkG = randG;
	    snkB = randB;
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
        glColor3f(colorInt, colorInt, colorInt);
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
