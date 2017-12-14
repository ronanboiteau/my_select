#include <stdlib.h>
#include "my.h"
#include "my_select_actions.h"
#include "my_select_ncurses.h"
#include "list.h"

void		_input_iskey(t_node *list_start, int input, int *current)
{
  if (input == KEY_UP || input == 65)
    {
      if (*current == 1)
	*current = _count_elems_list(list_start);
      else
	*current -= 1;
    }
  else if (input == KEY_DOWN || input == 66 || input == 94)
    {
      if (*current == _count_elems_list(list_start))
	*current = 1;
      else
	*current += 1;
    }
  return ;
}

t_node		*_input_isbackspace(t_node *list_start,
				    int input,
				    int *current,
				    int *longest_arg)
{
  if (input == KEY_BACKSPACE || input == 127)
    {
      if ((list_start = _remove_node(list_start, *current)) == NULL)
	{
	  if (clear() == ERR || endwin() == ERR)
	    my_exit(EXIT_FAILURE, "Failed to exit ncurses window!\n");
	  return (NULL);
	}
      if (*current > _count_elems_list(list_start))
	*current = _count_elems_list(list_start);
      *longest_arg = _find_longest_arg(list_start);
    }
  return (list_start);
}

void		_input_isspace(t_node *list_start, int input, int *current)
{
  if (input == ' ')
    {
      _reverse_selection(list_start, *current);
      if (*current == _count_elems_list(list_start))
	*current = 1;
      else
	*current += 1;
    }
  return ;
}

t_node		*_input_isexit(t_node *list_start, int input)
{
  if (clear() == ERR || endwin() == ERR)
    my_exit(EXIT_FAILURE, "Failed to exit ncurses window!\n");
  if (input == MY_KEY_ESC)
    exit(EXIT_SUCCESS);
  else if (input == KEY_ENTER || input == '\n')
    {
      if (clear() == ERR || endwin() == ERR)
	my_exit(EXIT_FAILURE, "Failed to exit ncurses window!\n");
      return (list_start);
    }
  return (NULL);
}
