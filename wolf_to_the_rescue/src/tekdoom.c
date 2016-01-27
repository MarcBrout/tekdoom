/*
** tekdoom.c for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Dec 17 15:25:21 2015 marc brout
** Last update Wed Jan 27 03:26:35 2016 marc brout
*/

#include "tekdoom.h"
#include "menu.h"

void		whats_up(char **av, int err)
{
  if (err == 1)
    {
      write(2, av[1], my_strlen(av[1]));
      write(2, "file corrupted, execution aborted.\n", 37);
    }
  if (err == 2)
    write(2, "Trouble loading map, executon aborted.\n", 40);
}

void		set_cossin(t_param *arg)
{
  int		i;

  i = -1;
  while (++i < arg->WIDTH)
    {
      arg->wm.ydep[i] = (arg->calc.p * (arg->WIDTH / 2 - i)) / arg->WIDTH;
      if (i < 360)
	{
	  arg->wm.costab[i] = cos((double)RAD(i));
	  arg->wm.sintab[i] = sin((double)RAD(i));
	}
    }
}

char		launch_tekdoom(t_param *arg , char **av)
{
  pos_pix_ar(arg->data);
  arg->calc.p = 1;
  arg->calc.d = 0.5;
  arg->hight = 0;
  arg->chrono = -1;
  arg->jump = 0;
  arg->speedy = 0;
  arg->vit = 0;
  arg->calc.mini = arg->HEIGHT / 50;
  if (get_textures(arg) || open_ini(arg, av) ||
      check_all_lvl(arg) || mal_tablvl(arg))
    return (1);
  if (get_tabmap(arg))
    return (2);
  set_cossin(arg);
  if (aff_tekdoom(arg))
    return (2);
  bunny_delete_ini(arg->ini);
  free_all(arg);
  return (0);
}

int		launch_start(char **av)
{
  t_param	arg;
  int		err;

  if ((arg.data = bunny_malloc(sizeof(t_data))) == NULL)
    return (3);
  start(arg.data);
  if ((arg.wm.ydep = bunny_malloc(sizeof(double) * arg.WIDTH)) == NULL)
  arg.trans = false;
    return (1);
  if ((err = launch_tekdoom(&arg, av)))
    {
      whats_up(av, err);
      return (1);
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  set_max_heap_size(50);
  if (check_args(ac, env))
    return (1);
  if (launch_start(av) != 0)
    return (1);
  return (0);
}
