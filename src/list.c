#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "my_macro.h"
#include "list.h"

int		_find_longest_arg(t_node *list_ptr)
{
  t_node	*tmp;
  t_node	*longest;
  int		last_len;

  tmp = list_ptr;
  last_len = my_strlen(tmp->str);
  longest = tmp;
  tmp = tmp->next;
  while (tmp != list_ptr)
    {
      if (my_strlen(tmp->str) > last_len)
	{
	  last_len = my_strlen(tmp->str);
	  longest = tmp;
	}
      tmp = tmp->next;
    }
  return (my_strlen(longest->str));
}

int		_count_elems_list(t_node *list_start)
{
  t_node	*tmp;
  int		idx;

  idx = 0;
  tmp = list_start;
  idx += 1;
  tmp = tmp->next;
  while (tmp != list_start)
    {
      idx += 1;
      tmp = tmp->next;
    }
  return (idx);
}

int		_put_in_list(t_node *list_ptr, char *str, int arg_rank)
{
  t_node	*list_start;

  list_start = list_ptr;
  while (list_ptr->next != list_start)
    list_ptr = list_ptr->next;
  list_ptr->next = malloc(sizeof(t_node));
  if (list_ptr == NULL)
    return (EXIT_FAILURE);
  list_ptr = list_ptr->next;
  list_ptr->str = str;
  list_ptr->arg_rank = arg_rank;
  list_ptr->selected = false;
  list_ptr->next = list_start;
  return (EXIT_SUCCESS);
}

int		_init_list(t_node *list_start, char **argv)
{
  int		idx;

  idx = 2;
  while (argv[idx])
    {
      if (_put_in_list(list_start, argv[idx], idx) == EXIT_FAILURE)
	my_exit(EXIT_FAILURE, "malloc() failed: out of memory!\n");
      idx += 1;
    }
  return (EXIT_SUCCESS);
}
