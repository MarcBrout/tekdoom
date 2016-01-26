##
## Makefile for Makefile in /home/marel_m/rendu/liblapintest
##
## Made by maud marel
## Login   <marel_m@epitech.net>
##
## Started on  Mon Nov  2 12:21:34 2015 maud marel
## Last update Sat Jan 23 19:52:28 2016 maud marel
##

NAME		=	lifebar

SRC             =	src/main.c \
			src/my_set_square.c \
			src/tekpixel.c \
			src/tekpixel2.c \
			src/draw_life.c \
			src/draw_heart.c \
			src/draw_bullet.c \
			src/draw_trigger.c \

OBJ             =       $(SRC:.c=.o)

LIBS		=	-L/home/${USER}/.froot/lib/ \
			-llapin \
                        -lsfml-audio \
                        -lsfml-graphics \
                        -lsfml-window \
                        -lsfml-system \
                        -lstdc++ -ldl \
			-lm \

CFLAGS		+=	-Iinclude \
			-I/home/${USER}/.froot/include/

CFLAGS     	+=	-W -Wall -ansi -pedantic

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
