/*
** menu_init.c for tekdomm in /home/sauvau_m/rendu/gfx_tekdoom/menu_wip
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jan 22 16:48:40 2016 Mathieu Sauvau
** Last update Mon Jan 25 15:47:01 2016 Mathieu Sauvau
*/

#include "menu.h"

void			init_res(t_data *data)
{
  my_strcpy(RES[0].res, "640x480");
  RES[0].width = 640;
  RES[0].height = 480;
  my_strcpy(RES[1].res, "800x600");
  RES[1].width = 800;
  RES[1].height = 600;
  my_strcpy(RES[2].res, "1280x720");
  RES[2].width = 1280;
  RES[2].height = 720;
  my_strcpy(RES[3].res, "1280x1024");
  RES[3].width = 1280;
  RES[3].height = 1024;
}

void			default_config(t_data *data)
{
  data->config->fullscreen = false;
  data->config->width = 800;
  data->config->height = 600;
  data->config->volume = 100;
  data->config->fov = 60;
  INPUT->key[0] = 25;
  INPUT->key[1] = 18;
  INPUT->key[2] = 16;
  INPUT->key[3] = 3;
  INPUT->key[4] = 57;
  INPUT->key[5] = 17;
  INPUT->key[6] = 4;
  INPUT->key[7] = 11;
  INPUT->key[8] = 12;
}

int			init_data(t_data *data)
{
  data->menu_length = 4;
  if ((data->rect = malloc(sizeof(t_mrect) * data->menu_length)) == NULL)
    return (1);
  load_config(data);
  init_res(data);
  CONFIG->res_i = get_res(data, CONFIG->height);
  load_letter(data);
  data->selected_index = 0;
  data->menu_index = 0;
  data->exit = false;
  INPUT->change_key = false;
  if (CONFIG->fullscreen && CONFIG->height == 720)
    {
      data->pos.x = WIDTH / 4;
      data->pos.y = HEIGHT / 4;
    }
  else
    {
      data->pos.x = 0;
      data->pos.y = 0;
    }
  return (0);
}

int			get_res(t_data *data, int height)
{
  int			i;

  i = -1;
  while (++i < 4)
    {
      if (height == RES[i].height)
	{
	  WIDTH = RES[i].width;
	  HEIGHT = RES[i].height;
	  return (i);
	}
    }
  WIDTH = RES[1].width;
  HEIGHT = RES[1].height;
  return (1);
}
