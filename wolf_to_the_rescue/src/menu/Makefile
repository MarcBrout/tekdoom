##
## Makefile for fdf in /home/sauvau_m/rendu/gfx_fdf1
##
## Made by Mathieu Sauvau
## Login   <sauvau_m@epitech.net>
##
## Started on  Wed Nov 18 19:31:13 2015 Mathieu Sauvau
## Last update Mon Jan 25 13:53:08 2016 Mathieu Sauvau
##

CFLAGS += -W -Wall -Wextra -g # -Werror
#CFLAGS += -ansi -pedantic
CFLAGS += -I ./include
CFLAGS += -I /home/${USER}/.froot/include

NAME = lapin

SRC =	tekpixel.c \
	start.c \
	my_getnbr.c \
	my_strlen.c \
	my_strcpy.c \
	my_strcat.c \
	my_revstr.c \
	itoa.c \
	change_key.c \
	load_config.c \
	menu_draw.c \
	menu_nav.c \
	menu_utilities.c \
	menu_utilities2.c \
	nav.c \
	menu.c \
	menu_init.c \
	save_opt.c \
	write_bmp.c

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
