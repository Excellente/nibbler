/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:24:39 by emsimang          #+#    #+#             */
/*   Updated: 2017/06/22 11:56:46 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

//direction constants
# define UP 1
# define RIGHT 2
# define DOWN -1
# define LEFT -2

# define GLUT_KEY_ESC 27
# define GLUT_KEY_LCA 97

# define MAX_LEN 60
# define MAX_SPEED 50

#ifdef __APPLE__
	# define EXIT _exit(0);
	# include <iostream>
	# include <OpenGL/glu.h>
	# include <GLUT/glut.h>
	# include <OpenGl/gl.h>
#else
	# define EXIT exit(0);
	# include <GL/glu.h>
	# include <GL/glut.h>
	# include <GL/gl.h>
#endif

# include <ctime>
# include <vector>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

extern bool gpause;
extern bool gameOver;

typedef		struct	s_snakeColor
{
	float snkR;
	float snkG;
	float snkB;
}					t_sColor;

typedef	struct	s_color
{
	float snkR;
	float snkG;
	float snkB;
}		s_color;

class IDisplay
{
	private:
		bool gameOver;
		static IDisplay *instance;
	
	public:
		void drawGrid();
		void drawFood();
		void drawSnake();
		void windowInit();
		static void display_callback();
;		void initialize(int *argc, char **argv);

};

class Snake
{
	private:
		short	_life;
		int	_speed;
		int	_length;
		bool	_isAlive;
		int	_direction;
		int	_xCoord[MAX_LEN];
		int	_yCoord[MAX_LEN];
		s_color _color;
	public:
		Snake();
		~Snake();
		void	moveHead();
		void	moveBody();
		int	getSpeed();
		void	collision();
		void	drawSnake();
		void	updateSnake();
		int	getDirection();
		void	setSpeed(int s);
		void	setDirection(int d);
		s_color	getColor();
		void	setColor(float r, float g, float b);
};

void drawGrid();
//void drawSnake();
void drawFood();
void random(int &x, int &y);
void drawUnit(int x, int y);
void initGrid(int x, int y);
void randColor(float &rr, float &rg, float &rb);

#endif
