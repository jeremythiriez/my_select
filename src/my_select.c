/*
** my_select.c for my_select.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_my_select
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Wed May  4 17:41:57 2016 jeremy thiriez
** Last update Sun May 15 17:21:47 2016 jeremy thiriez
*/

#include "my_select.h"

int		init_select(t_sel *sel)
{
  if ((sel->screen = newterm(NULL, stdin, NULL)) == NULL)
    return (EXIT_FAILURE);
  sel->cols = COLS;
  sel->lines = LINES;
  if (sel->cols == 0 || sel->lines == 0)
    return (EXIT_FAILURE);
  sel->key = 0;
  find_big_size_arg(sel);
  sel->tmp = sel->list;
  keypad(stdscr, TRUE);
  curs_set(0);
  noecho();
  return (EXIT_SUCCESS);
}

int		check_error(t_sel *sel)
{
  t_list	*tmp;

  tmp = NULL;
  while (tmp != sel->list)
    {
      if (tmp == NULL)
	tmp = sel->list;
      if (tmp->x + sel->big_arg > sel->cols)
	{
	  endwin();
	  write(2, "error: too many arguments for this window\n", 42);
	  return (EXIT_FAILURE);
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

void		find_big_size_arg(t_sel *sel)
{
  t_list	*tmp;
  int		save;

  tmp = NULL;
  save = 0;
  sel->big_arg = 0;
  while (tmp != sel->list)
    {
      if (tmp == NULL)
	tmp = sel->list;
      save = my_strlen(tmp->arg);
      if (save > sel->big_arg)
	sel->big_arg = save;
      tmp = tmp->next;
    }
}

int		my_select(t_sel *sel)
{
  display_list(sel);
  while (sel->key != ESCAPE)
    {
      if (check_error(sel) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      sel->key = getch();
      if (sel->lines != LINES || sel->cols != COLS)
	display_list(sel);
      if (key(sel) == EXIT_FAILURE)
	{
	  endwin();
	  delscreen(sel->screen);
	  return (EXIT_FAILURE);
	}
      refresh();
    }
  endwin();
  delscreen(sel->screen);
  return (EXIT_SUCCESS);
}
