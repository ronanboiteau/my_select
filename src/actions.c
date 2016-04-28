#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "my_macro.h"
#include "list.h"

static void	_update_ranks(t_node *stop_elem,
			      t_node *tmp)
{
  int		idx;

  idx = 2;
  while (tmp != stop_elem)
    {
      tmp->arg_rank = idx;
      idx += 1;
      tmp = tmp->next;
    }
  return ;
}

t_node		*_remove_node(t_node *list_start, int current)
{
  t_node	*node_to_rm;
  t_node	*node_before;
  t_node	*tmp;
  t_node	*stop_elem;

  node_to_rm = list_start;
  if (node_to_rm->next == list_start)
    return (NULL);
  while (node_to_rm->arg_rank != current)
    node_to_rm = node_to_rm->next;
  node_before = list_start;
  while (node_before->next != node_to_rm)
    node_before = node_before->next;
  node_before->next = node_to_rm->next;
  if (current == 1)
    stop_elem = node_before->next;
  else
    stop_elem = list_start;
  tmp = stop_elem;
  tmp->arg_rank = 1;
  _update_ranks(stop_elem, tmp->next);
  return (stop_elem);
}

void		_reverse_selection(t_node *list_start, int current)
{
  t_node	*tmp;

  tmp = list_start;
  while (tmp->arg_rank != current)
    tmp = tmp->next;
  if (tmp->selected == true)
    tmp->selected = false;
  else
    tmp->selected = true;
  return ;
}
