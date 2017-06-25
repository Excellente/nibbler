# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emsimang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/21 11:27:01 by emsimang          #+#    #+#              #
#    Updated: 2017/06/25 18:16:39 by emsimang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= clang++
EXE	= viper
LIB1 = lib1.so
LIB2 = lib2.so
LIB3 = lib3.so
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
	$(CC) src/opengl.cpp $(DFLAG) $(SRCS) -o $(EXE) -I$(INC) $(LIBFLAG)

MLIB1:
	$(CC) $(SRCS) -c -I$(INC) $(DFLAG) $(LIBFLAGS)
	$(CC) $(OBJ) -shared -fPIC -o $(LIB1) -I $(INC) $(DFLAG) $(LIBFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIB1)
	rm -f $(LIB2)
	rm -f $(LIB3)
	rm -f $(EXE)

git:
	git add *
	git commit -m "all ready"
	git push origin master

viper: all
	./$(EXE)

re: fclean all
