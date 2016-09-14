/*
** fct_keys.c for main.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_my_select
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Thu May  5 17:52:52 2016 jeremy thiriez
** Last update Thu May 12 02:27:23 2016 jeremy thiriez
*/

#include "my_select.h"

int	underline_down(t_sel *sel)
{
  if (sel->tmp->next->space == 0)
    next_no_select_down(sel);
  else
    next_select_down(sel);
  return (EXIT_SUCCESS);
}

int	underline_up(t_sel *sel)
{
  if (sel->tmp->prev->space == 0)
    next_no_select_up(sel);
  else
    next_select_up(sel);
  return (EXIT_SUCCESS);
}
