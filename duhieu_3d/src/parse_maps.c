/*
** parse_maps.c for doom
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sun Jan 17 11:52:54 2016 marc brout
** Last update Fri Jan 22 23:54:14 2016 marc brout
*/

#include "main.h"

char		open_ini(t_ini *ini)
{
  if ((ini->ini = bunny_load_ini(ini->file)) == NULL)
    return (1);
  if ((ini->scope = bunny_ini_first(ini->ini)) == NULL)
    return (1);
  if ((ini->scope = bunny_ini_next(ini->ini, ini->scope)) == NULL)
    return (1);
  return (0);
}

char		add_lvl(t_ini *ini)
{
  t_lvl		*elem;

  if ((elem = malloc(sizeof(t_lvl))) == NULL)
    return (1);
  elem->name = NULL;
  elem->desc = NULL;
  elem->text = NULL;
  elem->segs = NULL;
  elem->next = ini->lvls;
  elem->prev = ini->lvls->prev;
  ini->lvls->prev->next = elem;
  ini->lvls->prev = elem;
  return (0);
}

char			get_lvl_infos(t_ini *ini)
{
  if (bunny_ini_scope_name(ini->ini, ini->scope) == NULL ||
      BISGF(ini->scope, "desc", 0) == NULL ||
      BISGF(ini->scope, "start_position", 0) == NULL ||
      BISGF(ini->scope, "start_position", 1) == NULL ||
      BISGF(ini->scope, "start_position", 2) == NULL)
    return (1);
  if ((ini->lvls->prev->name = my_strdup
       ((char *)bunny_ini_scope_name(ini->ini, ini->scope))) == NULL ||
      (ini->lvls->prev->desc =
       my_strdup((char*)BISGF(ini->scope, "desc", 0))) 
      == NULL)
    return (1);
  ini->lvls->prev->plx = my_getnbr
    ((char *)BISGF(ini->scope, "start_position", 0));
  ini->lvls->prev->ply = my_getnbr
    ((char *)BISGF(ini->scope, "start_position", 1));
  ini->lvls->prev->pla = my_getnbr
    ((char *)BISGF(ini->scope, "start_position", 2));
  return (0);
}

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

char			parse_maps(t_parse *parse)
{
  t_ini			*tmp;
  t_seg			*tmp2;

  tmp = parse->maps->next;
  while (tmp != NULL && !access(tmp->file, F_OK))
    {
      if (open_ini(tmp))
	continue;
      while (tmp->scope != NULL)
	{
	  if (add_lvl(tmp) || get_lvl_infos(tmp) ||
	      segment_listing(tmp, tmp->lvls->prev))
	    return (1);
	  tmp->scope = bunny_ini_next(tmp->ini, tmp->scope);
	}
      tmp = tmp->next;
    }
  tmp2 = parse->maps->next->lvls->segs;
  while (tmp2)
    {
      printf("%f, %f, %f, %f\n", tmp2->ax, tmp2->ay, tmp2->bx, tmp2->by);
      tmp2 = tmp2->next;
    }
  return (0);
}
