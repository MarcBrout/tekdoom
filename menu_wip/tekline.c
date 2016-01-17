/*
** put_pix_line.c for pixel - line in /home/sauvau_m/bunnyTGraph
** 
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
** 
** Started on  Mon Nov 16 09:56:34 2015 Mathieu Sauvau
** Last update Fri Dec  4 10:32:51 2015 Mathieu Sauvau
*/

#include "lapin.h"
#include "struct.h"

void			inc_dx(t_bunny_pixelarray *pix_ar,
			       t_bunny_position point, t_bunny_position d,
			       t_color *color)
{
  int			i;
  int			cumul;
  int			xinc;
  int			yinc;

  xinc = (d.x < 0 ? -1 : 1);
  yinc = (d.y < 0 ? -1 : 1);
  d.x = (d.x < 0 ? -d.x : d.x);
  d.y = (d.y < 0 ? -d.y : d.y);
  i = 0;
  cumul = d.x / 2;
  while (++i <= d.x)
    {
      point.x += xinc;
      cumul += d.y;
      if (cumul >= d.x)
	{
	  cumul -= d.x;
	  point.y += yinc;
	}
      tekpixel(pix_ar, point, color);
    }
}

void			inc_dy(t_bunny_pixelarray *pix_ar,
			       t_bunny_position point, t_bunny_position d, 
			       t_color *color)
{
  int			i;
  int			cumul;
  int			xinc;
  int			yinc;

  i = 0;
  xinc = (d.x < 0 ? -1 : 1);
  yinc = (d.y < 0 ? -1 : 1);
  d.x = (d.x < 0 ? -d.x : d.x);
  d.y = (d.y < 0 ? -d.y : d.y);
  cumul = d.y / 2;
  while (++i <= d.y)
    {
      point.y += yinc;
      cumul += d.x;
      if (cumul >= d.y)
	{
	  cumul -= d.y;
	  point.x += xinc;
	}
      tekpixel(pix_ar, point, color);
    } 
}

void			tekline(t_bunny_pixelarray *pix_ar,
				t_bunny_position *coord,
				t_color *color)
{
  t_bunny_position	point;
  t_bunny_position	d;

  d.x = coord[1].x - coord[0].x;
  d.y = coord[1].y - coord[0].y;
  point.x = coord[0].x;
  point.y = coord[0].y;
  if ((d.x < 0 ? -d.x : d.x) > (d.y < 0 ? -d.y : d.y))
    inc_dx(pix_ar, point, d, color);
  else
    inc_dy(pix_ar, point, d, color);
}
