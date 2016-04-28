/*
** my_putstr.c for my_putstr in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Oct  6 09:33:22 2015 Ronan Boiteau
** Last update Fri Nov 27 21:05:50 2015 Ronan Boiteau
*/

#include "my.h"
#include "my_macro.h"

unsigned int	my_putstr_fd(int fd, const char *str)
{
  if (str == NULL)
    {
      write(fd, "(null)", my_strlen("(null)"));
      return (my_strlen("(null)"));
    }
  write(fd, str, my_strlen(str));
  return (my_strlen(str));
}

unsigned int	my_putstr(const char *str)
{
  return (my_putstr_fd(STDOUT, str));
}
