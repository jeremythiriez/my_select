/*
** main.c for main.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_my_select
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Wed May  4 15:54:13 2016 jeremy thiriez
** Last update Sat May 14 07:18:39 2016 jeremy thiriez
*/

#include "my_select.h"

t_list		*my_create_elem(char *arg)
{
  t_list	*node;

  if ((node = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  node->arg = arg;
  node->space = 0;
  node->x = 0;
  node->y = 0;
  node->next = node;
  node->prev = node;
  return (node);
}

t_list		*my_create_list(int ac, char **av)
{
  int		i;
  t_list	*list;
  t_list	*tmp;
  t_list	*node;

  i = 2;
  if ((list = my_create_elem(av[1])) == NULL)
    return (NULL);
  while (i < ac)
    {
      tmp = list->prev;
      if ((node = my_create_elem(av[i])) == NULL)
	return (NULL);
      tmp->next = node;
      node->prev = tmp;
      node->next = list;
      list->prev = node;
      i++;
    }
  return (list);
}
