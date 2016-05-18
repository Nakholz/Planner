/*
** prerequis.c for  in /home/arnhol_m/rendu/synth/agenda
**
** Made by martin Arnholz
**
** Started on  Mon Jun 29 14:00:21 2015 martin Arnholz
** Last update Mon Apr 25 14:23:36 2016 
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_list
{
  void *data;
  struct s_list *next;
} t_list;

int	rev_list(t_list **begin)
{
  t_list *tmpnext;
  t_list *tmplist;

  if ((*begin) != NULL)
    {
      tmpnext = (*begin)->next;
      (*begin)->next = NULL;
      while (tmpnext != NULL)
	{
	  tmplist = tmpnext->next;
	  tmpnext->next = (*begin);
	  (*begin) = tmpnext;
	  tmpnext = tmplist;
	}
    }
  return (0);
}

t_list	*find_node(t_list *begin, void *data_ref, int (*cmp)(void *, void *))
{
  while (begin != NULL)
    {
      if (begin->data == NULL)
        return (0);
      if ((cmp(begin->data, data_ref)) == 0)
	return (begin);
       begin = begin->next;
    }
  return (0);
}
