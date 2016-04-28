/*
** my_select_actions.h for my_select in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Dec  8 11:16:09 2015 Ronan Boiteau
** Last update Fri Dec 11 03:54:01 2015 Ronan Boiteau
*/

#ifndef MY_SELECT_ACTION_H_
# define MY_SELECT_ACTION_H_

# include "list.h"

# define MY_KEY_ESC (27)

t_node		*_remove_node(t_node *list_start, int current);
void		_reverse_selection(t_node *list_start, int current);

#endif /* !MY_SELECT_ACTION_H_ */
