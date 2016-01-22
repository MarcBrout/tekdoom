##
## Makefile for Makefile in /home/marel_m/rendu/liblapintest
##
## Made by maud marel
## Login   <marel_m@epitech.net>
##
## Started on  Mon Nov  2 12:21:34 2015 maud marel
## Last update Fri Jan 22 13:29:02 2016 Maud MAREL
##

NAME		=	lifebar

SRC             =	src/main.c \
			src/my_set_square.c \
			src/tekpixel.c \
			src/tekpixel2.c \
			src/draw_life.c \
			src/draw_heart.c \
			src/draw_bullet.c \

OBJ             =       $(SRC:.c=.o)

LIBS		=	-L/home/$(USER)/.froot/lib/ \
			-llapin \
                        -lsfml-audio \
                        -lsfml-graphics \
                        -lsfml-window \
                        -lsfml-system \
                        -lstdc++ -ldl \
			-lm \

CFLAGS		+=	-Iinclude \

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
