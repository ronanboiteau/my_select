/*
** attributes.c for my_select in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Fri Dec 11 04:06:02 2015 Ronan Boiteau
** Last update Sun Dec 13 21:16:07 2015 Ronan Boiteau
*/

#include "my.h"
#include "my_select_ncurses.h"

void		_set_attributes(WINDOW *win,
				t_node *tmp,
				int idx,
				int current)
{
  if (idx == current)
    {
      if (wattron(win, A_UNDERLINE) == ERR)
	my_exit(EXIT_FAILURE, "wattron() failed!\n");
    }
  if (tmp->selected == TRUE)
    {
      if (wattron(win, A_REVERSE) == ERR)
	my_exit(EXIT_FAILURE, "wattron() failed!\n");
    }
  return ;
}

t_node		*_reset_attr(WINDOW *win, t_node *tmp, int *idx)
{
  if (wattroff(win, A_UNDERLINE | A_REVERSE) == ERR)
    my_exit(EXIT_FAILURE, "wattron() failed!\n");
  *idx += 1;
  return (tmp->next);
}
