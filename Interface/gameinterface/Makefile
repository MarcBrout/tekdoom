##
## Makefile for Makefile in /home/marel_m/rendu/liblapintest
##
## Made by maud marel
## Login   <marel_m@epitech.net>
##
## Started on  Mon Nov  2 12:21:34 2015 maud marel
## Last update Wed Jan 20 15:54:30 2016 Maud MAREL
##

NAME		=	lifebar

SRC             =	src/main.c \
			src/my_set_square.c \
			src/tekpixel.c \
			src/tekpixel2.c \
			src/draw.c \
			src/draw_init_life.c \
			src/draw_init_bullet.c \
			src/draw_heart.c \

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
