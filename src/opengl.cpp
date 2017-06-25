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

Snake s = Snake();
int gridY = ROW;
int	gridX = COLUMN;
bool gpause = false;
bool gameOver = false;

int main(int argc, char **argv)
{
	ILibrary *iwin = new ILibrary();
	iwin->initialize(&argc, argv);
	//called whenever the window get created, window is resized or moved.
	// glutReshapeFunc(reshape_callback);

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
	glutPostRedisplay();
	glutTimerFunc(1000 / s.getSpeed(), timer_callback, 0);
}

void	display_callback()
{
	//updates or resets the color buffer
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid(s.getScore());
	s.updateSnake();
	s.getFood().drawFood();
	glutSwapBuffers();
	if (gameOver)
		EXIT;
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
