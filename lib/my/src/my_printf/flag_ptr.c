/*
** flag_ptr.c for my_printf in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sat Nov  7 18:02:00 2015 Ronan Boiteau
** Last update Tue Dec  1 02:56:59 2015 Ronan Boiteau
*/

#include "my.h"
#include "variadic.h"

unsigned int	_ptr_to_hex(int fd, unsigned int printed, va_list ap)
{
  int		*ptr;

  ptr = va_arg(ap, void *);
  if (ptr == NULL)
    {
      my_putstr_fd(fd, "(nil)");
      return (my_strlen("(nil)"));
    }
  printed += my_putstr_fd(fd, "0x");
  printed += my_putnbr_base_ull(fd, (unsigned long long)ptr, "0123456789abcdef");
  return (printed);
}

unsigned int	_ptr_printed_chars(int fd, unsigned int printed, va_list ap)
{
  int		*ptr;

  (void)fd;
  ptr = va_arg(ap, int *);
  *ptr = printed;
  return (printed);
}
