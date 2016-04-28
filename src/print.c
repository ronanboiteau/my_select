#include <stdlib.h>
#include "list.h"
#include "my.h"
#include "my_macro.h"
#include "my_select_ncurses.h"
#include "my_select_actions.h"

static void	_handle_columns(int idx, int *column, int longest_arg)
{
  if ((idx - 1) % LINES == 0)
    *column += 1;
  if (((longest_arg + COL_PADDING) * (*column - 1)) + longest_arg > COLS)
    {
      if (clear() == ERR || endwin() == ERR)
	my_exit(EXIT_FAILURE, "Failed to exit ncurses window!\n");
      my_exit(EXIT_FAILURE, "X Window too small for arguments\n");
    }
  return ;
}

static t_node	*_init_print_args(t_node *list_start, int *column, int *idx)
{
  *idx = 1;
  *column = 0;
  return (list_start);
}

static void	_print_args(WINDOW *win,
			    int current,
			    t_node *list_start,
			    int longest_arg)
{
  t_node	*tmp;
  int		idx;
  int		column;

  tmp = _init_print_args(list_start, &column, &idx);
  if (wclear(win) == ERR)
    my_exit(EXIT_FAILURE, "wclear() failed!\n");
  _set_attributes(win, tmp, idx, current);
  _handle_columns(idx, &column, longest_arg);
  if (mvwprintw(win, (idx - 1) % LINES, ((longest_arg + COL_PADDING) *
					 (column - 1)), "%s", tmp->str) == ERR)
    _exit_too_long();
  tmp = _reset_attr(win, tmp, &idx);
  while (tmp != list_start)
    {
      _set_attributes(win, tmp, idx, current);
      _handle_columns(idx, &column, longest_arg);
      if (mvwprintw(win, (idx - 1) % LINES,
		    ((longest_arg + COL_PADDING) * (column - 1)),
		    "%s", tmp->str) == ERR)
	_exit_too_long();
      tmp = _reset_attr(win, tmp, &idx);
    }
  if (wrefresh(win) == ERR)
    my_exit(EXIT_FAILURE, "wrefresh() failed!\n");
}

static WINDOW	*_init_win(void)
{
  WINDOW	*win;

  if (newterm(NULL, stderr, stdin) == NULL)
    my_exit(EXIT_FAILURE, "Failed to create ncruses window!\n");
  if ((win = newwin(LINES, COLS, 0, 0)) == NULL)
    my_exit(EXIT_FAILURE, "Failed to create ncruses window!\n");
  if (keypad(win, true) == ERR)
    my_exit(EXIT_FAILURE, "keypad() failed!\n");
  if (noecho() == ERR)
    my_exit(EXIT_FAILURE, "noecho() failed!\n");
  if (raw() == ERR)
    my_exit(EXIT_FAILURE, "noecho() failed!\n");
  curs_set(0);
  return (win);
}

t_node		*_selection_window(t_node *list_start)
{
  WINDOW	*win;
  int		input;
  int		current;
  int		longest_arg;

  win = _init_win();
  longest_arg = _find_longest_arg(list_start);
  current = 1;
  _print_args(win, current, list_start, longest_arg);
  while (TRUE)
    {
      if ((input = wgetch(win)) == ERR)
	my_exit(EXIT_FAILURE, "Timeout!\n");
      _input_iskey(list_start, input, &current);
      if ((list_start = _input_isbackspace(list_start, input, &current,
					   &longest_arg)) == NULL)
	return (NULL);
      _input_isspace(list_start, input, &current);
      if (_input_isexit(list_start, input) != NULL)
	return (list_start);
      _print_args(win, current, list_start, longest_arg);
    }
  return (NULL);
}
