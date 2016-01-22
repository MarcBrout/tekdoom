##
## Makefile for fdf in /home/sauvau_m/rendu/gfx_fdf1
##
## Made by Mathieu Sauvau
## Login   <sauvau_m@epitech.net>
##
## Started on  Wed Nov 18 19:31:13 2015 Mathieu Sauvau
## Last update Thu Jan 21 14:57:21 2016 Mathieu Sauvau
##

CFLAGS += -W -Wall -Wextra -g # -Werror
#CFLAGS += -ansi -pedantic
CFLAGS += -I ./include
CFLAGS += -I /home/${USER}/.froot/include

NAME = lapin

SRC =	tekpixel.c \
	main.c \
	my_getnbr.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm -llapin -L/home/${USER}/.froot/lib

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
