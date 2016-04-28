/*
** my_select_ncurses.h for my_select in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Dec  7 21:37:02 2015 Ronan Boiteau
** Last update Sun Dec 13 22:33:08 2015 Ronan Boiteau
*/

#ifndef MY_SELECT_NCURSES_H_
# define MY_SELECT_NCURSES_H_

# include <ncurses.h>
# include "list.h"

# define COL_PADDING (1)

t_node		*_selection_window(t_node *list_start);
void		_input_iskey(t_node *list_start, int input, int *current);
t_node		*_input_isbackspace(t_node *list_start,
				    int input,
				    int *current,
				    int *longest_arg);
void		_input_isspace(t_node *list_start, int input, int *current);
t_node		*_input_isexit(t_node *list_start, int input);
void		_set_attributes(WINDOW *win,
				t_node *tmp,
				int idx,
				int current);
t_node		*_reset_attr(WINDOW *win, t_node *tmp, int *idx);
void		_exit_too_long(void);

#endif /* !MY_SELECT_NCURSES_H_ */
