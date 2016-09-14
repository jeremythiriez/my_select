/*
** display.c for display.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_my_select
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Thu May 12 22:42:22 2016 jeremy thiriez
** Last update Sun May 15 21:23:20 2016 jeremy thiriez
*/

#include "my_select.h"

void		select_display(t_sel *sel, int i, int j)
{
  if (sel->begin->space == 1)
    {
      attron(A_REVERSE);
      printw(sel->begin->arg);
      attroff(A_REVERSE);
      sel->begin->y = i;
      sel->begin->x = j;
    }
  else
    {
      printw(sel->begin->arg);
      sel->begin->y = i;
      sel->begin->x = j;
    }
}

void		display_list(t_sel *sel)
{
  int           i;
  int           j;

  i = 0;
  j = 0;
  clear();
  sel->begin = NULL;
  sel->lines = LINES;
  sel->cols = COLS;
  while (sel->begin != sel->list)
    {
      move(i, j);
      if (sel->begin == NULL)
	sel->begin = sel->list;
      select_display(sel, i, j);
      i++;
      if (i == sel->lines)
	{
	  i = 0;
	  j += sel->big_arg + 5;
	}
      sel->begin = sel->begin->next;
    }
  underline_line(sel);
  refresh();
}
