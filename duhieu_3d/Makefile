##
## Makefile for Makefile in /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d
##
## Made by benjamin duhieu
## Login   <duhieu_b@epitech.net>
##
## Started on  Fri Jan 15 10:08:11 2016 benjamin duhieu
<<<<<<< HEAD
## Last update Thu Jan 21 22:21:26 2016 benjamin duhieu
=======
## Last update Wed Jan 20 23:56:08 2016 marc brout
>>>>>>> 4f3bf963312008283e224b5ff26ede9980862c08
##

SRC	=	src/start.c \
		src/background.c \
		src/correct_dist.c \
		src/init_data.c \
		src/event.c \
		src/calc.c \
		src/direction.c \
		src/parse_file.c \
		src/parse_maps.c \
		src/tools.c \
		src/get_double.c \
		src/get_maps.c

OBJS	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -ansi -pedantic -Iinclude

LIB	=	-L/home/${USER}/.froot/lib/ -llapin \
		-lsfml-audio \
		-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \
		-lstdc++ -ldl \
		-lm \
		-L./lib/ \
		-lmy

CC	=	gcc -g $(CFLAGS)

RM	=	rm -f

NAME	=	tekdoom

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LIB)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
