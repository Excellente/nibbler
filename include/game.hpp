/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:24:39 by emsimang          #+#    #+#             */
/*   Updated: 2017/06/21 11:34:05 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

//constants to check for the snake direction
# define UP 1
# define RIGHT 2
# define DOWN -1
# define LEFT -2

# define MAX_LEN 60

#ifdef __APPLE__

#include <OpenGL/glu.h>
# include <GLUT/glut.h>
# include <OpenGl/gl.h>
#else
# include <GL/glu.h>
# include <GL/glut.h>
# include <GL/gl.h>
#endif

# include <ctime>
# include <unistd.h>

extern int life;
extern bool gameOver;
extern short snake_direction;

void drawGrid();
void drawSnake();
void drawFood();
void random(int &x, int &y);
void drawUnit(int x, int y);
void initGrid(int x, int y);
void randColor(float &rr, float &rg, float &rb);

#endif
