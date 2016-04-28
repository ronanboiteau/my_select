/*
** printf_flags.h for my_printf in /home/boitea_r/c/lib/my/src
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Fri Dec  4 22:35:02 2015 Ronan Boiteau
** Last update Fri Dec  4 22:35:44 2015 Ronan Boiteau
*/

#ifndef PRINTF_FLAGS_H_
# define PRINTF_FLAGS_H_

# include <stdarg.h>
# include "string.h"

# define FLAGS_NBR (12)

typedef struct	s_flag
{
  unsigned int	(*fct)(int fd, unsigned int printed, va_list ap);
  char		flag_char;
}		t_flag;

int		_char_isflag(char letter, t_flag *flags);
int		_char_isletter(char letter);
unsigned int	_print_char(int fd, unsigned int printed, va_list ap);
unsigned int	_print_str(int fd, unsigned int printed, va_list ap);
unsigned int	_str_non_printable(int fd, unsigned int printed, va_list ap);
unsigned int	_print_int(int fd, unsigned int printed, va_list ap);
unsigned int	_convert_binary(int fd, unsigned int printed, va_list ap);
unsigned int	_convert_decimal(int fd, unsigned int printed, va_list ap);
unsigned int	_convert_hex_lowcase(int fd, unsigned int printed, va_list ap);
unsigned int	_convert_hex_upcase(int fd, unsigned int printed, va_list ap);
unsigned int	_convert_octal(int fd, unsigned int printed, va_list ap);
unsigned int	_ptr_to_hex(int fd, unsigned int printed, va_list ap);
unsigned int	_ptr_printed_chars(int fd, unsigned int printed, va_list ap);
unsigned int	_double_decimal(int fd, unsigned int printed, va_list ap);
int		_init_flag(char flag_char,
			   unsigned int (*fct)(int fd,
					       unsigned int printed,
					       va_list ap),
			   t_flag *flags);
void		_init_structures(t_flag *flags,
				 t_string *str,
				 const char *format);
const char	*_find_flag(t_string *str,
			    unsigned int *printed,
			    int fd,
			    va_list ap);

#endif /* !PRINTF_FLAGS_H_ */
