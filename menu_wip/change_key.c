/*
** change_key.c for tekdoom in /home/sauvau_m/rendu/gfx_tekdoom/menu_wip
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jan 22 16:55:31 2016 Mathieu Sauvau
** Last update Sun Jan 24 14:19:09 2016 Mathieu Sauvau
*/

#include "menu.h"

int			check_key_inuse(t_data *data, int key)
{
  int			i;

  i = -1;
  while (++i < 10)
    {
      if (INPUT->key[i] == key)
	return (i);
    }
  return (-1);
}

void			swap_key(t_data *data, int key, int in_use)
{
  int			swap;

  swap = INPUT->key[INPUT->key_to_change];
  INPUT->key[INPUT->key_to_change] = key;
  INPUT->key[in_use] = swap;
}

void		        change_key(t_data *data)
{
  const  bool		*k;
  int			i;
  int			in_use;

  if (data->selected_index != 9 && INPUT->change_key)
    {
      i = -1;
      k = bunny_get_keyboard();
      while (++i < 102)
	{
	  if (i != BKS_RETURN && k[i] == 1)
	    {
	      if ((in_use = check_key_inuse(data, i)) == -1)
		INPUT->key[INPUT->key_to_change] = i;
	      else
		swap_key(data, i, in_use);
	      save_input(data);
	      INPUT->change_key = false;
	      data->selected_index++;
	    }
	}
    }
}
