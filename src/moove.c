/*
** fct_keys_next2.c for fct_keys_next2.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_my_select
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Thu May  5 22:42:22 2016 jeremy thiriez
** Last update Sat May 14 06:45:12 2016 jeremy thiriez
*/

#include "my_select.h"

void	move_down(t_sel *sel)
{
  sel->tmp = sel->tmp->next;
  move(sel->tmp->y, sel->tmp->x);
}

void	move_up(t_sel *sel)
{
  sel->tmp = sel->tmp->prev;
  move(sel->tmp->y, sel->tmp->x);
}

void    underline_up_line(t_sel *sel)
{
  move_up(sel);
  underline_line(sel);
}

void    underline_down_line(t_sel *sel)
{
  move_down(sel);
  underline_line(sel);
}
