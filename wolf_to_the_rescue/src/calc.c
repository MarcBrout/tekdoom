/*
** calc.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 18 18:56:11 2015 marc brout
** Last update Mon Jan 25 09:16:33 2016 marc brout
*/

#include "wolf.h"

void		basic_to_sec(t_param *arg, int x)
{
  arg->calc.xf = arg->calc.d;
  arg->calc.yf = arg->wm.ydep[x];
  arg->calc.vecx =
    arg->calc.xf * arg->wm.costab[(int)arg->lvl[arg->curlvl].plangle]
    - arg->calc.yf * arg->wm.sintab[(int)arg->lvl[arg->curlvl].plangle];
  arg->calc.vecy =
    arg->calc.xf * arg->wm.sintab[(int)arg->lvl[arg->curlvl].plangle]
    + arg->calc.yf * arg->wm.costab[(int)arg->lvl[arg->curlvl].plangle];
}

void		get_len(t_param *arg)
{
  arg->calc.k = 0;
  arg->calc.xf = arg->lvl[arg->curlvl].playerx +
    arg->calc.vecx * arg->calc.k;
  arg->calc.yf = arg->lvl[arg->curlvl].playery +
    arg->calc.vecy * arg->calc.k;
  while (!arg->lvl[arg->curlvl].map[(int)arg->calc.yf][(int)arg->calc.xf])
    {
      arg->calc.k += 0.005;
      arg->calc.xf = arg->lvl[arg->curlvl].playerx + arg->calc.vecx *
	arg->calc.k;
      arg->calc.x = 1;
      if (arg->lvl[arg->curlvl].map[(int)arg->calc.yf][(int)arg->calc.xf])
	return ;
      arg->calc.yf = arg->lvl[arg->curlvl].playery + arg->calc.vecy *
	arg->calc.k;
      arg->calc.x = 0;
      if (arg->lvl[arg->curlvl].map[(int)arg->calc.yf][(int)arg->calc.xf])
	return ;
      if ((int)arg->calc.xf <= 0 ||
	  (int)arg->calc.xf >= arg->lvl[arg->curlvl].width ||
	  (int)arg->calc.yf <= 0 ||
	  (int)arg->calc.yf >= arg->lvl[arg->curlvl].height)
	return ;
    }
}

void		project_k(t_param *arg, t_lvl *lvl, int x)
{
  int		y;
  int		j;
  int		k;
  double	change;
  double	val;
  t_color	*pixelstext;
  t_color	*pixels;
  int		total;

  pixels = arg->pix->pixels;
  pixelstext = arg->textures[0]->pixels;
  total = (HEIGHT / 2) + HEIGHT / (2 * arg->calc.k) + lvl->yangle;
  y = (HEIGHT / 2) - HEIGHT / (2 * arg->calc.k) - 1 + lvl->yangle;
  val = arg->calc.k / (arg->textures[0]->clipable.clip_height / 4);
  j = 0;
  k = arg->textures[0]->clipable.clip_width *
    ((arg->calc.xf - (int)arg->calc.xf) + (arg->calc.yf - (int)arg->calc.yf));
  change = 0;
  while (++y < total && y < HEIGHT)
    {
      if (y >= 0 && k >= 0)
	pixels[x + y * WIDTH].full = 
	  pixelstext[k + j * arg->textures[0]->clipable.clip_width].full;
      if ((change += val) > 1)
      	{
      	  j += change;
	  j = j % arg->textures[0]->clipable.clip_height;
      	  change -= (int)change;
      	}
    }
}

void		calc_walls(t_param *arg)
{
  int		x;

  x = -1;
  while (++x < WIDTH)
    {
      basic_to_sec(arg, x);
      get_len(arg);
      project_k(arg, &arg->lvl[arg->curlvl], x);
    }
}
