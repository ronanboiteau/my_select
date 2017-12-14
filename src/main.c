#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "my_macro.h"
#include "my_select_ncurses.h"
#include "list.h"

static void		_print_selected(t_node *list_start, int first_pass)
{
  t_node		*tmp;

  tmp = list_start;
  if (tmp->selected == true)
    {
      my_printf("%s", tmp->str);
      first_pass = false;
    }
  tmp = tmp->next;
  while (tmp != list_start)
    {
      if (tmp->selected == true)
	{
	  if (first_pass == true)
	    {
	      my_printf("%s", tmp->str);
	      first_pass = false;
	    }
	  else
	    my_printf(" %s", tmp->str);
	}
      tmp = tmp->next;
    }
  return ;
}

int			main(int argc, char **argv)
{
  t_node		*list_start;
  t_node		*list_end;

  if (argc < 2)
    my_exit(EXIT_FAILURE,
  	    "Usage: ./my_select [choice_1] [choice_2] [choice_3] [...]\n");
  if ((list_start = malloc(sizeof(t_node))) == NULL)
    my_exit(EXIT_FAILURE,"Out of memory! malloc() failed\n");
  list_start->str = argv[1];
  list_start->arg_rank = 1;
  list_start->selected = false;
  list_end = list_start;
  list_end->next = list_start;
  _init_list(list_start, argv);
  if ((list_start = _selection_window(list_start)) != NULL)
    _print_selected(list_start, true);
  free(list_start);
  return (EXIT_SUCCESS);
}
