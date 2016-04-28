##
## Makefile for my_select in /home/boitea_r
## 
## Made by Ronan Boiteau
## Login   <boitea_r@epitech.net>
## 
## Started on  Wed Dec  2 17:59:10 2015 Ronan Boiteau
## Last update Sun Dec 13 22:33:50 2015 Ronan Boiteau
##

NAME	= my_select

IDIR	= include/

LIB	= libmy.a
LNAME	= my
LDIR	= lib/my

CC	= gcc
CFLAGS	+= -I $(IDIR)
CFLAGS	+= -Wall -Werror -Wextra -ansi

SDIR	= src/
SRCS	= $(SDIR)actions.c		\
	  $(SDIR)attributes.c		\
	  $(SDIR)error.c		\
	  $(SDIR)input_manager.c	\
	  $(SDIR)list.c			\
	  $(SDIR)main.c			\
	  $(SDIR)print.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f


all: $(LIB) $(NAME)

$(LIB):
	cd $(LDIR) && $(MAKE)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L lib -l $(LNAME) -lncurses

clean:
	$(RM) $(OBJS)
	cd $(LDIR) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	cd $(LDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
