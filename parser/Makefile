##
## Makefile for wolf3d in /home/brout_m/rendu/projet/Infographie/gfx_wolf3d
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Thu Dec 17 13:59:43 2015 marc brout
## Last update Sun Jan 17 21:42:49 2016 marc brout
##

SRCP	= ./src/

SRC     = $(SRCP)parse_file.c \
	$(SRCP)tools.c \
	$(SRCP)parse_maps.c \

OBJS    = $(SRC:.c=.o)

NAME    = tekdoom

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
	-L./lib/ \
	-lmy \

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
