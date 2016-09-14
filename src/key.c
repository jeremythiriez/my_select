/*
** key.c for key.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_my_select
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Wed May  4 22:32:42 2016 jeremy thiriez
** Last update Sat May 14 05:56:31 2016 jeremy thiriez
*/

#include "my_select.h"

void		init_tab(t_fonc *tab)
{
  tab[0].keys = KEY_DOWN;
  tab[1].keys = KEY_UP;
  tab[2].keys = SPACE;
  tab[3].keys = KEY_BACKSPACE;
  tab[4].keys = ENTER;
  tab[5].keys = RIGHT;
  tab[6].keys = LEFT;
  tab[7].keys = DELETE;
  tab[8].keys = 0;
  tab[0].fonc = &underline_down;
  tab[1].fonc = &underline_up;
  tab[2].fonc = &reverse;
  tab[3].fonc = &delete;
  tab[4].fonc = &enter;
  tab[5].fonc = &move_right;
  tab[6].fonc = &move_left;
  tab[7].fonc = &delete;
  tab[8].fonc = 0;
}

int		key(t_sel *sel)
{
  int		i;
  t_fonc	tab[9];

  i = 0;
  init_tab(tab);
  while (tab[i].keys != sel->key && tab[i].keys != 0)
    i++;
  if (tab[i].fonc != 0)
    if (tab[i].fonc(sel) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
