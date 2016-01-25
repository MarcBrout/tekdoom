##
## Makefile for wolf3d in /home/brout_m/rendu/projet/Infographie/gfx_wolf3d
##
## Made by marc brout
## Login   <brout_m@epitech.net>
##
## Started on  Thu Dec 17 13:59:43 2015 marc brout
## Last update Mon Jan 25 13:53:00 2016 maud marel
##

SRCP	= ./src/

SRCI	= ./src/interface/

SRC     = $(SRCP)wolf.c \
	$(SRCP)check_file.c \
	$(SRCP)fill_tablvl.c \
	$(SRCP)aff_wolf.c \
	$(SRCP)free_all.c \
	$(SRCP)wall.c \
	$(SRCP)keyboard.c \
	$(SRCP)mini_map.c \
	$(SRCP)mini_map_blit.c \
	$(SRCP)calc.c \
	$(SRCP)my_getnbr.c \
	$(SRCP)my_strdup.c \
	$(SRCP)my_strlen.c \
	$(SRCP)my_strcmp.c \
	$(SRCP)textures.c \
	$(SRCI)draw_bullet.c \
	$(SRCI)draw_heart.c \
	$(SRCI)draw_life.c \
	$(SRCI)draw_trigger.c \
	$(SRCI)tekpixel.c \
	$(SRCI)tekpixel2.c \
	$(SRCI)interface.c \


OBJS    = $(SRC:.c=.o)

NAME    = tekdoom

CC      = gcc -g

CFLAGS  = -W -Wall -ansi -pedantic -I/home/${USER}/.froot/include -I./include

LDFLAGS = -L/home/${USER}/.froot/lib \
	-llapin \
	-lsfml-audio \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system \
	-lstdc++ -ldl \
	-lm \
	-L./lib/ \

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
