/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:33:57 by emsimang          #+#    #+#             */
/*   Updated: 2017/06/21 11:34:01 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.hpp"
# define COLUMN 40
# define ROW 40
# define FPS 10

bool gameOver = false;

void	init();
void	display_callback();
void	timer_callback(int val);
void	reshape_callback(int w, int h);
void	keyboard_callback(int key, int mouseX, int mouseY);

int main(int argc, char **argv)
{
	//initialize glut, before using the framework
	glutInit(&argc, argv);

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
	glutSpecialFunc(keyboard_callback);
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

void	timer_callback(int)
{
	//calls the display function everytime
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer_callback, 0);
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
	drawSnake();
	drawFood();
	glutSwapBuffers();
	if (gameOver)
		exit(0);
}

void	keyboard_callback(int key, int, int)
{
	switch (key)
	{
		case GLUT_KEY_UP:
			if (snake_direction != DOWN)
				snake_direction = UP;
			break;
		case GLUT_KEY_DOWN:
			if (snake_direction != UP)
				snake_direction = DOWN;
			break;
		case GLUT_KEY_RIGHT:
			if (snake_direction != LEFT)
				snake_direction = RIGHT;
			break;
		case GLUT_KEY_LEFT:
			if (snake_direction != RIGHT)
				snake_direction = LEFT;
			break;
		case 27:
			exit(0);
			break;
	}
}
