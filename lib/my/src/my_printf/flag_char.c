/*
** flag_char.c for my_printf in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sat Nov  7 18:05:08 2015 Ronan Boiteau
** Last update Tue Dec  1 02:49:15 2015 Ronan Boiteau
*/

#include "my.h"
#include "variadic.h"

unsigned int	_print_char(int fd, unsigned int printed, va_list ap)
{
  printed += my_putchar_fd(fd, va_arg(ap, int));
  return (printed);
}
