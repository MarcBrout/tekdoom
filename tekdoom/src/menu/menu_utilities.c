/*
** menu_utilities.c for tekdoom in /home/sauvau_m/rendu/gfx_tekdoom/menu_wip
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jan 22 16:47:28 2016 Mathieu Sauvau
** Last update Fri Jan 22 17:48:24 2016 Mathieu Sauvau
*/

#include "menu.h"

t_bunny_position	calc_pos_txt(t_data *data, t_mrect ref, int offset_len)
{
  t_bunny_position	pos;

  pos = ref.pos;
  pos.x -= ref.size.x / 2 - data->pos.x + offset_len / 2 * 20;
  pos.y += data->pos.y;
  return (pos);
}

t_bunny_position	pos_(int x, int y)
{
  t_bunny_position	pos;

  pos.x = x;
  pos.y = y;
  return (pos);
}

t_bunny_position	centered_pos(t_data *data, t_bunny_position size,
				     int offset_x, int offset_y)
{
  t_bunny_position      pos;

  pos.x = data->config->width / 2 - size.x / 2 + offset_x;
  pos.y = data->config->height / 2 + offset_y;
  return (pos);
}

t_bunny_picture		*search_letter(t_letter *letter, char c)
{
  int			i;

  i = -1;
  while (++i < 76)
    {
      if (letter[i].name == c)
	return (letter[i].letter);
    }
  return (NULL);
}

void			write_bmp(t_data *data, char *txt, t_bunny_position start)
{
  int			i;
  t_bunny_position	pos;
  t_bunny_picture	*pic;

  i = -1;
  pos = start;
  while (txt[++i])
    {
      if ((pic = search_letter(data->letter, txt[i])) != NULL)
	bunny_blit(&data->win->buffer, pic, &pos);
      pos.x += 20;
    }
}
