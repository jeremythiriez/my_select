/*
** fct_keys_next2.c for fct_keys_next2.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_my_select
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Thu May  5 23:34:32 2016 jeremy thiriez
** Last update Sat May 14 07:00:02 2016 jeremy thiriez
*/

#include "my_select.h"

void	next_no_select_down(t_sel *sel)
{
  put_in_normal(sel);
  if (sel->tmp->space == 1)
    reverse_line(sel);
  underline_down_line(sel);
}

void	next_select_down(t_sel *sel)
{
  put_in_normal(sel);
  if (sel->tmp->space == 1)
    reverse_line(sel);
  move_down(sel);
  underline_reverse_line(sel);
}

void	next_no_select_up(t_sel *sel)
{
  put_in_normal(sel);
  if (sel->tmp->space == 1)
    reverse_line(sel);
  underline_up_line(sel);
}

void	next_select_up(t_sel *sel)
{
  put_in_normal(sel);
  if (sel->tmp->space == 1)
    reverse_line(sel);
  move_up(sel);
  underline_reverse_line(sel);
}
