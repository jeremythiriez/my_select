/*
** my_putchar.c for my_putchar.c in /home/thirie_a/rendu/fonctions
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Tue Mar  8 10:19:05 2016 jeremy thiriez
** Last update Wed May  4 16:34:53 2016 jeremy thiriez
*/

#include "my_select.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
