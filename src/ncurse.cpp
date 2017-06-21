/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:10:24 by emsimang          #+#    #+#             */
/*   Updated: 2017/06/19 16:51:54 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h>

int main()
{
	//initscr() is used to initialize the ncurses data structures and
	//to read the proper terminfo file. Memory for and will be allocated.
	initscr();

	int i = 0;
	while (1)
	{
		//moves the curser and prints at that position.
		if ((i % 2) == 0)
		{
			mvprintw(i - 2, 19, " ");
			mvprintw(i, 19, "o");
			refresh();
		}
		if (i == 59)
		{
			mvprintw(i - 2, 19, " ");
			i = 0;
		}
		usleep(9999);
		i++;
		//writes directly to the screen.

		//program pause;
		//getch();
	}
	//deallocate the memory allocated by initscr()
	endwin();
	return (0);
}
