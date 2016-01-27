/*
** wall.c for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Dec 25 00:46:23 2015 marc brout
** Last update Wed Jan 27 08:40:19 2016 marc brout
*/

#include "tekdoom.h"

void		basic_to_sec(t_param *arg, int x)
{
  XF = arg->calc.d;
  YF = arg->wm.ydep[x];
  arg->calc.vecx = XF * arg->wm.costab[(int)arg->lvl[I].plangle]
    - YF * arg->wm.sintab[(int)arg->lvl[I].plangle];
  arg->calc.vecy = XF * arg->wm.sintab[(int)arg->lvl[I].plangle]
    + YF * arg->wm.costab[(int)arg->lvl[I].plangle];
}

char		test_k(t_param *arg, int x)
{
  if (DEC(YF) > 0.54 && DEC(YF) < 0.56 &&
      DEC(XF) > 0.54 && DEC(XF) < 0.56 &&
      arg->lvl[I].objs[(int)YF][(int)XF]->type)
    {
      arg->lvl[I].objs[(int)YF][(int)XF]->trace = 1;
      arg->lvl[I].objs[(int)YF][(int)XF]->k = arg->calc.k;
      arg->lvl[I].objs[(int)YF][(int)XF]->x = x;
    }
  if ((int)YF >= 0 && (int)YF < arg->lvl[I].height &&
      (int)XF >= 0 && (int)XF < arg->lvl[I].width)
    if (arg->lvl[I].map[(int)YF][(int)XF])
      return (1);
  return (0);
}

void		get_len(t_param *arg, int x)
{
  arg->calc.k = 0;
  XF = arg->lvl[I].playerx
    + arg->calc.vecx * arg->calc.k;
  YF = arg->lvl[I].playery
    + arg->calc.vecy * arg->calc.k;
  while (!arg->lvl[I].map[(int)YF][(int)XF])
    {
      arg->calc.k += 0.005;
      XF = arg->lvl[I].playerx + arg->calc.vecx *arg->calc.k;
      arg->calc.x = 1;
      if (test_k(arg, x))
	return ;
      YF = arg->lvl[I].playery + arg->calc.vecy * arg->calc.k;
      arg->calc.x = 0;
      if (test_k(arg, x))
	return ;
      if ((int)XF <= 0 || (int)XF >= arg->lvl[I].width ||
	  (int)YF <= 0 || (int)YF >= arg->lvl[I].height)
	return ;
    }
}

void		new_hight(t_param *arg)
{
  if (arg->jump && ++arg->chrono < 360)
    {
      if (arg->jump > 277)
	{
	  arg->jump = 0;
	  arg->chrono = 0;
	  arg->hight = 0;
	}
    }
  if (arg->jump)
    {
      arg->hight = arg->wm.costab[arg->jump];
      arg->jump += 10;
    }
}

void		get_player(t_param *arg, t_lvl *lvl)
{
  lvl->tiles = my_getnbr((char *)FLD(arg->ini, lvl->name, "tile_size", 0));
  lvl->playerx = my_getnbr((char *)FLD(arg->ini, lvl->name,
				       "start_position", 0));
  lvl->playery = my_getnbr((char *)FLD(arg->ini, lvl->name,
				       "start_position", 1));
  lvl->plangle = (my_getnbr((char *)FLD(arg->ini, lvl->name,
					"start_position", 2)) % 360);
  if (!lvl->playerx || !lvl->playery || lvl->playerx >= lvl->width ||
      lvl->playery >= lvl->height)
    {
      lvl->playerx = 0;
      lvl->playery = 0;
      while (lvl->map[(int)lvl->playery][(int)lvl->playerx])
	{
	  lvl->playerx += 1;
	  if (lvl->playerx == lvl->width)
	    {
	      lvl->playerx = 0;
	      lvl->playery += 1;
	    }
	}
    }
  lvl->yangle = 0;
  lvl->playerx += 0.5;
  lvl->playery += 0.5;
}
