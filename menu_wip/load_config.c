/*
** load_config.c for tekdomm in /home/sauvau_m/rendu/gfx_tekdoom/menu_wip
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jan 22 16:49:58 2016 Mathieu Sauvau
** Last update Sun Jan 24 14:07:15 2016 Mathieu Sauvau
*/

#include "menu.h"

void			load_input(t_data *data)
{
  INPUT->key[0] = my_getnbr((char *)BGF(CONFIG->ini, "input", "up", 0));
  INPUT->key[1] = my_getnbr((char *)BGF(CONFIG->ini, "input", "down", 0));
  INPUT->key[2] = my_getnbr((char *)BGF(CONFIG->ini, "input", "left", 0));
  INPUT->key[3] = my_getnbr((char *)BGF(CONFIG->ini, "input", "right", 0));
  INPUT->key[4] = my_getnbr((char *)BGF(CONFIG->ini, "input", "jump", 0));
  INPUT->key[5] = my_getnbr((char *)BGF(CONFIG->ini, "input", "reload", 0));
  INPUT->key[6] = my_getnbr((char *)BGF(CONFIG->ini, "input", "action", 0));
  INPUT->key[7] = my_getnbr((char *)BGF(CONFIG->ini, "input", "fire", 0));
  INPUT->key[8] = my_getnbr((char *)BGF(CONFIG->ini, "input", "zoom", 0));
}

void			load_config(t_data *data)
{
  if ((CONFIG = bunny_malloc(sizeof(t_config))) == NULL)
    exit(1);
  if ((CONFIG->ini = bunny_load_ini("config.ini")) != NULL)
    {
      data->config->fullscreen =
	my_getnbr((char *)BGF(CONFIG->ini, "config", "fullscreen", 0));
      WIDTH = my_getnbr((char *)BGF(CONFIG->ini, "config", "width", 0));
      HEIGHT = my_getnbr((char *)BGF(CONFIG->ini, "config", "height", 0));
      VOLUME = my_getnbr((char *)BGF(CONFIG->ini, "config", "volume", 0));
      CONFIG->fov = my_getnbr((char *)BGF(CONFIG->ini, "config", "fov", 0));
      load_input(data);
    }
  else
    default_config(data);
}

void			load_letter(t_data *data)
{
  int			i;
  char			path[11];
  char			letter[90];
  int			l_path;
  double		scale;

  i = -1;
  scale = 0.5;
  scale += 0.25 * CONFIG->res_i;
  my_strcpy(path, "text/a.bmp");
  my_strcpy(letter, "  0123456789abcdefghijklmnopqrstuvwxyz");
  my_strcat(letter, "ABCDEFGHIJKLMNOPQRSTUWVXYZ()<>.,!?;:-_'\"");
  l_path = my_strlen(path);
  while (++i < 75)
    {
      path[l_path - 5] = letter[i];
      data->letter[i].name = letter[i];
      data->letter[i].letter = bunny_load_picture(path);
      data->letter[i].letter->scale.x *= scale;
      data->letter[i].letter->scale.y *= scale;
    }
}
