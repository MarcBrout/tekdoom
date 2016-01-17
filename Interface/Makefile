##
## Makefile for Makefile in /home/marel_m/rendu/liblapintest
##
## Made by maud marel
## Login   <marel_m@epitech.net>
##
## Started on  Mon Nov  2 12:21:34 2015 maud marel
## Last update Thu Jan 14 16:25:50 2016 Maud MAREL
##

NAME		=	interface

SRC             =	main.c \
			my_set_square.c \
			tekpixel.c \
			draw.c \

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
