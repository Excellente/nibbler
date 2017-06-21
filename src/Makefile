# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emsimang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/21 11:27:01 by emsimang          #+#    #+#              #
#    Updated: 2017/06/21 11:31:30 by emsimang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
LIBFLAG = -framework OpenGl -framework GLUT
CFLAGS = -Wall -Wextra -Werror
DFLAG = -Wno-deprecated
INC = ./include

all:
	$(CC) *.cpp -I$(INC) $(DFLAG) $(LIBFLAG)

clean:
	rm -f a.out
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXE)

re: flcean all
