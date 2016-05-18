/*
** pars.c in /home/nakholz/rendu/Github/Planner
** 
** Made by Arnholz Martin
** Login : arnhol_m
**
** Started on  Tue Jun 30 10:04:25 2015 martin Arnholz
** Last update Thu May 19 01:03:08 2016 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

int	pars_it(char *str ,t_employee *employee ,t_meeting *meeting)
{
  char **toc;
  int	i;

  i = 0;
  toc = my_str_to_wordtab(str ,' ');
  while (toc[i] != NULL)
    {
      if ((strcmp("new_employee", toc[i])) == 0)
	add_name(&employee ,toc);
      else if ((strcmp("new_meeting", toc[i])) == 0)
	add_meet(&meeting, toc);
      else if ((strcmp("fire", toc[i])) == 0)
	del_node(employee ,toc);
      else if ((strcmp("invite", toc[i])) == 0)
	inv_meet(meeting ,toc);
      else if ((strcmp("info_meetings", toc[i])) == 0)
	print_meeting(meeting);
      else if ((strcmp("info_employees", toc[i])) == 0)
	print_employee(employee);
      i++;
    }
  return (0);
}
