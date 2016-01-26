/*
** aff_wolf.c for wolf
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Dec 18 16:11:12 2015 marc brout
<<<<<<< HEAD
** Last update Tue Jan 26 17:38:03 2016 marc brout
=======
** Last update Tue Jan 26 17:46:22 2016 benjamin duhieu
>>>>>>> 0dc7fb166465d61183647255ee6c72b7d5db0450
*/

#include "wolf.h"

t_bunny_response		my_mouse(const t_bunny_position *pos,
					 void *data)
{
  const t_bunny_position	*abs;
  t_param			*arg;

  arg = data;
  abs = bunny_get_mouse_position();
  if (!arg->mov)
    {
      arg->lvl[arg->curlvl].yangle += pos->y / 3;
      arg->lvl[arg->curlvl].plangle += pos->x / 3;
      if (arg->lvl[arg->curlvl].plangle <= 0)
	arg->lvl[arg->curlvl].plangle += 359;
      if (arg->lvl[arg->curlvl].plangle >= 359)
	arg->lvl[arg->curlvl].plangle -= 359;
    }
  else
    arg->mov = 0;
  if ((abs->x <= 200 || abs->x >= (arg->WIDTH - 200)) ||
      (abs->y <= 200 || abs->y >= (arg->HEIGHT - 200)))
    {
      bunny_set_mouse_position_window(arg->win, arg->WIDTH / 2,
				      arg->HEIGHT / 2);
      arg->mov = 1;
    }
  return (GO_ON);
}

void			main_wolf2(t_param *arg)
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

t_bunny_response	main_wolf(void *data)
{
  t_param		*arg;
  int			i;

  arg = data;
  i = -1;
  if (arg->data->exit)
    return (EXIT_ON_SUCCESS);
  if (arg->speedy)
    {
      move(arg, 0, 0.02);
      arg->speedy--;
    }
  simple_tap(arg);
  new_hight(arg);
  i = sky(arg, i);
  bottom(arg, i);
  calc_walls(arg, arg->data);
  set_bump(arg, &arg->lvl[arg->curlvl]);
  add_player_to_mini(arg, &arg->lvl[arg->curlvl]);
  put_border(arg, 6, BORDER);
  put_border(arg, 4, BORDERIN);
  put_border(arg, 2, BORDEROU);
  mini_map(arg, &arg->lvl[arg->curlvl], arg->data);
  interface(arg);
  main_wolf2(arg);
  bunny_blit(&arg->win->buffer, &arg->pix->clipable, &arg->data->pos);
  if (arg->menu)
    bunny_blit(&arg->win->buffer, &arg->data->pix_ar->clipable,
	       &arg->data->pos);
  bunny_display(arg->win);
  return (GO_ON);
}

int		sky(t_param *arg, int i)
{
  unsigned int	*pixels;
  unsigned int	*sky;
  int		x;
  int		y;
  int		k;
  int		l;
  int		total;

<<<<<<< HEAD
  total = (arg->WIDTH * arg->HEIGHT) / 2 +
    (int)(arg->lvl[arg->curlvl].yangle - (arg->hight * (34))) * arg->WIDTH;
  sky = (unsigned int *)arg->textures[2]->pixels;
  pixels = (unsigned int *)arg->pix->pixels;
  y = 0;
  x = 0;
  while (x + (y * arg->WIDTH) < total && total)
    {
      k = (int)(((double)x / arg->WIDTH) * arg->textures[2]->CWID) %
	arg->textures[2]->CWID;
      l = (int)(((double)y / (arg->HEIGHT / 2)) * arg->textures[2]->CHEI) %
	arg->textures[2]->CHEI;
      x++;
      i++;
      pixels[x + y * arg->WIDTH] = sky[k + l * arg->textures[2]->CWID];
      if (x == arg->WIDTH)
	{
	  x = 0;
	  y++;
	}
    }
=======
  total = (arg->WIDTH * arg->HEIGHT) / 2
    + (int)(arg->lvl[arg->curlvl].yangle - (arg->hight * (34))) * arg->WIDTH;
  pixels = arg->pix->pixels;
  while (++i < total && total)
    pixels[i].full = SKY;
>>>>>>> 726d3bff9916ec0f33872d405d4c14fe64fe3ed9
  return (i);
}

void		bottom(t_param *arg, UNUSED int i)
{
  int		y;
  int		x;
  int		end;
  unsigned int	*pixels;

  y = arg->HEIGHT;
  end = arg->HEIGHT / 2 +
    (int)(arg->lvl[arg->curlvl].yangle - (arg->hight * 34));
  pixels = arg->pix->pixels;
  while (--y > end)
    {
      x = -1;
      while (++x < arg->WIDTH)
	pixels[x + y * arg->WIDTH] = FLOOR;
    }
}

char		aff_wolf(t_param *arg)
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
  printf("lol\n");
  bunny_set_loop_main_function(main_wolf);
  bunny_set_move_response(arg->move);
  bunny_set_key_response(arg->key);
  bunny_set_mouse_visibility(arg->win, 0);
  bunny_set_mouse_position_window(arg->win, arg->WIDTH / 2, arg->HEIGHT / 2);
  bunny_loop(arg->win, 24, arg);
  bunny_delete_clipable(&arg->pix->clipable);
  bunny_stop(arg->win);
  return (0);
}
