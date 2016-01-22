##
## Makefile for wolf3d in /home/brout_m/rendu/projet/Infographie/gfx_wolf3d
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Thu Dec 17 13:59:43 2015 marc brout
## Last update Thu Jan 21 22:33:13 2016 marc brout
##

SRCP	= ./src/

SRC     = $(SRCP)tloader.c

OBJS    = $(SRC:.c=.o)

NAME    = tloader

CC      = gcc -g

CFLAGS  = -W -Wall -Werror -ansi -pedantic

CFLAGS	+= -I/home/${USER}/.froot/include -I./include

LDFLAGS = -L/home/${USER}/.froot/lib \
	-llapin \
	-lsfml-audio \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system \
	-lstdc++ -ldl \
	-lm \


RM      = rm -f

.c.o:
	$(CC) -c $< -o $@ $(CFLAGS)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
