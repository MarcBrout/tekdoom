/*
** wall.c for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Dec 25 00:46:23 2015 marc brout
** Last update Tue Jan 26 22:10:08 2016 maud marel
*/

#include "tekdoom.h"

void		new_hight(t_param *arg)
{
  if (arg->jump && ++arg->chrono < 360)
    {
      if (arg->jump > 277)
	{
	  arg->jump = 0;
	  arg->chrono = 0;
	  arg->hight = 0;
	}
    }
  if (arg->jump)
    {
      arg->hight = arg->wm.costab[arg->jump];
      arg->jump += 10;
    }
}

void		wall_north_east(t_param *arg, int x, int y, int total)
{
  unsigned int	*pixels;

  pixels = arg->pix->pixels;
  if (arg->calc.vecx >= 0 && arg->calc.vecy >= 0)
    {
      if (arg->calc.x)
  	while (++y < total && y < arg->HEIGHT)
  	  pixels[x + y * arg->WIDTH] = WALLA;
      else
  	while (++y < total && y < arg->HEIGHT)
  	  pixels[x + y * arg->WIDTH] = WALLB;
    }
}

void		wall_north_west(t_param *arg, int x, int y, int total)
{
  unsigned int	*pixels;

  pixels = arg->pix->pixels;
  if (arg->calc.vecx < 0 && arg->calc.vecy >= 0)
    {
      if (arg->calc.x)
  	while (++y < total && y < arg->HEIGHT)
  	  pixels[x + y * arg->WIDTH] = WALLD;
      else
  	while (++y < total && y < arg->HEIGHT)
  	  pixels[x + y * arg->WIDTH] = WALLB;
    }
}

void		wall_south_west(t_param *arg, int x, int y, int total)
{
  unsigned int	*pixels;

  pixels = arg->pix->pixels;
  if (arg->calc.vecx < 0 && arg->calc.vecy < 0)
    {
      if (arg->calc.x)
  	while (++y < total && y < arg->HEIGHT)
  	  pixels[x + y * arg->WIDTH] = WALLD;
      else
  	while (++y < total && y < arg->HEIGHT)
  	  pixels[x + y * arg->WIDTH] = WALLC;
    }
}

void		wall_south_east(t_param *arg, int x, int y, int total)
{
  unsigned int	*pixels;

  pixels = arg->pix->pixels;
  if (arg->calc.vecx >= 0 && arg->calc.vecy < 0)
    {
      if (arg->calc.x)
  	while (++y < total && y < arg->HEIGHT)
  	  pixels[x + y * arg->WIDTH] = WALLA;
      else
  	while (++y < total && y < arg->HEIGHT)
  	  pixels[x + y * arg->WIDTH] = WALLC;
    }
}
