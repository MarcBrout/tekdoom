/*
** main.c for fdf1 in /home/sauvau_m/rendu/gfx_fdf1
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Nov 20 18:46:14 2015 Mathieu Sauvau
** Last update Wed Jan 13 14:55:52 2016 Mathieu Sauvau
*/

#include <math.h>
#include "struct.h"

t_bunny_position	pol_to_carth(t_bunny_position *pol)
{
  t_bunny_position	convert;

  convert.x = pol->x * cos(pol->y * M_PI / 180);
  convert.y = pol->x * sin(pol->y * M_PI / 180);
  return (convert);
}

t_bunny_position	carth_to_pol(t_bunny_position *carth)
{
  t_bunny_position	convert;

  convert.x = sqrt(pow(carth->x, 2) + pow(carth->y, 2));
  convert.y = atan2(carth->x, carth->y);
  return (convert);
}

void			create_pov(t_bunny_pixelarray *pix_ar,
				   t_bunny_position pos,
				   t_bunny_position view)
{
  t_bunny_position	pov;

  tekpixel(pix_ar, pos, WHITE);
  pov = pol_to_carth(&view);
  pov.x += pos.x;
  pov.y += pos.y;
  tekpixel(pix_ar, pov, RED);
}

t_bunny_response	esc(t_bunny_event_state state, t_bunny_keysym keysym,
			    void *data)
{
  t_data		*my_data;

  (void)state;
  my_data = data;
  if (keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);

  if (keysym == BKS_UP && state == GO_DOWN)
    my_data->selected_index == 0 ?
      my_data->selected_index = my_data->menu_length - 1 : my_data->selected_index--;
  if (keysym == BKS_DOWN && state == GO_DOWN)
    my_data->selected_index == my_data->menu_length - 1 ?
      my_data->selected_index = 0 : my_data->selected_index++;
  /*  if (keysym == BKS_Z)
    my_data->pos2.y -= 1;
  if (keysym == BKS_S)
    my_data->pos2.y += 1;
  if (keysym == BKS_Q)
    my_data->pos2.x -= 1;
  if (keysym == BKS_D)
    my_data->pos2.x += 1;

  if (keysym == BKS_UP)
    my_data->view.x += 5;
  if (keysym == BKS_DOWN)
    my_data->view.x -= 5;
  if (keysym == BKS_LEFT)
    {
      my_data->view.y -= 5;
    }
  if (keysym == BKS_RIGHT)
    {
      my_data->view.y += 5;
    }*/
  return (GO_ON);
}

t_bunny_response	mainloop(void	*data)
{
  t_data		*my_data;

  my_data = data;
  create_menu(my_data->pix_ar, my_data->menu_length, my_data->selected_index);
  //create_pov(my_data->pix_ar, my_data->pos2, my_data->view);
  bunny_blit(&my_data->win->buffer, &my_data->pix_ar->clipable, &my_data->pos);
  bunny_display(my_data->win);
  return (GO_ON);
}

void                    my_fill(t_bunny_pixelarray *pix_ar, unsigned int color)
{
  int                   x;
  int                   y;
  t_color               *col;
  int                   new_pos;

  x = 0;
  y = 0;
  col = pix_ar->pixels;
  while (x < pix_ar->clipable.clip_width)
    {
      while (y < pix_ar->clipable.clip_height)
        {
          new_pos = pix_ar->clipable.clip_width * y  + x;
          col[new_pos].full = color;
          y++;
        }
      x++;
      y = 0;
    }
}

void                    draw_square(t_bunny_pixelarray *pix_ar,
                                    t_mrect *rect)
{
  int			x;
  int			y;

  x = rect->pos.x;
  y = rect->pos.y;
  while (rect->pos.x < rect->size.x + x)
    {
      while (rect->pos.y < rect->size.y + y)
        {
	  if (rect->selected &&
	      (rect->pos.x <= x + rect->contour - 1
	       || rect->pos.x >= rect->size.x + x - rect->contour ||
	       rect->pos.y <= y + rect->contour - 1
	       || rect->pos.y >= rect->size.y + y - rect->contour))
	    tekpixel(pix_ar, rect->pos, rect->color[1]);
	  else
	      tekpixel(pix_ar, rect->pos, rect->color[0]);
          rect->pos.y++;
        }
      rect->pos.x++;
      rect->pos.y = y;
    }
}

void			create_menu(t_bunny_pixelarray *pix_ar,
				    int nb, int selected_index)
{
  int			n;
  t_mrect		rect[nb];
  int			margin;
  int			offset;

  n = -1;
  margin = 20;
  offset = HEIGHT / 2;
  rect[0].pos.y = offset;
  while (++n < nb)
    {
      rect[n].size.x = WIDTH / 2;
      rect[n].size.y = (HEIGHT - offset - (margin * (nb + 1))) / nb;
      rect[n].pos.x = WIDTH / 2 - rect[n].size.x / 2;
      if (n != 0)
	rect[n].pos.y = rect[n - 1].pos.y + rect[n].size.y + margin;
      rect[n].color[0] = WHITE;
      rect[n].color[1] = RED;
      rect[n].contour = 3;
      if (n == selected_index)
	rect[n].selected = true;
      else
	rect[n].selected = false;
      draw_square(pix_ar, &rect[n]);
    }
}


int			main()
{
  t_data		data;

  data.selected_index = 0;
  data.menu_length = 5;
  data.pos.x = 0;
  data.pos.y = 0;
  memory_check = 1;
  data.win = bunny_start(WIDTH, HEIGHT, false, "test");
  data.pix_ar = bunny_new_pixelarray(WIDTH, HEIGHT);
  my_fill(data.pix_ar, BLACK);

  //  tekpixel(pix_ar, pol_to_carth(&pos2), WHITE);

  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(esc);
  bunny_loop(data.win, 30, &data);
  bunny_delete_clipable(&data.pix_ar->clipable);
  bunny_stop(data.win);
  return (0);
}
