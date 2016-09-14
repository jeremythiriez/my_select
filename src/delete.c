/*
** delete.c for delete.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_my_select
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Thu May 12 02:25:26 2016 jeremy thiriez
** Last update Sat May 14 06:49:33 2016 jeremy thiriez
*/

#include "my_select.h"

void		select_delete(t_sel *sel)
{
  if (sel->tmp->prev == sel->list->prev)
    {
      sel->tmp = sel->tmp->prev;
      move_down(sel);
      if (sel->tmp->space == 0)
	underline_line(sel);
      else
	underline_reverse_line(sel);
    }
  else
    {
      move(sel->tmp->y, 0);
      if (sel->tmp->space == 0)
	underline_line(sel);
      else
	underline_reverse_line(sel);
    }
}

int		delete(t_sel *sel)
{
  t_list	*new;

  if (sel->tmp == sel->tmp->prev)
    return (EXIT_FAILURE);
  if (sel->tmp == sel->list)
    sel->list = sel->list->next;
  sel->tmp->prev->next = sel->tmp->next;
  sel->tmp->next->prev = sel->tmp->prev;
  new = sel->tmp;
  sel->tmp = sel->tmp->next;
  free(new);
  clear();
  move(0, 0);
  find_big_size_arg(sel);
  display_list(sel);
  select_delete(sel);
  return (EXIT_SUCCESS);
}
