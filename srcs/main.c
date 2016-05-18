/*
** main.c for  in /home/arnhol_m/rendu/synth/agenda/srcs
** 
** Made by martin Arnholz
** 
** Started on  Mon Jun 29 14:28:25 2015 martin Arnholz
** Last update Mon Apr 25 14:16:57 2016 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my.h"

int	main(int ac, char **av)
{
  char	*str;
  t_employee *employee;
  t_meeting  *meeting;
  
  if (ac != 1 || av[1] != NULL)
    return (0);
  employee = init_employee();
  meeting = init_meeting();
  while ((str = get_next_line(0)) != NULL)
    pars_it(str ,employee ,meeting);
  return (0);
}
