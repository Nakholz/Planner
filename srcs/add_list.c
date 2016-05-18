/*
** add_list.c for  in /home/arnhol_m/rendu/synth/agenda/srcs
**
** Made by martin Arnholz
**
** Started on  Tue Jun 30 14:01:48 2015 martin Arnholz
** Last update Mon Apr 25 14:12:58 2016 
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int     add_name(t_employee **employee, char **toc)
{
  t_employee *emp;

  if ((emp = malloc(sizeof(t_employee))) == NULL)
    return (0);
  emp->name = toc[1];
  emp->forename = toc[2];
  emp->poste = toc[3];
  emp->code_post = toc[4];
  emp->id_name = toc[5];
  if ((*employee)->first == NULL && (*employee)->last == NULL)
    {
      emp->next = NULL;
      emp->previous = NULL;
      (*employee)->first = emp;
      (*employee)->last = emp;
    }
  else
    {
      emp->previous = (*employee)->last;
      emp->next = NULL;
      (*employee)->last->next = emp;
      (*employee)->last = emp;
    }
  return (0);
}

int     add_meet(t_meeting **meeting, char **toc)
{
  t_meeting *mee;
  int	i;

  i = 0;
  if ((mee = malloc(sizeof(t_meeting))) == NULL)
    return (0);
  mee->place = toc[1];
  mee->date = toc[2];
  mee->id = toc[3];
  while (toc[i] != NULL)
    i++;
  if ((mee->id_employee = malloc(sizeof(char *) * i)) == 0)
    return (0);
  i = 0;
  while (toc[i] != NULL)
    {
      if ((mee->id_employee[i] = malloc(sizeof(char) * strlen(toc[i]))) == 0)
	return (0);
      mee->id_employee[i] = toc[i+4];
      i++;
    }
  if ((*meeting)->first == NULL && (*meeting)->last == NULL)
    {
      mee->next = NULL;
      mee->previous = NULL;
      (*meeting)->first = mee;
      (*meeting)->last = mee;
    }
  else
    {
      mee->previous = (*meeting)->last;
      mee->next = NULL;
      (*meeting)->last->next = mee;
      (*meeting)->last = mee;
    }
  return (0);
}
