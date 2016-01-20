/*
** draw_init_life.c for draw_init_life in /home/mmaud/Rendu/Infographie/gfx_tekdoom/Interface
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Sun Jan 17 10:45:26 2016 Maud MAREL
** Last update Wed Jan 20 15:48:04 2016 Maud MAREL
*/

#include "lifebar.h"

void                    draw_life_bar(t_data *data)
{
  t_bunny_position      pos_s;
  t_bunny_position      pos_e;

  pos_s.x = (WIDTH / 75) - 1;
  pos_e.x = (data->life.life * 3 * WIDTH) / 1000;
  pos_e.y = HEIGHT - (HEIGHT / 75);
  while (++pos_s.x < pos_e.x)
    {
      pos_s.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) - 1;
      while(++pos_s.y < pos_e.y)
	tekpixel(data->pix, &pos_s, RED);
    }
  data->life.pos_life.x = (3 * WIDTH) / 10;
  data->life.pos_life.y = HEIGHT - (HEIGHT / 75);
}

void			action_draw_square_life(t_data *data,
						    t_bunny_position pos_e,
						    t_bunny_position pos_s)
{
  t_bunny_position      pos_eh;
  t_bunny_position      pos_sh;

  pos_eh.x = pos_e.x;
  pos_eh.y = pos_s.y - 1;
  pos_sh.x = pos_s.x - 1;
  pos_sh.y = pos_e.y;
  while (pos_s.x <= pos_eh.x)
    {
      tekpixel(data->pix, &pos_s, BLACK);
      pos_s.x++;
    }
  while (++pos_eh.y <= pos_e.y)
    tekpixel(data->pix, &pos_eh, BLACK);
  pos_s.x = (WIDTH / 75) - 1;
  while (pos_s.y <= pos_e.y)
    {
      tekpixel(data->pix, &pos_s, BLACK);
      pos_s.y++;
    }
  while (++pos_sh.x <= pos_e.x)
    tekpixel(data->pix, &pos_sh, BLACK);
}

void                    draw_square_life(t_data *data)
{
  t_bunny_position      pos_s;
  t_bunny_position      pos_e;

  pos_s.x = (WIDTH / 75) - 1;
  pos_s.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) - 1;
  pos_e.x = ((WIDTH / 10) + (WIDTH / 5)) + 1;
  pos_e.y = HEIGHT - (HEIGHT / 75);
  action_draw_square_life(data, pos_e, pos_s);
}
