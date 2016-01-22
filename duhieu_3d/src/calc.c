/*
** calc.c for calc in
** /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Jan 17 10:16:40 2016 benjamin duhieu
** Last update Fri Jan 22 15:38:02 2016 benjamin duhieu
*/

#include "main.h"

void		disp_wall(t_main *doom, int x)
{
  int		i;
  unsigned	*pixels;

  pixels = (unsigned *)doom->pix->pixels;
  i = doom->calc.draw_start - 1;
  while (++i < doom->calc.draw_end && i < HEIGHT)
    pixels[x + i * WIDTH] = WHITE;
}
void	calc(t_main *doom)
{

}
