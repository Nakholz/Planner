/*
** get_next_line.c for  in /home/arnhol_m/rendu/synth/agenda/srcs
** 
** Made by martin Arnholz
** 
** Started on  Mon Jun 29 13:44:52 2015 martin Arnholz
** Last update Mon Apr 25 14:17:17 2016 
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#define BUFFER_SIZE 4096

int     size(char *str)
{
  int   i;

  i = 0;
  if (str == NULL)
    return (i);
  while (str[i] != '\0')
    i++;
  return (i);
}

char     *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  if (src == NULL)
    return (dest);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}

char    *strct(char *dest, char *src, int *tmp)
{
  int   a;
  char  *str2;

  str2 = malloc((size(dest) + size(src)) * sizeof(char) + 1);
  str2 = my_strcpy(str2, dest);
  a = size(dest);
  while (src[*tmp] != '\0' && src[*tmp] != '\n')
    {
      str2[a] = src[*tmp];
      (*tmp)++;
      a++;
    }
  str2[a] = '\0';
  return (str2);
}

char    *get_next_line(const int fd)
{
  static char   buffer[BUFFER_SIZE + 1];
  static int    tmp = 0;
  char          *str;
  int           n;

  str = NULL;
  if (fd < 0)
    return (NULL);
  if (buffer[tmp++] == '\n')
    {
      str = strct(str, buffer, &tmp);
      if (buffer[tmp] == '\n')
        return (str);
    }
  while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
      buffer[n] = '\0';
      tmp = 0;
      str = strct(str, buffer, &tmp);
      if (buffer[tmp] == '\n')
        return (str);
    }
  if (str != NULL && str[0] == 0)
    return (NULL);
  return (str);
}
