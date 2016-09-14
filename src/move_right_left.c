/*
** move_right_left.c for move_right_left.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_my_select
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Sat May 14 02:26:58 2016 jeremy thiriez
** Last update Sat May 14 05:26:51 2016 jeremy thiriez
*/

#include "my_select.h"

void	my_aff(t_sel *sel, int i)
{
  if (i == 1)
    {
      if (sel->tmp->space == 0)
	put_in_normal(sel);
      else
	reverse_line(sel);
    }
  else
    {
      if (sel->tmp->space == 1)
	underline_reverse_line(sel);
      else
	underline_line(sel);
    }
}

int	move_right(t_sel *sel)
{
  int	x;
  int	y;

  x = sel->tmp->x + 1;
  y = sel->tmp->y;
  my_aff(sel, 1);
  if (x < sel->list->prev->x)
    while (sel->tmp->x < x)
      sel->tmp = sel->tmp->next;
  else
    {
      x = 0;
      while (sel->tmp->x > x)
	sel->tmp = sel->tmp->next;
    }
  while (sel->tmp->y < y)
    sel->tmp = sel->tmp->next;
  my_aff(sel, 0);
  return (EXIT_SUCCESS);
}

int	move_left(t_sel *sel)
{
  int	x;
  int	y;

  x = sel->tmp->x - 1;
  y = sel->tmp->y;
  my_aff(sel, 1);
  if (x < 0)
    {
      x = sel->list->prev->x;
      while (sel->tmp->x < x)
	sel->tmp = sel->tmp->prev;
      while (sel->tmp->y < y)
	sel->tmp = sel->tmp->prev;
      while (sel->tmp->y > y)
	sel->tmp = sel->tmp->prev;
    }
  else
    {
      while (sel->tmp->x > x)
	sel->tmp = sel->tmp->prev;
      while (sel->tmp->y > y)
	sel->tmp = sel->tmp->prev;
    }
  my_aff(sel, 0);
  return (EXIT_SUCCESS);
}
