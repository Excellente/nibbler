#include "snake.hpp"

bool food = true;
int foodX, foodY;
float randR = 1.0, randG = 1.0, randB = 1.0;

Snake::~Snake(){
}

Snake::Snake()
{
	this->_life = 2;
	this->_speed = 2;
	this->_length = 4;
	this->_food = Food();
	this->_color.snkR = 0.8;
	this->_color.snkG = 0.8;
	this->_color.snkB = 0.8;
	this->_direction = RIGHT;
	this->_score.high_score = 0;
	this->_score.current_score = 0;
	this->reset();
}

int Snake::getDirection(){
	return (this->_direction);
}

int Snake::getSpeed(){
	return (this->_speed);
}

t_score Snake::getScore(){
	return (this->_score);
}

Food Snake::getFood(){
	return (this->_food);
}

s_color Snake::getColor(){
	return (this->_color);
}

void Snake::setHighScore(int hs){
	this->_score.high_score = hs;
}

void Snake::setScore(int s){
	this->_score.current_score = s;
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

void Snake::reset()
{
	for (int i = 0; i < 4; i++)
		this->_xCoord[i] = 20;
	for (int j = 0, i = 20; i > 16; i--, j++)
		this->_yCoord[j] = i;
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
	this->reset();	
	this->_direction = RIGHT;
	this->_score.current_score = 0;
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

	for (int i = 0; i < this->_length; i++)
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
	|| this->_xCoord[0] == (gridX - 2)
	|| this->_yCoord[0] == (gridY - 3))
		this->collision();
	if (this->_xCoord[0] == foodX && this->_yCoord[0] == foodY)
	{
		food = true;
		this->_score.current_score += 4;
		this->_speed += 1;
		if (this->_score.high_score < this->_score.current_score)
			this->setHighScore(this->_score.current_score);
		if (this->_length < 60)
			this->_length += 1;
		if (gridInt != 0.0)
			gridInt -= 0.09;
		this->setColor(randR, randG, randB);
	}
    //////////////////////////////////////debugging///////////////////////////////////
	printf("____Debugging____\n");
	printf("score = %d\nsnake_length = %d\nsnake_direction = %d\nsnake_speed = %d\n",
		   this->_score.current_score, this->_length, this->_direction, this->_speed);
    //////////////////////////////////////debugging///////////////////////////////////
}

Food::~Food(){
}

Food::Food(Food const &s)
{
	this->_resetPos = s._resetPos;
	this->_color.snkR = s._color.snkR;
	this->_color.snkR = s._color.snkR;
	this->_color.snkR = s._color.snkR;
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
	int maxY = gridY - 3;
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