/*
** write_bmp.c for tekdoom in /home/sauvau_m/rendu/gfx_tekdoom/menu_wip
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jan 22 16:43:24 2016 Mathieu Sauvau
** Last update Fri Jan 22 17:49:47 2016 Mathieu Sauvau
*/

#include "menu.h"

void			write_input_menu(t_data *data)
{
  t_bunny_position	pos_txt;

  pos_txt =  calc_pos_txt(data, data->rect_input[0], my_strlen("Up"));
  write_bmp(data, "Up", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[1], my_strlen("Down"));
  write_bmp(data, "Down", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[2], my_strlen("Left"));
  write_bmp(data, "Left", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[3], my_strlen("Right"));
  write_bmp(data, "Right", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[4], my_strlen("Action"));
  write_bmp(data, "Action", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[5], my_strlen("Jump"));
  write_bmp(data, "Jump", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[6], my_strlen("Reload"));
  write_bmp(data, "Reload", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[7], my_strlen("Shoot"));
  write_bmp(data, "Shoot", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[8], my_strlen("Zoom"));
  write_bmp(data, "Zoom", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[9], my_strlen("Back"));
  write_bmp(data, "Back", pos_txt);
}

void			write_main_menu(t_data *data)
{
  t_bunny_position	pos_txt;

  pos_txt =  calc_pos_txt(data, data->rect[0], my_strlen("Play"));
  write_bmp(data, "Play", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect[1], my_strlen("Options"));
  write_bmp(data, "Options", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect[2], my_strlen("Credits"));
  write_bmp(data, "Credits", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect[3], my_strlen("Quit"));
  write_bmp(data, "Quit", pos_txt);
}

void			write_option_menu_2(t_data *data)
{
  t_bunny_position	pos_txt;
  char			convert_int[3];

  pos_txt = calc_pos_txt(data, data->rect_opt[5], my_strlen("FOV"));
  pos_txt.x -= 60;
  write_bmp(data, "FOV", pos_txt);
  itoa(CONFIG->fov, convert_int, 10);
  pos_txt = calc_pos_txt(data, data->rect_opt[5], 3);
  pos_txt.x += 60;
  write_bmp(data, convert_int, pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_opt[7], my_strlen("Input Config"));
  write_bmp(data, "Input Config", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_opt[8], my_strlen("Save"));
  write_bmp(data, "Save", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_opt[9], my_strlen("Back"));
  write_bmp(data, "Back", pos_txt);
}

void			write_option_menu(t_data *data)
{
  t_bunny_position	pos_txt;
  char			convert_int[3];

  itoa(CONFIG->volume, convert_int, 10);
  pos_txt = calc_pos_txt(data, data->rect_opt[0], my_strlen("Fullscreen"));
  write_bmp(data, "Fullscreen", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_opt[1], my_strlen("Resolution"));
  write_bmp(data, "Resolution", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_opt[2],
			 my_strlen(RES[CONFIG->res_i].res));
  write_bmp(data, RES[CONFIG->res_i].res, pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_opt[3], my_strlen("Volume"));
  pos_txt.x -= 60;
  write_bmp(data, "Volume", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_opt[3], 3);
  pos_txt.x += 60;
  write_bmp(data, convert_int, pos_txt);
  write_option_menu_2(data);
}

void			write_change_key(t_data *data)
{
  t_bunny_position	pos_txt;

  pos_txt.x = WIDTH / 2 - 110;
  pos_txt.y = HEIGHT / 2 - 20;
  write_bmp(data, "Press a key", pos_txt);
}
