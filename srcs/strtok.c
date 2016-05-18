/*
** strtok.c for  in /home/arnhol_m/rendu/synth/agenda/srcs
** 
** Made by martin Arnholz
** 
** Started on  Tue Jun 30 09:38:28 2015 martin Arnholz
** Last update Mon Apr 25 14:17:56 2016 
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int     count_word(char *str ,char sep)
{
  int   i;
  int   o;

  i = 0;
  o = 0;
  while (str[i] != '\0')
    {
      if (str[i] == sep)
        o++;
      i++;
    }
  o++;
  return (o);
}

int     size_tab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

int    count_char(char *str, int i, char sep)
{
  while (str[i] != sep && str[i] != '\0')
    i++;
  return (i);
}

char    **my_str_to_wordtab(char *str ,char sep)
{
  char   **tab;
  int   i;
  int   y;
  int   x;

  y = 0;
  i = 0;
  if ((tab = malloc(sizeof(char*) * (count_word(str ,sep) + 1))) == 0)
    return (NULL);
  while (str[i] != '\0')
    {
      if ((tab[y] = malloc(sizeof(char) * (count_char(str, i, sep) + 1))) == 0)
	return(NULL);
      x = 0;
      while (str[i] != sep && str[i] != '\0')
        {
          tab[y][x] = str[i];
          x++;
          i++;
        }
      if (str[i] == '\0')
        i--;
      i++;
      y++;
    }
  tab[y] = NULL;
  return (tab);
}
