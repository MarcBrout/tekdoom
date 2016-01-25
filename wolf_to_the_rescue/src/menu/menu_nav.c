/*
** menu_nav.c for tekdoom in /home/sauvau_m/rendu/gfx_tekdoom/menu_wip
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jan 22 16:34:03 2016 Mathieu Sauvau
** Last update Mon Jan 25 16:37:57 2016 Mathieu Sauvau
*/

#include <menu.h>

int			menu_nav(t_data *data)
{
  if (data->selected_index == 0)
    return (1);
  if (data->selected_index == 1)
    {
      data->menu_length = 7;
      data->selected_index = 0;
      data->menu_index = 1;
    }
  else if (data->selected_index == 2)
    {
      data->selected_index = 0;
      data->menu_index = 2;
    }
  else if (data->selected_index == 3)
    data->exit = true;
  return (0);
}

void			input_nav(t_data *data)
{
  if (data->selected_index == 9)
    {
      data->menu_length = 7;
      data->selected_index = 0;
      data->menu_index = 1;
    }
  else
    {
      INPUT->change_key = true;
      INPUT->key_to_change = data->selected_index;
    }
}

void			option_nav(t_data *data)
{
  if (data->selected_index == 0)
    data->config->fullscreen = !data->config->fullscreen;
  else if (data->selected_index == 1)
    (CONFIG->res_i == 3) ? (CONFIG->res_i = 0) : (CONFIG->res_i++);
  else if (data->selected_index == 4)
    {
      data->menu_length = 10;
      data->menu_index = 3;
      data->selected_index = 0;
    }
  else if (data->selected_index == 5)
    save_opt(data);
  else if (data->selected_index == 6)
    {
      data->menu_length = 4;
      data->menu_index = 0;
      data->selected_index = 0;
    }
}

void			option_nav2(t_bunny_event_state state, t_bunny_keysym keysym,
				 t_data *data)
{
  if ((keysym == BKS_LEFT || keysym == INPUT->key[2]) && state == GO_DOWN)
    {
      if (data->menu_index == 1 && data->selected_index == 1)
	(CONFIG->res_i == 0) ? (CONFIG->res_i = 3) : (CONFIG->res_i--);
      else if (data->menu_index == 1 && data->selected_index == 2
	  && data->config->volume > 0)
	data->config->volume--;
      else if (data->menu_index == 1 && data->selected_index == 3
	  && data->config->fov > 50)
	data->config->fov--;
    }
  else if ((keysym == BKS_RIGHT || keysym == INPUT->key[3])
	   && state == GO_DOWN)
    {
      if (data->menu_index == 1 && data->selected_index == 1)
	(CONFIG->res_i == 3) ? (CONFIG->res_i = 0) : (CONFIG->res_i++);
      else if (data->menu_index == 1 && data->selected_index == 2
	  && data->config->volume < 100)
	data->config->volume++;
      else if (data->menu_index == 1 && data->selected_index == 3
	  && data->config->fov < 100)
	data->config->fov++;
    }
}
