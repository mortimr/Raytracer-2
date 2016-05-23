##
## Makefile for raytra in /home/rotaru_i/Coding/LibLap/tests
## 
## Made by Iulian Rotaru
## Login   <rotaru_i@epitech.net>
## 
## Started on  Tue Apr 26 17:42:45 2016 Iulian Rotaru
## Last update Sat May 14 19:29:25 2016 
##

CC		= 	g++

LIB		= 	ar r

FLAGS           =       -W -Wall -Werror			\
			-fPIC -std=gnu++03              	\
			-D_GLIBCXX_USE_CXX11_ABI=0      	\
			-fnothrow-opt				\
			-L/home/${USER}/.froot/lib     		\
			-llapin -lsfml-audio -lsfml-graphics	\
			-lsfml-window -lsfml-system -lstdc++	\
			-ldl -lm 				\
			-Wall -Wextra -Werror			\
			-O2

INC		= 	-I/home/${USER}/.froot/include 		\
		  	-I./inc

RM		= 	rm -rf

NAME		= 	libcarrot.a

SRC		= 	win_pos.cpp

OBJ		= 	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)
	ranlib $(NAME)
	if [ -f .signa ] ; then cat .signa ; fi

.cpp.o:
		@$(CC) $(INC) $(FLAGS) -c $< -o $@ 
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
