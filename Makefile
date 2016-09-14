##
## Makefile for Makefile in /home/thirie_a/rendu/Piscine_C_J10
##
## Made by jeremy thiriez
## Login   <thirie_a@epitech.net>
##
## Started on  Fri Mar 11 15:30:08 2016 jeremy thiriez
## Last update Sun May 15 21:43:53 2016 jeremy thiriez
##

NAME	= my_select

CC	= gcc

RM	= rm -rf

SRCS	= src/main.c \
	  src/my_select.c \
	  src/create_list.c \
	  tools/my_putstr.c \
	  tools/my_putchar.c \
	  src/underline.c \
	  src/underline_select.c \
	  src/moove.c \
	  src/modif_line.c \
	  src/delete.c \
	  src/enter.c \
	  src/reverse.c \
	  src/key.c \
	  tools/my_strlen.c \
	  src/display.c \
	  src/move_right_left.c

CFLAGS	+= -W -Wall -Wextra -Werror -I./include

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean all re
