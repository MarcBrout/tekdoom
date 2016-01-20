##
## Makefile for Makefile in /home/marel_m/rendu/liblapintest
##
## Made by maud marel
## Login   <marel_m@epitech.net>
##
## Started on  Mon Nov  2 12:21:34 2015 maud marel
## Last update Sun Jan 17 12:00:31 2016 Maud MAREL
##

NAME		=	interface

SRC             =	src/main.c \
			src/my_set_square.c \
			src/tekpixel.c \
			src/draw.c \
			src/draw_init_life.c \

OBJ             =       $(SRC:.c=.o)

LIBS		=	-L/home/$(USER)/.froot/lib \
			-L/usr/local/lib \
			-llapin \
                        -lsfml-audio \
                        -lsfml-graphics \
                        -lsfml-window \
                        -lsfml-system \
                        -lstdc++ -ldl \
			-lm \

CFLAGS		+=	-Iinclude/

CFLAGS     	+=	-W -Wall -ansi -pedantic -I/usr/local/include/

CFLAGS		+=	$(LIBS)

FLAGS		=	$(LIBS)

CC		=	gcc

RM		=	rm -f

$(NAME):        $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(FLAGS)

all:            $(NAME)

clean:
		$(RM) $(OBJ)

fclean:         clean
		$(RM) $(NAME)

re:             fclean all
