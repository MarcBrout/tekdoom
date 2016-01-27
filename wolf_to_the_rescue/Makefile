##
## Makefile for wolf3d in /home/brout_m/rendu/projet/Infographie/gfx_wolf3d
##
## Made by marc brout
## Login   <brout_m@epitech.net>
##
## Started on  Thu Dec 17 13:59:43 2015 marc brout
## Last update Wed Jan 27 03:32:24 2016 marc brout
##

SRCP	= ./src/

SRCI	= ./src/interface/

MENU = ./src/menu/

SRC     = $(SRCP)tekdoom.c \
	$(SRCP)check_file.c \
	$(SRCP)transition.c \
	$(SRCP)fill_tablvl.c \
	$(SRCP)aff_tekdoom.c \
	$(SRCP)inertia.c \
	$(SRCP)free_all.c \
	$(SRCP)wall.c \
	$(SRCP)keyboard.c \
	$(SRCP)calc.c \
	$(SRCP)my_getnbr.c \
	$(SRCP)my_strdup.c \
	$(SRCP)my_strlen.c \
	$(SRCP)my_strcmp.c \
	$(SRCP)textures.c \
	$(MENU)change_key.c \
	$(MENU)start.c \
	$(MENU)menu.c \
	$(MENU)menu_nav.c \
	$(MENU)my_strcat.c \
	$(MENU)my_strcpy.c \
	$(MENU)my_revstr.c \
	$(MENU)tekpixel.c \
	$(MENU)itoa.c \
	$(MENU)music.c \
	$(MENU)menu_draw.c \
	$(MENU)menu_utilities.c \
	$(MENU)menu_utilities2.c \
	$(MENU)menu_init.c \
	$(MENU)nav.c \
	$(MENU)save_opt.c \
	$(MENU)load_config.c \
	$(MENU)write_bmp.c \
	$(MENU)menu_credits.c \
	$(SRCI)mini_map.c \
	$(SRCI)mini_map_blit.c \
	$(SRCI)draw_bullet.c \
	$(SRCI)draw_heart.c \
	$(SRCI)draw_life.c \
	$(SRCI)draw_biggun.c \
	$(SRCI)draw_trigger.c \
	$(SRCI)draw_gunshot.c \
	$(SRCI)draw_reload.c \
	$(SRCI)draw_scope.c \
	$(SRCI)draw_punch.c \
	$(SRCI)weapon.c \
	$(SRCI)load_picture.c \
	$(SRCI)interface.c \
	$(SRCI)keyboard_interface.c \
	$(SRCI)tekpixel2.c \
	$(SRCI)tekpixel3.c \

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
