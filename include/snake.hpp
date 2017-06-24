#ifndef SNAKE_H
# define SNAKE_H

typedef		struct	s_color
{
	float snkR;
	float snkG;
	float snkB;
}					o_color;

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

	public:
		Snake();
		~Snake();
        Food    getFood();
		s_color	getColor();
		void	moveHead();
		void	moveBody();
		int     getSpeed();
		void	collision();
		void	drawSnake();
		void	updateSnake();
		int     getDirection();
		void	setSpeed(int s);
		void	setDirection(int d);
		void	setColor(float r, float g, float b);
};

#endif