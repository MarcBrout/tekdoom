/*
** parse_segment.c for doom
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sat Jan 23 19:51:45 2016 marc brout
** Last update Sat Jan 23 21:19:55 2016 marc brout
*/

#include "main.h"

char			add_segment(t_lvl *lvl)
{
  t_seg			*elem;

  if ((elem = malloc(sizeof(t_seg))) == NULL)
    return (1);
  elem->next = lvl->segs;
  lvl->segs = elem;
  return (0);
}

char			segment_listing(t_ini *ini, t_lvl *lvls)
{
  int			i;
  
  i = 0;
  while ((BISGF(ini->scope, "seg", i)) && (BISGF(ini->scope, "seg", i + 1)) &&
	 (BISGF(ini->scope, "seg", i + 2)) && (BISGF(ini->scope, "seg", i + 3))
	 && (BISGF(ini->scope, "size", i / 4)) &&
	 (BISGF(ini->scope, "type", i / 4)))
    {
      add_segment(lvls->prev);
      SEGL->ax = get_double((char*)BISGF(ini->scope, "seg", i));
      SEGL->ay = get_double((char*)BISGF(ini->scope, "seg", i + 1));
      SEGL->bx = get_double((char*)BISGF(ini->scope, "seg", i + 2));
      SEGL->by = get_double((char*)BISGF(ini->scope, "seg", i + 3));
      SEGL->z = get_double((char*)BISGF(ini->scope, "size", i / 4));
      SEGL->type = my_getnbr((char*)BISGF(ini->scope, "type", i / 4));
      i += 4;
    }
  return (0);
}

char			mal_tab(t_lvl *lvl)
{
  int			i;
  int			j;

  if ((lvl->tabseg = malloc(sizeof(double *) * 3)) == NULL ||
      (lvl->tabseg[0] = malloc(sizeof(double) * (lvl->nbseg + 1))) == NULL ||
      (lvl->tabseg[1] = malloc(sizeof(double) * (lvl->nbseg + 1))) == NULL)
    return (1);
  lvl->tabseg[2] = NULL;
  i = -1;
  while (lvl->tabseg[++i])
    {
      j = -1;
      while (++j <= lvl->nbseg)
	lvl->tabseg[i][j] = -1;
    }
  return (0);
}
