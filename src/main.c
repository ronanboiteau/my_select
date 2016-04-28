/*
** main.c for my_select in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Wed Dec  2 17:59:31 2015 Ronan Boiteau
** Last update Fri Dec 11 04:10:30 2015 Ronan Boiteau
*/

#include "my.h"
#include "my_macro.h"
#include "my_select_ncurses.h"
#include "list.h"

static void		_print_selected(t_node *list_start, int first_pass)
{
  t_node		*tmp;

  tmp = list_start;
  if (tmp->selected == TRUE)
    {
      my_printf("%s", tmp->str);
      first_pass = FALSE;
    }
  tmp = tmp->next;
  while (tmp != list_start)
    {
      if (tmp->selected == TRUE)
	{
	  if (first_pass == TRUE)
	    {
	      my_printf("%s", tmp->str);
	      first_pass = FALSE;
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
  list_start->selected = FALSE;
  list_end = list_start;
  list_end->next = list_start;
  _init_list(list_start, argv);
  if ((list_start = _selection_window(list_start)) != NULL)
    _print_selected(list_start, TRUE);
  free(list_start);
  return (EXIT_SUCCESS);
}
