/*
** fill_tablvl.c for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Dec 18 11:50:49 2015 marc brout
** Last update Wed Jan 27 07:09:19 2016 marc brout
*/

#include "tekdoom.h"

void		init_obj(t_obj *obj, int nb)
{
  obj->type = nb;
  obj->alive = 1;
  obj->trace = 0;
  obj->k = 0;
  obj->x = 0;
}

char		get_lvl_map(t_param *arg, t_lvl *lvl)
{
  int		x;
  int		y;
  int		ind;
  const char	*nb;
  const char	*nb2;
  char		pres;

  y = -1;
  pres = 0;
  while (++y < lvl->height && (x = -1))
    while (++x < lvl->width)
      {
	ind = x + (lvl->height - 1 - y) * lvl->width;
	if (!(nb = FLD(arg->ini, lvl->name, "data", ind)) ||
	    !(nb2 = FLD(arg->ini, lvl->name, "type", ind)))
	  return (1);
	lvl->map[y][x] = my_getnbr((char *)nb);
	init_obj(lvl->objs[y][x], my_getnbr((char *)nb2));
	if (!lvl->map[y][x])
	  pres = 1;
    }
  if (!pres)
    return (1);
  return (0);
}

char		get_tabmap(t_param *arg)
{
  int		i;

  i = -1;
  while (++i < arg->nblvl)
    {
      if (get_lvl_map(arg, &arg->lvl[i]))
	return (1);
      get_player(arg, &arg->lvl[i]);
    }
  return (0);
}

char		mal_lvl_map(t_param *arg, t_lvl *lvl)
{
  int		i;
  int		j;

  if (!(lvl->height = my_getnbr((char *)FLD(arg->ini, lvl->name, "height", 0)))
      ||
      !(lvl->width = my_getnbr((char *)FLD(arg->ini, lvl->name, "width", 0))))
   return (1);
  if (mal_mini_map(arg, lvl))
    return (2);
  if (!(lvl->map = bunny_malloc(sizeof(int *) * (lvl->height + 1))) ||
      !(lvl->objs = bunny_malloc(sizeof(t_obj **) * (lvl->height + 1))))
    return (3);
  i = -1;
  while (++i < lvl->height)
    {
      if (!(lvl->map[i] = bunny_malloc(sizeof(int) * (lvl->width + 1))) ||
	  !(lvl->objs[i] = bunny_malloc(sizeof(t_obj *) * (lvl->width + 1))))
	return (4);
      j = -1;
      while (++j < lvl->width)
	if (!(lvl->objs[i][j] = bunny_malloc(sizeof(t_obj))))
	  return (4);
    }
  return (0);
}

char		mal_tablvl(t_param *arg)
{
  char		*name;
  int		i;

  if ((arg->lvl = bunny_malloc(sizeof(t_lvl) * (arg->nblvl + 1))) == NULL)
    return (1);
  i = -1;
  while (++i < arg->nblvl &&
	 (name = (char *)FLD(arg->ini, NULL, "lvlscope", i)) != NULL)
    {
      if ((arg->lvl[i].name = my_strdup(name)) == NULL)
	return (2);
      if ((arg->lvl[i].desc =
	   my_strdup((char *)FLD(arg->ini, name, "name", 0))) == NULL)
	return (3);
      if (mal_lvl_map(arg, &arg->lvl[i]))
	return (4);
    }
  return (0);
}
