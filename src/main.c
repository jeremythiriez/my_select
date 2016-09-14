/*
** main.c for main.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_my_select
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Wed May  4 16:30:17 2016 jeremy thiriez
** Last update Sun May 15 22:30:30 2016 jeremy thiriez
*/

#include "my_select.h"

void		free_list(t_sel *sel)
{
  sel->tmp = sel->list->prev;
  while (sel->list != sel->tmp)
    {
      sel->list = sel->list->next;
      free(sel->list->prev);
    }
  free(sel->tmp);
}

int		main(int ac, char **av, char **env)
{
  t_sel		sel;

  sel.nb_arg = ac - 1;
  if (env[0] == NULL)
    return (EXIT_FAILURE);
  if (ac > 1)
    {
      if ((sel.list = malloc(sizeof(t_list))) == NULL)
	return (EXIT_FAILURE);
      if ((sel.list = my_create_list(ac, av)) == NULL)
	return (EXIT_FAILURE);
      if (init_select(&sel) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (my_select(&sel) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      free_list(&sel);
    }
  return (EXIT_SUCCESS);
}
