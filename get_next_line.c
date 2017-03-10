/*
** get_next_line.c for get_next_line.c in /home/dams/delivery/CPE/CPE_2016_matchstick/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Fri Feb 24 09:31:34 2017 Damien Laurent
** Last update Thu Mar  9 23:30:49 2017 Damien Laurent
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char		*my_strcat(char* bufout, char *buffer)
{
  int		size;
  char		*tmp;

  size = strlen(bufout);
  tmp = malloc(sizeof(char) * size + 2);
  tmp = bufout;
  tmp[size] = buffer[0];
  tmp[size + 1] = '\0';
  return (tmp);
}

char		*get_next_line(int fd)
{
  char		*buffer;
  char		*bufout;
  int		i;
  int		out;

  out = 0;
  i = 0;
  if ((buffer = malloc(sizeof(char) *2)) == NULL)
    return (NULL);
  if ((bufout = malloc(sizeof(char*) * 4)) == NULL)
    return (NULL);
  bufout[0] = '\0';
  while (out == 0)
    {
      if ((read(fd, buffer, 1)) == 0)
	return (NULL);
      if (buffer[0] != '\n' && buffer[0] != '\0')
	bufout = my_strcat(bufout, buffer);
      else
	out = 2;
      i++;
    }
  return (bufout);
}
