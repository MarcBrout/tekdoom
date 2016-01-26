/*
** menu_credits.c for tekdoom in /home/sauvau_m/rendu/gfx_tekdoom/wolf_to_the_rescue
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue Jan 26 11:53:39 2016 Mathieu Sauvau
** Last update Tue Jan 26 13:35:39 2016 Mathieu Sauvau
*/

#include "menu.h"

void			write_credit_menu(t_data *data)
{
  t_bunny_position	pos_txt;

  pos_txt = pos_(WIDTH / 2 - (my_strlen("Marc Brout") / 2 * 20), 50);
  write_bmp(data, "Marc Brout", pos_txt);
  pos_txt = pos_(WIDTH / 2 - (my_strlen("Benjamin Duhieu") / 2 * 20), 150);
  write_bmp(data, "Benjamin Duhieu", pos_txt);
  pos_txt = pos_(WIDTH / 2 - (my_strlen("Maud Marel") / 2 * 20), 250);
  write_bmp(data, "Maud Marel", pos_txt);
  pos_txt =  pos_(WIDTH / 2 - (my_strlen("Mathieu Sauvau") / 2 * 20), 350);
  write_bmp(data, "Mathieu Sauvau", pos_txt);
  pos_txt =  pos_(WIDTH / 2 - (my_strlen("Back") / 2 * 20), 450);
  write_bmp(data, "Back", pos_txt);
}

void			credit_menu(t_data *data)
{
  t_mrect		rect;
  int			i;
  int			offset;

  i = -1;
  offset = 50;
  while (++i < 5)
    {
      rect.size = pos_(400, 50);
      rect.pos = pos_(WIDTH / 2 - 200, offset);
      if (i != 4)
	label(data, false, rect.size, rect.pos);
      else
	label(data, true, rect.size, rect.pos);
      offset += 100;
    }
}
