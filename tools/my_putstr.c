/*
** my_putstr.c for my_putstr.c in /home/thirie_a/rendu/Piscine_C_J04
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Thu Mar  3 09:23:57 2016 jeremy thiriez
** Last update Wed May  4 16:34:40 2016 jeremy thiriez
*/

#include "my_select.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
