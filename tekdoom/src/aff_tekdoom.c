/*
** aff_tekdoom.c for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Dec 18 16:11:12 2015 marc brout
** Last update Wed Jan 27 06:39:11 2016 marc brout
*/

#include "tekdoom.h"

void			main_tekdoom2(t_param *arg)
{
  inertie(arg);
  new_hight(arg);
  calc_walls(arg, arg->data);
  set_bump(arg, &arg->lvl[arg->curlvl]);
  add_player_to_mini(arg, &arg->lvl[arg->curlvl]);
  put_border(arg, 6, BORDER);
  put_border(arg, 4, BORDERIN);
  put_border(arg, 2, BORDEROU);
  mini_map(arg, &arg->lvl[arg->curlvl], arg->data);
  interface(arg);
}

t_bunny_response	main_tekdoom(void *data)
{
  t_param		*arg;

  arg = data;
  bunny_sound_loop(arg->play, true);
  if (!arg->trans)
    {
      if (arg->data->exit)
	return (EXIT_ON_SUCCESS);
      simple_tap(arg);
      sky(arg);
      bottom(arg);
      main_tekdoom2(arg);
      bunny_blit(&arg->win->buffer, &arg->pix->clipable, &arg->data->pos);
    }
  else
    transition(arg);
  bunny_display(arg->win);
  return (GO_ON);
}

void		sky(t_param *arg)
{
  unsigned int	*pixels;
  unsigned int	*sky;
  int		x;
  int		y;
  int		k;
  int		l;
  int		size;

  sky = arg->textures[2]->pixels;
  pixels = arg->pix->pixels;
  size = arg->HEIGHT / 2 + (int)(arg->lvl[arg->curlvl].yangle
				 - (arg->hight * (34)));
  y = size;
  x = 0;
  while (x + (y * arg->WIDTH) > 0)
    {
      k = (int)(((double)x / 1.5 / arg->WIDTH) * arg->textures[2]->CWID) %
	arg->textures[2]->CWID  - arg->lvl[I].plangle * 15;
      l = (int)((double)y * 1.5) % arg->textures[2]->CHEI;
      x++;
      pixels[x + y * arg->WIDTH] = sky[k + l * arg->textures[2]->CWID];
      if (x == arg->WIDTH && !(x = 0))
	  y--;
    }
}

void		bottom(t_param *arg)
{
  int		y;
  int		x;
  int		end;
  unsigned int	*pixels;

  y = arg->HEIGHT;
  end = arg->HEIGHT / 2
    + (int)(arg->lvl[arg->curlvl].yangle - (arg->hight * 34));
  pixels = arg->pix->pixels;
  while (--y > end)
    {
      x = -1;
      while (++x < arg->WIDTH)
	pixels[x + y * arg->WIDTH] = FLOOR;
    }
}

char		aff_tekdoom(t_param *arg)
{
  if ((arg->pix = bunny_new_pixelarray(arg->WIDTH, arg->HEIGHT)) == NULL ||
      (arg->win = bunny_start(arg->WIDTH, arg->HEIGHT,
			      arg->CONFIG->fullscreen, "DOOM")) == NULL)
    return (1);
  arg->curlvl = 0;
  arg->key = &my_keys;
  arg->move = &my_mouse;
  arg->mov = 1;
  set_minimaps(arg);
  interface_init(arg);
  if (load_picture(arg) < 0)
    return (-1);
  bunny_set_loop_main_function(main_tekdoom);
  bunny_set_move_response(arg->move);
  bunny_set_click_response(main_click);
  bunny_set_key_response(arg->key);
  bunny_set_mouse_visibility(arg->win, 0);
  bunny_set_mouse_position_window(arg->win, arg->WIDTH / 2, arg->HEIGHT / 2);
  bunny_loop(arg->win, 24, arg);
  bunny_delete_clipable(&arg->pix->clipable);
  bunny_stop(arg->win);
  return (0);
}
