/*
** ai.c for tekdoom in /home/sauvau_m/rendu/gfx_tekdoom/ia
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Jan 24 11:29:48 2016 Mathieu Sauvau
** Last update Sun Jan 24 11:59:16 2016 Mathieu Sauvau
*/

#include "main.h"

t_bunny_position        pol_to_carth(t_bunny_position *pol)
{
  t_bunny_position      convert;

  convert.x = pol->x * cos(pol->y * M_PI / 180);
  convert.y = pol->x * sin(pol->y * M_PI / 180);
  return (convert);
}

t_bunny_position        carth_to_pol(t_bunny_position *carth)
{
  t_bunny_position      convert;

  convert.x = sqrt(pow(carth->x, 2) + pow(carth->y, 2));
  convert.y = atan2(carth->x, carth->y);
  return (convert);
}

bool			in_range(t_bunny_position e_pos, t_bunny_position p_pos, int range)
{
  if (abs(p_pos.x - e_pos.x) <= range && abs(p_pos.y - e_pos.y) <= range)
    return (true);
  return (false);
}

bool			is_wall_ahead(t_lvl *lvl, t_enemy *enemy)
{
  t_bunny_position	point;

  point = pol_to_carth(&enemy->view);
  point.x += enemy->pos.x;
  point.y += enemy->pos.y;
  // esce que ce poit la resout lequation des segments alors = mur
  //tourner l'enemy dans le meilleur sens recomencer

}

void			move(t_enemy *enemy)
{
  //check if wall
  enemy->pos.x = cos(enemy->view.y * M_PI / 180) / 5;
  enemy->pos.y = sin(enemy->view.y * M_PI / 180) / 5;

}
