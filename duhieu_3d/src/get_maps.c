/*
** get_maps.c for doom in /home/brout_m/rendu/projet/Infographie/gfx_tekdoom/duhieu_3d/src
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Jan 20 23:52:35 2016 marc brout
** Last update Wed Jan 20 23:55:04 2016 marc brout
*/

#include "main.h"

char			set_line_length(int **tab, int len, int hei)
{
  int			i;

  i = -1;
  while (++i < hei)
    if ((tab[i] = malloc(sizeof(int) * (len + 1))) == NULL)
      return (1);
  return (0);
}

char			set_line_lengthd(double **tab, int len, int hei)
{
  int			i;

  i = -1;
  while (++i < hei)
    if ((tab[i] = malloc(sizeof(double) * (len + 1))) == NULL)
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

char			parse_mapd(t_ini *ini, 
				   t_lvl *lvl, double **tab, char *map)
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
	  if (!(tab[y][x] = get_double(nb)))
	    pres = 1;
	}
    }
  if (!pres)
    return (1);
  return (0);
}
