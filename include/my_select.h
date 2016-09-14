/*
** my_select.h for my_select.h in /home/thirie_a/tech_1/Prog_System_Unix/PSU_2015_my_select
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Wed May  4 15:57:08 2016 jeremy thiriez
** Last update Wed Sep 14 08:36:48 2016 jeremy thiriez
*/

#ifndef _MY_SELECT_H_
# define _MY_SELECT_H_

#define ESCAPE 27
#define SPACE 32
#define ENTER 10
#define RIGHT 261
#define LEFT 260
#define DELETE 330

#include <ncurses.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_list
{
  char		*arg;
  int		x;
  int		y;
  int		space;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef struct	s_sel
{
  t_list	*list;
  t_list	*tmp;
  t_list	*begin;
  int		cols;
  int		lines;
  int		key;
  int		nb_arg;
  int		big_arg;
  SCREEN	*screen;
}		t_sel;

typedef struct	s_fonc
{
  int		keys;
  int		(*fonc)(t_sel *sel);
}		t_fonc;

int		key(t_sel *sel);
t_list		*my_create_elem(char *arg);
t_list		*my_create_list(int ac, char **av);
int		my_print_list(t_list *list);
int		my_putstr(char *str);
void		my_putchar(char c);
int		my_select(t_sel *sel);
int		underline_down(t_sel *sel);
int		underline_up(t_sel *sel);
int		reverse(t_sel *sel);
void		end_list_down(t_sel *sel);
void		underline_down_line(t_sel *sel);
void		begin_list_up(t_sel *sel);
void		underline_up_line(t_sel *sel);
void		put_in_normal(t_sel *sel);
void		underline_line(t_sel *sel);
void		move_down(t_sel *sel);
void		move_up(t_sel *sel);
void		reverse_line(t_sel *sel);
void		next_no_select_down(t_sel *sel);
void		next_select_down(t_sel *sel);
void		next_no_select_up(t_sel *sel);
void		next_select_up(t_sel *sel);
void		select_reverse(t_sel *sel);
void		underline_reverse_line(t_sel *sel);
void		display_list(t_sel *sel);
int		delete(t_sel *sel);
int		enter(t_sel *sel);
int		init_select(t_sel *sel);
int		my_strlen(char *str);
int		move_right(t_sel *sel);
int		move_left(t_sel *sel);
void		find_big_size_arg(t_sel *sel);

#endif /* !_MY_SELECT_H_ */
