/*
** free.c for free in /home/duhieu_b/infographie/rendu/gfx_tekdoom/wolf_to_the_rescue
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Jan 27 05:29:03 2016 benjamin duhieu
** Last update Wed Jan 27 06:08:41 2016 benjamin duhieu
*/

#include "tekdoom.h"

void	free_obj(t_lvl *lvl)
{
  int	x;
  int	y;
  int	i;

  i = -1;
  while (lvl->objs[++i])
    {
      y = -1;
      while (++y < lvl->height)
	{
	  x = -1;
	  while (++x < lvl->width)
	    bunny_free(&lvl->objs[i][y][x]);
	  bunny_free(lvl->objs[i][y]);
	}
      bunny_free(lvl->objs[i]);
    }
}

void	free_map(t_lvl *lvl)
{
  int	i;

  i = -1;
  while (lvl->map[++i])
    bunny_free(lvl->map[i]);
  bunny_free(lvl->map);
}

void	free_lvl(t_param *arg)
{
  int	i;

  i = -1;
  while (++i < arg->nblvl)
    {
      free_obj(arg->lvl);
      bunny_free(arg->lvl->objs);
      free_map(arg->lvl);
      bunny_free(arg->lvl->name);
      bunny_free(arg->lvl->desc);
      bunny_delete_clipable(&arg->lvl->mini->clipable);
    }
  bunny_free(arg->lvl);
}

void	free_other(t_param *arg)
{
  bunny_free(arg->wm.ydep);
  bunny_free(arg->inter.gun.gunshoot1);
  bunny_free(arg->inter.gun.gunshoot2);
  bunny_free(arg->inter.gun.gunshoot3);
  bunny_free(arg->inter.gun.reload1);
  bunny_free(arg->inter.gun.reload2);
  bunny_free(arg->inter.gun.reload3);
  bunny_free(arg->inter.gun.punch1);
  bunny_free(arg->inter.gun.punch2);
  bunny_free(arg->inter.gun.punch3);
  bunny_free(arg->inter.gun.scope);
  bunny_free(arg->inter.gun.biggun1);
  bunny_free(arg->inter.gun.biggun2);
  bunny_free(arg->inter.gun.biggun3);
  bunny_free(arg->inter.gun.biggun4);
  bunny_free(arg->inter.gun.biggun5);
  bunny_free(arg->inter.gun.biggun6);
  bunny_free(arg->inter.gun.knife1);
  bunny_free(arg->inter.gun.knife2);
  bunny_free(arg->inter.gun.knife3);
}
