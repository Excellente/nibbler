/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:10:24 by emsimang          #+#    #+#             */
/*   Updated: 2017/06/19 15:33:37 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

int main()
{
	//initscr() is used to initialize the ncurses data structures and
	//to read the proper terminfo file. Memory for and will be allocated.
	initscr();
	
	//writes to memory
	printw("Hey in the world");

	//writes directly to the screen.
	refresh();

	//program pause;
	getch();

	//deallocate the memory allocated by initscr()
	endwin();
	return (0);
}
