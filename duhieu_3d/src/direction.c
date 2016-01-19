/*
** direction.c for dir in /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Jan 17 11:30:54 2016 benjamin duhieu
** Last update Sun Jan 17 11:53:42 2016 benjamin duhieu
*/

#include "engine.h"

int	up(t_main *doom)
{
  doom->calc.ay = (int)(doom->calc.py / doom->calc.dim) * (doom->calc.dim)
    - 1;
  doom->calc.ax = doom->calc.px +
    ((doom->calc.py - doom->calc.ay) /
     (doom->calc.ang.tang[doom->calc.teta * 10]));
  doom->calc.ya = doom->calc.dim * (-1);
  doom->calc.xa = doom->calc.dim / doom->calc.a	\
    ng.tang[doom->calc.teta * 10];
  if (doom->cur->map[doom->calc.ay][doom->calc.ax])
    return (0);
  else
    while (!doom->cur->map[doom->calc.ay][doom->calc.ax])
      {
	doom->calc.ay += doom->calc.ya;
	doom->calc.ax += doom->calc.xa;
      }
  return (0);
}

int	back(t_main *doom)
{
  doom->calc.ay = (int)(doom->calc.py / doom->calc.dim) * (doom->calc.dim)
    + (doom->calc.dim);
  doom->calc.ax = doom->calc.px +
    ((doom->calc.py - doom->calc.ay) /
     (doom->calc.ang.tang[doom->calc.teta * 10]));
  doom->calc.ya = doom->calc.dim;
  doom->calc.xa = doom->calc.dim / doom->calc.ang.tang[doom->calc.teta * 10];
  if (doom->cur->map[doom->calc.ay][doom->calc.ax])
    return (0);
  else
    while (!doom->cur->map[doom->calc.ay][doom->calc.ax])
      {
	doom->calc.ay += doom->calc.ya;
	doom->calc.ax += doom->calc.xa;
      }
  return (0);
}

int	left(t_main *doom)
{
  doom->calc.bx = (int)(doom->calc.px / doom->calc.dim) *
    (doom->calc.dim) + (doom->calc.dim);
  doom->calc.by = doom->calc.py +
    ((doom->calc.px - doom->calc.bx) /
     (doom->calc.ang.tang[doom->calc.teta * 10]));
  doom->calc.xa = doom->calc.dim * (-1);
  doom->calc.ya = doom->calc.dim * doom->calc.ang.tang[doom->calc.teta * 10];
  if (doom->cur->map[doom->calc.by][doom->calc.bx])
    return (0);
  else
    while (!doom->cur->map[doom->calc.by][doom->calc.bx])
      {
	doom->calc.bx += doom->calc.xa;
	doom->calc.by += doom->calc.ya;
      }
  return (0);
}

int	right(t_main *doom)
{
  doom->calc.bx = (int)(doom->calc.px / doom->calc.dim) * (doom->calc.dim)
    - 1;
  doom->calc.by = doom->calc.py +
    ((doom->calc.px - doom->calc.bx) /
     (doom->calc.ang.tang[doom->calc.teta * 10]));
  doom->calc.xa = doom->calc.dim;
  doom->calc.ya = doom->calc.dim * doom->calc.ang.tang[doom->calc.teta * 10];
  if (doom->cur->map[doom->calc.by][doom->calc.bx])
    return (0);
  else
    while (!doom->cur->map[doom->calc.by][doom->calc.bx])
      {
	doom->calc.bx += doom->calc.xa;
	doom->calc.by += doom->calc.ya;
      }
  return (0);
}
