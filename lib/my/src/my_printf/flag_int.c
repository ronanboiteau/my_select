/*
** flag_int.c for my_printf in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sat Nov  7 04:20:32 2015 Ronan Boiteau
** Last update Tue Dec  1 02:52:18 2015 Ronan Boiteau
*/

#include "my.h"
#include "variadic.h"

unsigned int	_print_int(int fd, unsigned int printed, va_list ap)
{
  printed += my_putnbr_printf(fd, va_arg(ap, int));
  return (printed);
}
