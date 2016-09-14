/*
** fct_keys_next3.c for fct_keys_next3.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_my_select
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Thu May  5 22:54:00 2016 jeremy thiriez
** Last update Thu May 12 20:20:34 2016 jeremy thiriez
*/

#include "my_select.h"

void	reverse_line(t_sel *sel)
{
  move(sel->tmp->y, sel->tmp->x);
  attron(A_REVERSE);
  printw(sel->tmp->arg);
  attroff(A_REVERSE);
}

void    underline_line(t_sel *sel)
{
  move(sel->tmp->y, sel->tmp->x);
  attron(A_UNDERLINE);
  printw(sel->tmp->arg);
  attroff(A_UNDERLINE);
}

void    put_in_normal(t_sel *sel)
{
  move(sel->tmp->y, sel->tmp->x);
  attron(A_NORMAL);
  printw(sel->tmp->arg);
  attroff(A_NORMAL);
}

void	underline_reverse_line(t_sel *sel)
{
  move(sel->tmp->y, sel->tmp->x);
  attron(A_UNDERLINE);
  attron(A_REVERSE);
  printw(sel->tmp->arg);
  attroff(A_UNDERLINE);
  attroff(A_REVERSE);
}
