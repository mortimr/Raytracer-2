##
## Makefile for raytra in /home/rotaru_i/Coding/LibLap/tests
## 
## Made by Iulian Rotaru
## Login   <rotaru_i@epitech.net>
## 
## Started on  Tue Apr 26 18:00:55 2016 Iulian Rotaru
## Last update Wed May 11 15:53:16 2016 Alif Matthias
##

all:
	make -C ./src/cpp
	make -C ./src

clean:
	make -C ./src/cpp clean
	make -C ./src clean

fclean:
	make -C ./src/cpp fclean
	make -C ./src fclean

re:
	make -C ./src/cpp re
	make -C ./src re

.PHONY: all clean fclean re
