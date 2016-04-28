/*
** error.c for my_select in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Dec 13 22:32:11 2015 Ronan Boiteau
** Last update Sun Dec 13 22:34:13 2015 Ronan Boiteau
*/

#include "my.h"
#include "my_select_ncurses.h"

void		_exit_too_long(void)
{
  if (clear() == ERR || endwin() == ERR)
    my_exit(EXIT_FAILURE, "Failed to exit ncurses window!\n");
  else
    my_exit(EXIT_FAILURE, "X Window too small for arguments\n");
  return ;
}
