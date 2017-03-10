/*
** set.c for set.c in /home/dams/delivery/perso/reveil/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 10 01:00:13 2017 Damien Laurent
** Last update Fri Mar 10 01:04:49 2017 Damien Laurent
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int		main(int ac, char **av)
{
  int		fd;

  if (ac != 2)
    {
      printf("Usage: ./set 'result'\n");
      return (0);
    }
  remove("resultat");
  fd = open("resultat", O_WRONLY | O_CREAT, 0644);
  write(fd, av[1], strlen(av[1]));
  write(fd, "\n", 1);
  close(fd);
}
