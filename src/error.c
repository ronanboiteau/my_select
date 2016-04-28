#include <stdlib.h>
#include "my.h"
#include "my_select_ncurses.h"

void		_exit_too_long(void)
{
  if (clear() == ERR || endwin() == ERR)
    my_exit(EXIT_FAILURE, "Failed to exit ncurses window!\n");
  else
    my_exit(EXIT_FAILURE, "X Window too small for arguments\n");
  return ;
}
