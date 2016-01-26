/*
** calc.c for wolf
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Dec 18 18:56:11 2015 marc brout
** Last update Tue Jan 26 15:42:11 2016 benjamin duhieu
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

void		project_k(t_param *arg, t_lvl *lvl, int x, t_data *data)
{
  int		y;
  int		j;
  int		k;
  double	l;
  double	p;
  double	o;
  double	coef;
  double	dist;
  unsigned int	*pixelstext;
  unsigned int	*floor;
  unsigned int	*ceil;
  unsigned int	*pixels;
  int		total;
  int		size;

  pixels = arg->pix->pixels;
  pixelstext = arg->textures[0]->pixels;
  ceil = arg->textures[2]->pixels;
  size = (HEIGHT / (2 * arg->calc.k));
  start = -1;
  total = (HEIGHT / 2) + size + lvl->yangle - (arg->hight * 200) / arg->calc.k;
  y = (HEIGHT / 2) - size - 1 + lvl->yangle - (arg->hight * 200) / arg->calc.k;
  k = (int)(arg->textures[0]->CWID * (DEC(arg->calc.xf) + DEC(arg->calc.yf)))
    % arg->textures[0]->CWID;
  /* o = (int)(((double)x / WIDTH) * arg->textures[2]->CWID) % */
  /*   arg->textures[2]->CWID; */
  l = 0;
  /* while (++start < y) */
  /*   { */
  /*     if (y == HEIGHT) */
  /* 	p = (int)(start * arg->textures[2]->CHEI) % arg->textures[2]->CHEI; */
  /*     else */
  /* 	p = (int)(((double)start / (HEIGHT - y)) * */
  /* 		  arg->textures[2]->CHEI) % arg->textures[2]->CHEI; */
  /*     printf("y = %d, start = %d, prop = %d, CHEI = %d\n", y, start, HEIGHT - y, arg->textures[2]->CHEI); */
  /*     pixels[(int)(x + start * WIDTH)] = ceil[o + p * arg->textures[2]->CWID]; */
  /*   } */
  while (++y < total && y < HEIGHT && ++l)
    if (y >= 0 && k >= 0)
      {
	j = (int)((l / size) * arg->textures[0]->CHEI) % arg->textures[0]->CHEI;
	pixels[(int)(x + y * WIDTH)] =
	  pixelstext[k + j * arg->textures[0]->CWID];
      }
  while (y++ < HEIGHT - 1)
    {
      dist = HEIGHT / ((2 * y) - h);
      coef = dist / arg->calc.k;
      p = coef * x + (1 - coef) * arg->lvl[arg->curlvl].playerx;
      o = coef * y + (1 - coef) * arg->lvl[arg->curlvl].playery;
      pixels[(int)(x + y * WIDTH)] =
	pixelstext[p + o * arg->textures[2]->CWID];
      pixels[(int)(x + (h - y) * WIDTH)] =
	pixelstext[p + o * arg->textures[1]->CWID];
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
