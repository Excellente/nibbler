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

int main(int argc, char **argv)
{

	ILibrary *iwin = new ILibrary();
	iwin->initialize(&argc, argv);
	return (0);
}