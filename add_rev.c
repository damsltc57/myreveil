/*
** add_rev.c for add_rev.c in /home/dams/delivery/perso/reveil/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 10 14:04:14 2017 Damien Laurent
** Last update Sat Mar 11 01:39:00 2017 Damien Laurent
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char		*get_next_line(int fd);

int		check_valid_time(char *hour)
{
  char		*tmp;
  char		*tmp1;
  int		i;
  int		j;

  j = 0;
  i = 0;
  tmp = malloc(sizeof(char) * 10);
  tmp1 = malloc(sizeof(char) * 10);

  while (hour[i] != ':')
    {
      tmp[i] = hour[i];
      i++;
    }
  tmp[i] = '\0';
  while (hour[i] != '\0')
    {
      tmp1[j] = hour[i];
      j++;
      i++;
    }
  tmp1[j] = '\0';
  if (strlen(tmp) != 2)
    exit(0);
  return (0);
}

int		main(int ac, char **av)
{
  int		fd;
  char		*s;

  if (ac != 2)
    {
      printf("Usage: ./add [heure:min]\n");
      return (0);
    }
  fd = open("input", O_RDWR);
  check_valid_time(av[1]);
  while ((s = get_next_line(fd)) != NULL);
  write(fd, av[1], strlen(av[1]));
  write(fd, "\n", 1);
  close(fd);
  return (0);
}
