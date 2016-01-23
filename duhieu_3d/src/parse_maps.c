/*
** parse_maps.c for doom
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sun Jan 17 11:52:54 2016 marc brout
** Last update Sat Jan 23 19:52:54 2016 marc brout
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
      BISGF(ini->scope, "nbseg", 0) == NULL ||
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
  ini->lvls->prev->nbseg = my_getnbr((char *)BISGF(ini->scope, "nbseg", 0));
  ini->lvls->prev->plx = my_getnbr
    ((char *)BISGF(ini->scope, "start_position", 0));
  ini->lvls->prev->ply = my_getnbr
    ((char *)BISGF(ini->scope, "start_position", 1));
  ini->lvls->prev->pla = my_getnbr
    ((char *)BISGF(ini->scope, "start_position", 2));
  return (0);
}

char			parse_maps(t_parse *parse)
{
  t_ini			*tmp;

  tmp = parse->maps->next;
  while (tmp != NULL && !access(tmp->file, F_OK))
    {
      if (open_ini(tmp))
	continue;
      while (tmp->scope != NULL)
	{
	  if (add_lvl(tmp) || get_lvl_infos(tmp) ||
	      segment_listing(tmp, tmp->lvls->prev) ||
	      mal_tab(tmp->lvls->prev))	    
	    return (1);
	  tmp->scope = bunny_ini_next(tmp->ini, tmp->scope);
	}
      tmp = tmp->next;
    }
  return (0);
}
