/*
** parse_maps.c for doom
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sun Jan 17 11:52:54 2016 marc brout
** Last update Sun Jan 17 23:35:33 2016 marc brout
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
  elem->type = NULL;
  elem->size = NULL;
  elem->text = NULL;
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

char			set_line_length(int **tab, int len, int hei)
{
  int			i;

  i = -1;
  while (++i < hei)
    if ((tab[i] = malloc(sizeof(int) * (len + 1))) == NULL)
      return (1);
  return (0);
} 

char			parse_map(t_ini *ini, 
				  t_lvl *lvl, int **tab, char *map)
{
  int			x;
  int			y;
  int			i;
  char			*nb;
  char			pres;

  y = -1;
  pres = 0;
  while (++y < lvl->hei)
    {
      x = -1;
      while (++x < lvl->wid)
	{
	  i = x + (lvl->hei - 1 - y) * lvl->wid;
	  if ((nb = (char *)BISGF(ini->scope, map, i)) == NULL)
	    return (1);
	  if (!(tab[y][x] = my_getnbr(nb)))
	    pres = 1;
	}
    }
  if (!pres)
    return (1);
  return (0);
}

char			set_minimap_size(t_ini *ini)
{
  int			h;

  if (BISGF(ini->scope, "width", 0) == NULL ||
      BISGF(ini->scope, "height", 0) == NULL)
    return (1);
  ini->lvls->prev->wid = my_getnbr((char *)BISGF(ini->scope, "width", 0));
  ini->lvls->prev->hei = my_getnbr((char *)BISGF(ini->scope, "height", 0));
  h = ini->lvls->prev->hei;
  if ((ini->lvls->prev->type = malloc(sizeof(int *) * (h + 1))) == NULL ||
      (ini->lvls->prev->size = malloc(sizeof(int *) * (h + 1))) == NULL ||
      (ini->lvls->prev->text = malloc(sizeof(int *) * (h + 1))) == NULL)
    return (1);
  ini->lvls->prev->type[h] = NULL;
  ini->lvls->prev->size[h] = NULL;
  ini->lvls->prev->text[h] = NULL;
  if (set_line_length(ini->lvls->prev->type, ini->lvls->prev->wid, h) ||
      set_line_length(ini->lvls->prev->size, ini->lvls->prev->wid, h) ||
      set_line_length(ini->lvls->prev->text, ini->lvls->prev->wid, h))
    return (1);
  if (parse_map(ini, ini->lvls->prev, ini->lvls->prev->type, "type") ||
      parse_map(ini, ini->lvls->prev, ini->lvls->prev->size, "size") ||
      parse_map(ini, ini->lvls->prev, ini->lvls->prev->text, "text"))
    return (1);
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
	      set_minimap_size(tmp))
	    return (1);
	  tmp->scope = bunny_ini_next(tmp->ini, tmp->scope);
	}
      tmp = tmp->next;
    }
  return (0);
}
