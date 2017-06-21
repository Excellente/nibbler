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

int animationVar = 1;
//snake blocks position
int snakeX = 20, snakeY = 20;

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
    //draws a rectangle
	glRectd(snakeX, snakeY, 1, 1);
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
        glColor3f(0.5, 0.5, 0.5);
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