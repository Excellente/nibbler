/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:33:57 by emsimang          #+#    #+#             */
/*   Updated: 2017/06/22 11:58:27 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"
# define COLUMN 40
# define ROW 40

bool gpause = false;
bool gameOver = false;
char *gOver = "Game Over!";
void	init();
void	display_callback();
void	timer_callback(int val);
void	reshape_callback(int w, int h);
void	keyboard_normal(unsigned char key, int x, int y);
void	keyboard_special(int key, int mouseX, int mouseY);
Snake s = Snake();

int main(int argc, char **argv)
{
	IDisplay *swin = new IDisplay();
	Snake s = Snake();
	// initialize glut, before using the framework
	glutInit(&argc, argv);
	//swin->initialize(&argc, argv);

	//using double buffer so as to buffer updates on the windows
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutCreateWindow("SNAKE");
	glutDisplayFunc(display_callback);
	//called whenever the window get created, window is resized or moved.
	glutReshapeFunc(reshape_callback);

	//registers a callback that
	//executes everytime x amount of mses has passed
	glutTimerFunc(0, timer_callback, 0);

	//keyboard callback, to capture key presses
	glutKeyboardFunc(keyboard_normal);
	glutSpecialFunc(keyboard_special);
	init();
	//calls all the necessary callbacks
	glutMainLoop();
	return (0);
}

void	init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	initGrid(COLUMN, ROW);
}

void	keyboard_normal(unsigned char k, int x, int y)
{
	switch (k)
	{
		case 80:
		case 112:
			printf("pressed key: %d :: bool %d\n", k, gpause);
			if (gpause == true)
				gpause = false;
			else
				gpause = true;
			break;
		case 27:
			exit(0);
			break;
	}
}

void	timer_callback(int)
{
	//calls the display function everytime
//	if (!gpause)
//	{
	glutPostRedisplay();
	glutTimerFunc(1000 / s.getSpeed(), timer_callback, 0);
//	}
}

void	reshape_callback(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMN, 0.0, ROW, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void	display_callback()
{
	//updates or resets the color buffer
	glClear(GL_COLOR_BUFFER_BIT);
	//draw a grid before swapping display buffers.
	drawGrid();
	s.updateSnake();
	drawFood();
	glutSwapBuffers();
	if (gameOver)
	{

		printf("%s\n", gOver);
		EXIT
	}
}

void	keyboard_special(int key, int, int)
{
	if (!gpause)
	switch (key)
	{
		case GLUT_KEY_UP:
			if (s.getDirection() != DOWN)
				s.setDirection(UP);
			break;
		case GLUT_KEY_DOWN:
			if (s.getDirection() != UP)
				s.setDirection(DOWN);
			break;
		case GLUT_KEY_RIGHT:
			if (s.getDirection() != LEFT)
				s.setDirection(RIGHT);
			break;
		case GLUT_KEY_LEFT:
			if (s.getDirection() != RIGHT)
				s.setDirection(LEFT);
			break;
		case GLUT_KEY_ESC:
			exit(0);
			break;
		defualt:
			printf("pressed key: %d\n", key);
			break;
	}	
}
