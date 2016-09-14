/*
** enter.c for enter.c in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_my_select
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Thu May 12 03:10:47 2016 jeremy thiriez
** Last update Sun May 15 22:32:35 2016 jeremy thiriez
*/

#include "my_select.h"

void		my_put_tty(char *str, int fd)
{
  int		i;

  i = 0;
  (void)fd;
  while (str[i])
    {
      write(1, &str[i], 1);
      i++;
    }
}

int		enter(t_sel *sel)
{
  t_list	*tmp;
  int		i;
  int		fd;

  endwin();
  delscreen(sel->screen);
  fd = ioctl(0, TIOCNOTTY);
  i = 0;
  tmp = NULL;
  while (tmp != sel->list)
    {
      if (tmp == NULL)
	tmp = sel->list;
      if (tmp->space == 1)
	{
	  if (i > 0)
	    my_putchar(' ');
	  my_put_tty(tmp->arg, fd);
	  i++;
	}
      tmp = tmp->next;
    }
  return (EXIT_FAILURE);
}
