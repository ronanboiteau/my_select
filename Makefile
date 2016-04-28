NAME	= my_select

IDIR	= include/
IDIR_MY	= lib/my/include/

LIB	= libmy.a
LNAME	= my
LDIR	= lib/my/

CC	= gcc
CFLAGS	+= -I $(IDIR) -I $(IDIR_MY)
CFLAGS	+= -Wall -Werror -Wextra -ansi

SRCS_DIR	= src/
SRCS_FILES	= actions.c		\
		  attributes.c		\
		  error.c		\
		  input_manager.c	\
		  list.c		\
		  main.c		\
		  print.c
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	= $(SRCS:.c=.o)

RM	= rm -f


all: $(LIB) $(NAME)

$(LIB):
	make -C $(LDIR)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L $(LDIR) -l $(LNAME) -lncurses

clean:
	$(RM) $(OBJS)
	make -C $(LDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LDIR) fclean

re: fclean all

.PHONY: all clean fclean re
