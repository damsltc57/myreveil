/*
** add_rev.c for add_rev.c in /home/dams/delivery/perso/reveil/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 10 14:04:14 2017 Damien Laurent
** Last update Fri Mar 10 14:19:07 2017 Damien Laurent
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

char		*get_next_line(int fd);

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
  while ((s = get_next_line(fd)) != NULL)
    printf("s: %s\n", s);
  write(fd, av[1], strlen(av[1]));
  write(fd, "\n", 1);
  close(fd);
  return (0);
}
