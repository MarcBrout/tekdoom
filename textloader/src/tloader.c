/*
** tloader.c for doom
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Jan 21 21:52:29 2016 marc brout
** Last update Fri Jan 22 02:01:38 2016 marc brout
*/

#include "tloader.h"

t_bunny_response	my_esc(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       UNUSED void *data)
{
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

void			my_back(t_bunny_pixelarray *array, unsigned int col)
{
  unsigned int		*pix;
  int			i;
  int			total;

  i = -1;
  total = array->clipable.clip_width * array->clipable.clip_height;
  pix = (unsigned int *)array->pixels;
  while (++i < total)
    pix[i] = col;
}

void			copy_sprite(t_sprite *spt,
				    t_bunny_pixelarray *sprt,
				    t_bunny_pixelarray *pix)
{
  unsigned int		*pixels;
  unsigned int		*pixelsm;
  int			i;
  int			total;

  pixels = (unsigned int *)pix->pixels;
  pixelsm = (unsigned int *)sprt->pixels;
  total = pix->clipable.clip_width * pix->clipable.clip_height;
  i = -1;
  while (++i < total)
    if (pixels[i] != spt->back)
      pixelsm[i] = pixels[i];
}

t_bunny_response	main_loop(void *data)
{
  t_arg			*arg;

  arg = data;
  my_back(arg->pix, BLACK);
  copy_sprite(arg->texture, arg->pix, arg->texture->anim[arg->texture->i]);
  bunny_blit(&arg->win->buffer, &arg->pix->clipable, NULL);
  bunny_display(arg->win);
  arg->texture->i = (arg->texture->i + 1) % 5;
  return (GO_ON);
}

char			loadmap(t_arg *arg)
{
  if ((arg->pix = bunny_new_pixelarray(arg->texture->w,
				       arg->texture->h)) == NULL ||
      (arg->win = bunny_start(arg->texture->w, arg->texture->h,
			      0, "wolf")) == NULL)
    return (1);
  arg->texture->i = 0;
  bunny_set_key_response(my_esc);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(arg->win, 10, arg);
  bunny_delete_clipable(&arg->texture->sprt->clipable);
  bunny_stop(arg->win);
  return (0);
}

void		calc_one_sprite(t_sprite *arg)
{
  int		i;
  unsigned int	*pixels;

  pixels = (unsigned int *)arg->sprt->pixels;
  arg->h = 0;
  arg->w = 0;
  i = -1;
  arg->back = pixels[0];
  while (pixels[++i] == pixels[0])
    arg->w += 1;
  i = -1;
  while (pixels[++i * arg->sprt->clipable.clip_width] == pixels[0])
    arg->h += 1;
}

char		set_anim(t_sprite *spt)
{
  int		i;
  int		j;
  int		x;
  int		y;
  int		limy;
  unsigned int	*pixels;
  unsigned int	*pixelsm;

  spt->anim = malloc(sizeof(t_bunny_pixelarray *) * 6);
  spt->anim[5] = NULL;
  pixelsm = (unsigned int *)spt->sprt->pixels;
  i = -1;
  while (++i < 5)
    {
      spt->anim[i] = bunny_new_pixelarray(spt->w, spt->h);
      pixels = (unsigned int *)spt->anim[i]->pixels;
      y = (i * (spt->h + 1)) - 1;
      limy = y + spt->h + 1;
      j = 0;
      printf("y = %d    --    ymax = %d\n", y, limy);
      while (++y < limy)
	{
	  x = -1;
	  while (++x < spt->w)
	    pixels[x + j * spt->w] =
	      pixelsm[x + y * spt->sprt->clipable.clip_width];
	  j++;
	}
    }
  return (1);
}

int		main()
{
  t_sprite	sprite;
  t_arg		arg;

  sprite.sprt = bunny_load_pixelarray("files/sprites/wolf.png");
  arg.texture = &sprite;
  calc_one_sprite(arg.texture);
  set_anim(arg.texture);
  printf("w = %d, h = %d\n", arg.texture->w, arg.texture->h);
  loadmap(&arg);
  return (0);
}
