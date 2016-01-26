/*
** free_all.c for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Dec 22 19:56:24 2015 marc brout
** Last update Tue Jan 26 22:08:36 2016 maud marel
*/

#include "tekdoom.h"

void		free_all(t_param *arg)
{
  int		i;
  int		j;

  i = -1;
  while (++i < arg->nblvl)
    {
      j = -1;
      while (++j < arg->lvl[i].height)
	bunny_free(arg->lvl[i].map[j]);
      bunny_free(arg->lvl[i].map);
      bunny_free(arg->lvl[i].name);
      bunny_free(arg->lvl[i].desc);
      bunny_delete_clipable(&arg->lvl[i].mini->clipable);
    }
  bunny_free(arg->lvl);
}
