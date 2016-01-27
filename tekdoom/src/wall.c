/*
** wall.c for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Dec 25 00:46:23 2015 marc brout
** Last update Wed Jan 27 04:42:53 2016 marc brout
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
