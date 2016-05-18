/*
** list.c for  in /home/arnhol_m/rendu/synth/agenda/srcs
**
** Made by martin Arnholz
**
** Started on  Mon Jun 29 13:49:57 2015 martin Arnholz
** Last update Mon Apr 25 14:17:28 2016 
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

t_employee	*init_employee()
{
  t_employee *employee;

  employee = malloc(sizeof(t_employee));
  employee->first = NULL;
  employee->last = NULL;
  return (employee);
}

t_meeting	*init_meeting()
{
  t_meeting	*meeting;

  meeting = malloc(sizeof(t_meeting));
  meeting->first = NULL;
  meeting->last = NULL;
  return (meeting);
}

void	del_node(t_employee *employee, char **toc)
{
  int	ref;
  int	temp;

  employee = employee->first;
  ref = atoi(toc[1]);
  while (employee != NULL)
    {
      temp = atoi(employee->id_name);
      if (ref == temp)
	{
	  if (employee->next != NULL)
	    employee->next->previous = employee->previous;
	  if (employee->previous != NULL)
	    employee->previous->next = employee->next;
	  if (employee->last == employee)
	    employee->last = employee->previous;
	  if (employee->first == employee)
	    employee->first = employee->next;
	}
      employee = employee->next;
     }
}

void	inv_meet(t_meeting *meeting, char **toc)
{
  int	i;

  meeting = meeting->first;
  while (meeting != NULL)
    {
      i = 0;
      while (toc[i] != NULL)
	i++;
      meeting->id_employee = realloc(meeting->id_employee, sizeof(char *) * i);
      i = 0;
      while (toc[i] != NULL)
	{
	  if (strcmp(meeting->id ,toc[1]) == 0)
	    {
	      meeting->id_employee[i] = realloc(meeting->id_employee[i], sizeof(char) * strlen(toc[i]));
	      meeting->id_employee[i] = toc[i+2];
	    }
	  i++;
	}
      meeting = meeting->next;
    }
}

void	ex_mee(t_meeting *meeting, char **toc)
{
  int   i;
  int	tc;

  i = 0;
  tc = atoi(toc[1]);
  meeting = meeting->first;
  while (meeting != NULL)
    {
      while (meeting->id_employee[i] != NULL)
	{
	  if (atoi(meeting->id_employee[i]) == tc)
	    return;
	  i++;
	}
      meeting = meeting->next;
    }
}
