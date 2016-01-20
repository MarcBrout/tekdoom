/*
** draw.c for draw in /home/mmaud/Rendu/Infographie/gfx_tekdoom/Interface
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Thu Jan 14 15:14:24 2016 Maud MAREL
** Last update Wed Jan 20 17:40:53 2016 Maud MAREL
*/

#include "lifebar.h"

int			draw_move_life(t_data *data)
{
  t_bunny_position	pos_s;

  if (data->life.end == 0)
    pos_s.x = (data->life.life * 3 * WIDTH) / 1000;
  else
    pos_s.x = (WIDTH / 75) - 1;
  while (++pos_s.x < data->life.pos_life.x)
    {
      pos_s.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) - 1;
      while(++pos_s.y < (HEIGHT - (HEIGHT / 75)))
  	tekpixel(data->pix, &pos_s, 0x008CFF);
    }
  if (data->life.pos_life.x > data->life.pos_limit.x)
    {
      pos_s.x = data->life.pos_life.x;
      pos_s.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) - 1;
      while(++pos_s.y < data->life.pos_life.y)
	tekpixel(data->pix, &pos_s, WHITE);
      return (0);
    }
  data->life.pos_life.x = data->life.pos_limit.x + 1;
  return (0);
}
