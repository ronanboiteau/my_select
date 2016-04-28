/*
** my_strlen.c for my_strlen in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Oct  5 02:49:33 2015 Ronan Boiteau
** Last update Mon Nov 23 21:45:58 2015 Ronan Boiteau
*/

#include "my.h"

int		my_strlen(const char *str)
{
  int		idx;

  if (str == NULL)
    return (0);
  idx = 0;
  while (str[idx] != '\0')
    idx += 1;
  return (idx);
}
