#ifndef MY_SELECT_ACTION_H_
# define MY_SELECT_ACTION_H_

# include "list.h"

# define MY_KEY_ESC (27)

t_node		*_remove_node(t_node *list_start, int current);
void		_reverse_selection(t_node *list_start, int current);

#endif /* !MY_SELECT_ACTION_H_ */
