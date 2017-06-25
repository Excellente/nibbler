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

# include "snake.hpp"

class ILibrary
{
	private:
		bool gameOver;
		static ILibrary *instance;
	
	public:
		void drawGrid();
		void drawFood();
		void drawSnake();
		void windowInit();
		static void display_callback();
;		void initialize(int *argc, char **argv);

};

void drawFood();
void drawGrid(t_score s);
void random(int &x, int &y);
void drawUnit(int x, int y);
void initGrid(int x, int y);
void randColor(float &rr, float &rg, float &rb);

void	init();
void	display_callback();
void	timer_callback(int val);
void	reshape_callback(int w, int h);
void	keyboard_normal(unsigned char key, int x, int y);
void	keyboard_special(int key, int mouseX, int mouseY);

#endif
