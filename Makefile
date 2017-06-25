# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emsimang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/21 11:27:01 by emsimang          #+#    #+#              #
#    Updated: 2017/06/25 06:26:07 by emsimang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= clang++
EXE	= viper
LIBFLAG	= -framework OpenGl -framework GLUT
CFLAGS	= -Wall -Wextra -Werror
DFLAG	= -Wno-deprecated
INC	= ./include
SRCDIR	= ./src/
OBDIR	= ./obj/
SRC	= game.cpp snake.cpp
OBJ	= $(SRC:.cpp=.o)
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(OBJ))
OS	:= $(shell uname)

ifeq ($(OS), Darwin)
	LIBFLAG := -framework OpenGl -framework GLUT
else
	LIBFLAG := -lGLU -lGL -lglut
endif

all:
	$(CC) src/opengl.cpp $(DFLAG) $(SRCS) -o$(EXE) -I$(INC) $(LIBFLAG)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXE)

git:
	git add *
	git commit -m "all ready"
	git push origin master

viper: all
	./$(EXE)

re: fclean all
