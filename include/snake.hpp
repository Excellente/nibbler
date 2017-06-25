#ifndef SNAKE_H
# define SNAKE_H

# define MAX_LEN 60
# define MAX_SPEED 50

//direction constants
# define UP 1
# define RIGHT 2
# define DOWN -1
# define LEFT -2

# define GLUT_KEY_ESC 27
# define GLUT_KEY_LCA 97

#ifdef __APPLE__
	# define EXIT _exit(0)
	# include <iostream>
	# include <OpenGL/glu.h>
	# include <GLUT/glut.h>
	# include <OpenGl/gl.h>
#else
	# define EXIT exit(0)
	# include <GL/glu.h>
	# include <GL/glut.h>
	# include <GL/gl.h>
#endif

# include <ctime>
# include <vector>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

extern bool food;
extern float gridInt;
extern int foodX, foodY;
extern int gridX, gridY;
extern float randR, randG, randB;
extern bool gameOver, gpause;

typedef	struct	s_color
{
	float snkR;
	float snkG;
	float snkB;
}					o_color;

typedef	struct	s_score
{
	int high_score;
	int current_score;
}				t_score;

class Food
{
	private:
		int		_xCoord;
		int		_yCoord;
		bool	_resetPos;
		o_color	_color;

	public:
		Food();
		~Food();
        float   getRed();
        float   getBlue();
        float   getGreen();
		void    drawFood();
		void    setColor();
        int     getXcoord();
        int     getYcoord();
        void    setResetPos(bool b);
		void    setPos(int &x, int &y);
		void    setColor(float &rr, float &rg, float &rb);
};

class Snake
{
	private:
		short   _life;
		int     _speed;
		int     _length;
		bool    _isAlive;
		int     _direction;
		int     _xCoord[MAX_LEN];
		int     _yCoord[MAX_LEN];
        Food    _food;
		o_color _color;
		t_score _score;

	public:
		Snake();
		~Snake();
		void	reset();
        Food    getFood();
		s_color	getColor();
		void	moveHead();
		void	moveBody();
		int     getSpeed();
		t_score	getScore();
		void	collision();
		void	drawSnake();
		void	updateSnake();
		int     getDirection();
		void	setSpeed(int s);
		void	setScore(int s);
		void	setDirection(int d);
		void	setHighScore(int hs);
		void	setColor(float r, float g, float b);
};

#endif