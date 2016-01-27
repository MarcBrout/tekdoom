/*
** calc.c for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Dec 18 18:56:11 2015 marc brout
** Last update Wed Jan 27 03:06:53 2016 benjamin duhieu
*/

#include "tekdoom.h"

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

void		project_k(t_param *arg, t_lvl *lvl, int x, t_data *data)
{
  int		y;
  int		j;
  int		k;
  double	l;
  unsigned int	*pixelstext;
  unsigned int	*pixels;
  int		total;
  int		size;

  pixels = arg->pix->pixels;
  pixelstext = arg->textures[0]->pixels;
  size = (HEIGHT / (2 * arg->calc.k));
  total = (HEIGHT / 2) + size + lvl->yangle - (arg->hight * 200) / arg->calc.k;
  y = (HEIGHT / 2) - size - 1 + lvl->yangle - (arg->hight * 200) / arg->calc.k;
  k = (int)(arg->textures[0]->CWID * (DEC(arg->calc.xf) + DEC(arg->calc.yf)))
    % arg->textures[0]->CWID;
  l = 0;
  while (++y < total && y < HEIGHT && ++l)
    if (y >= 0)
      {
	j = (int)((l / size) * arg->textures[0]->CHEI) % arg->textures[0]->CHEI;
	pixels[(int)(x + y * WIDTH)] =
	  pixelstext[k + j * arg->textures[0]->CWID];
      }
}

void		calc_walls(t_param *arg, t_data *data)
{
  int		x;

  x = -1;
  while (++x < arg->WIDTH)
    {
      basic_to_sec(arg, x);
      get_len(arg);
      project_k(arg, &arg->lvl[arg->curlvl], x, data);
    }
}
