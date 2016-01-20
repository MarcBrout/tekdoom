##
## Makefile for Makefile in /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d
##
## Made by benjamin duhieu
## Login   <duhieu_b@epitech.net>
##
## Started on  Fri Jan 15 10:08:11 2016 benjamin duhieu
## Last update Fri Jan 15 10:31:38 2016 benjamin duhieu
##

SRC	=	src/main.c \

OBJS	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -ansi -pedantic -Iinclude

LIB	=	-L/home/${USER}/.froot/lib/ -llapin \
		-lsfml-audio \
		-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \
		-lstdc++ -ldl \
		-lm \

CC	=	gcc -g $(CFLAGS)

RM	=	rm -f

NAME	=	tekdoom

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(LIB)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
