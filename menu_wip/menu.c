/*
** menu.c for tekdooom in /home/sauvau_m/rendu/gfx_tekdoom/menu_wip
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jan 22 16:57:43 2016 Mathieu Sauvau
** Last update Fri Jan 22 17:46:03 2016 Mathieu Sauvau
*/

#include "menu.h"

void			option_menu_2(t_data *data, int selected_index,
				      t_bunny_position pos,
				      t_bunny_position size)
{
  pos.y = data->rect_opt[2].pos.y + data->rect_opt[1].size.y + 20;
  data->rect_opt[3] = label(data, false, size, pos);
  pos.y = data->rect_opt[3].pos.y + data->rect_opt[1].size.y + 15;
  if (selected_index == 2)
    data->rect_opt[4] = slider(data, true, data->config->volume, pos);
  else
    data->rect_opt[4] = slider(data, false, data->config->volume, pos);
  pos.y = data->rect_opt[4].pos.y + data->rect_opt[1].size.y + 20;
  data->rect_opt[5] = label(data, false, size, pos);
  pos.y = data->rect_opt[5].pos.y + data->rect_opt[1].size.y + 20;
  if (selected_index == 3)
    data->rect_opt[6] = slider(data, true, data->config->fov, pos);
  else
    data->rect_opt[6] = slider(data, false, data->config->fov, pos);
  pos.y = data->rect_opt[6].pos.y + data->rect_opt[1].size.y + 20 ;
  (selected_index == 4) ? (data->rect_opt[7] = label(data, true, size, pos)) :
    (data->rect_opt[7] = label(data, false, size, pos));
  pos.y = data->rect_opt[7].pos.y + data->rect_opt[1].size.y + 20;
  (selected_index == 5) ? (data->rect_opt[8] = label(data, true, size, pos)) :
    (data->rect_opt[8] = label(data, false, size, pos));
  pos.y = data->rect_opt[8].pos.y + data->rect_opt[1].size.y + 20;
  (selected_index == 6) ? (data->rect_opt[9] = label(data, true, size, pos)) :
  (data->rect_opt[9] = label(data, false, size, pos));
}

void			option_menu(t_data *data, int selected_index)
{
  t_bunny_position	pos;
  t_bunny_position	size;
  int			margin;

  margin = 20;
  size = pos_(WIDTH / 2 - 60, 50);
  size.y = (data->config->height - margin - (margin * 10)) / 10;
  pos.x = WIDTH / 2 - size.x / 2 - 30;
  pos.y = margin;
  (selected_index == 0) ? (data->rect_opt[0] = label(data, true, size, pos)) :
    (data->rect_opt[0] = label(data, false, size, pos));
  check_box(data, data->config->fullscreen, data->rect_opt[0].pos);
  size = pos_(WIDTH / 2, 50);
  size.y = (data->config->height - margin - (margin * 10)) / 10;
  pos.x = data->config->width / 2 - data->rect_opt[0].size.x / 2 - 30;
  pos.y = data->rect_opt[0].pos.y + data->rect_opt[0].size.y + margin;
  data->rect_opt[1] = label(data, false, size, pos);
  pos.x = data->config->width / 2 - data->rect_opt[1].size.x / 2;
  pos.y = data->rect_opt[1].pos.y + data->rect_opt[1].size.y + margin;
  (selected_index == 1) ? (data->rect_opt[2] = label(data, true, size, pos)) :
    (data->rect_opt[2] = label(data, false, size, pos));
  option_menu_2(data, selected_index, pos, size);
}

void			input_menu_next(t_data *data, t_mrect *ref)
{
  t_mrect		box;

  box.size = pos_(60, ref->size.y);
  box.pos = pos_(ref->pos.x + 20, ref->pos.y);
  box.color[0] = WHITE;
  box.color[1] = WHITE;
  box.contour = 0;
  box.selected = false;
  draw_square(data->pix_ar, &box);
}

void			input_menu(t_data *data, t_mrect *rect,
				   int offset, int margin)
{
  int			n;

  n = -1;
  rect[0].pos.y = margin;
  while (++n < data->menu_length)
    {
      rect[n].size.x = 200;
      rect[n].size.y = (data->config->height - offset
			      - (margin * (data->menu_length + 1))) / data->menu_length;
      rect[n].pos.x = data->config->width / 2 - rect[n].size.x / 2;
      if (n != 0)
	rect[n].pos.y = rect[n - 1].pos.y + rect[n].size.y + margin;
      rect[n].color[0] = WHITE;
      rect[n].color[1] = RED;
      rect[n].contour = 3;
      if (n == data->selected_index)
	rect[n].selected = true;
      else
	rect[n].selected = false;
      draw_square(data->pix_ar, &rect[n]);
      input_menu_next(data, &rect[n]);
    }
}

void			main_menu(t_data *data, t_mrect *rect,  int offset, int margin)
{
  int			n;

  n = -1;
  rect[0].pos.y = offset;
  while (++n < data->menu_length)
    {
      rect[n].size.x = data->config->width / 2;
      rect[n].size.y = (data->config->height - offset
			      - (margin * (data->menu_length + 1))) / data->menu_length;
      rect[n].pos.x = data->config->width / 2 - rect[n].size.x / 2;
      if (n != 0)
	rect[n].pos.y = rect[n - 1].pos.y + rect[n].size.y + margin;
      rect[n].color[0] = WHITE;
      rect[n].color[1] = RED;
      rect[n].contour = 3;
      if (n == data->selected_index)
	rect[n].selected = true;
      else
	rect[n].selected = false;
      draw_square(data->pix_ar, &rect[n]);
    }
}
