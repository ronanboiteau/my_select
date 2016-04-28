/*
** list.h for push_swap in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Nov  8 18:48:40 2015 Ronan Boiteau
** Last update Fri Dec 11 04:09:36 2015 Ronan Boiteau
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_node
{
  struct s_node	*next;
  char		*str;
  int		arg_rank;
  int		selected;
}		t_node;

int		_count_elems_list(t_node *list_start);
int		_put_in_list(t_node *list_ptr, char *str, int arg_rank);
int		_init_list(t_node *list_start, char **argv);
int		_find_longest_arg(t_node *list_ptr);

#endif /* !LIST_H_ */
