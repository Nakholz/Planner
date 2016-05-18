/*
** print_opt.c for  in /home/arnhol_m/rendu/synth/agenda/srcs
**
** Made by martin Arnholz
**
** Started on  Mon Jun 29 13:50:15 2015 martin Arnholz
** Last update Mon Apr 25 14:17:04 2016 
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void    print_employee(t_employee *employee)
{
  employee = employee->first;
  while (employee != NULL)
    {
      printf("*************************************\n");
      printf("%s ", employee->name);
      printf("%s\n", employee->forename);
      printf("poste: %s\n", employee->poste);
      printf("ville: %s\n", employee->code_post);
      printf("id: %s\n", employee->id_name);
      employee = employee->next;
    }
}

void    print_meeting(t_meeting *meeting)
{
  int	i;
  
  meeting = meeting->first;
  while (meeting != NULL)
    {
      i = 0;
      printf("*************************************\n");
      printf("REUNION\n");
      printf("ville: %s\n", meeting->place);
      printf("date: %s\n", meeting->date);
      printf("id: %s\n", meeting->id);
      while (meeting->id_employee[i] != NULL)
	{
	  printf("avec: %s\n", meeting->id_employee[i]);
	  i++;
	}
      meeting = meeting->next;
    }
}

char    **fill_tab(char *str, int k)
{
  int   i;
  int   x;

  i = 0;
  x = 0;
  while (str[i])
    {
      while (x < k)
        {
          printf("%c", str[x]);
          x++;
        }
      x = 0;
      i++;
    }
  return (0);
}

char	**sort_tab(char *str, int k)
{
  char	**new;
  int	a;

  a = 0;
  if ((new = malloc(sizeof(char *) * strlen(str) - k - 1)) == 0)
    return (0);
  while (a < k)
    {
      if ((new[a] = malloc(sizeof(char) * k)) == 0)
	return (0);
      a++;
    }
  return (new);
}

char	**alpha(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      printf("%s\n", tab[i]);
      i++;
    }
  return (tab);
}
