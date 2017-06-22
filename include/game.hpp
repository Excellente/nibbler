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

//constants to check for the snake direction
# define UP 1
# define RIGHT 2
# define DOWN -1
# define LEFT -2

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
# include <unistd.h>
# include <string.h>

extern int life;
extern bool gameOver;
extern int snake_speed;
extern short snake_direction;

typedef		struct	s_snakeColor
{
	float snkR;
	float snkG;
	float snkB;
}					t_sColor;

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

void drawGrid();
void drawSnake();
void drawFood();
void random(int &x, int &y);
void drawUnit(int x, int y);
void initGrid(int x, int y);
void randColor(float &rr, float &rg, float &rb);

#endif
