/*
** reverse.c for reverse.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_my_select
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Thu May 12 02:27:03 2016 jeremy thiriez
** Last update Sat May 14 07:09:02 2016 jeremy thiriez
*/

#include "my_select.h"

void	select_reverse_on(t_sel *sel)
{
  if (sel->tmp == sel->list->prev)
    {
      move_down(sel);
      if (sel->tmp->space == 1)
	underline_reverse_line(sel);
      else
	underline_line(sel);
    }
  else
    {
      if (sel->tmp->next->space == 0)
	underline_down_line(sel);
      else
	{
	  move_down(sel);
	  underline_reverse_line(sel);
	}
    }
}

void	select_reverse_off(t_sel *sel)
{
  if (sel->tmp->next->space == 0)
    {
      if (sel->tmp == sel->list->prev)
	{
	  move_down(sel);
	  underline_line(sel);
	}
      else
	underline_down_line(sel);
    }
  else
    {
      if (sel->tmp == sel->list->prev)
	move_down(sel);
      else
	move_down(sel);
      underline_reverse_line(sel);
    }
}

int	 reverse(t_sel *sel)
{
  if (sel->tmp->space == 0)
    {
      put_in_normal(sel);
      reverse_line(sel);
      sel->tmp->space = 1;
      select_reverse_off(sel);
    }
  else
    {
      put_in_normal(sel);
      sel->tmp->space = 0;
      select_reverse_on(sel);
    }
  return (EXIT_SUCCESS);
}
