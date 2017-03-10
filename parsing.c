/*
** parsing.c for parsing.c in /home/dams/delivery/perso/reveil/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Thu Mar  9 23:00:09 2017 Damien Laurent
** Last update Fri Mar 10 16:08:12 2017 Damien Laurent
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "reveil.h"
#include <stdlib.h>
#include <unistd.h>

void		read_input(t_rev *rev, t_allr **allr)
{
  int		fd;
  char		*s;
  char		*tmp;
  int		i;
  char		**tab;
  int		j;
  int		k;

  tab = malloc(sizeof(char*) * 10);
  i = 0;
  tmp = malloc(sizeof(char) * 10);
  if ((fd = open("input", O_RDONLY)) == -1)
    {
      printf("cant open input\n");
      exit(0);
    }
  while ((s = get_next_line(fd)) != NULL)
    {
      tab[i] = s;
      i++;
    }
  tab[i] = NULL;
  i = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      k = 0;
      while (tab[i][j] != '\0')
	{
	  tmp[k] = tab[i][j];
	  if (tab[i][j + 1] == ':')
	    {
	      tmp[k + 1] = '\0';
	      rev->heures = atoi(tmp);
	      j++;
	      k = -1;
              tmp[0] = '\0';
	    }
          k++;
	  j++;
	}
      tmp[k] = '\0';
      rev->min = atoi(tmp);
      my_put_in_list(allr, *rev);
      i++;
    }

  close(fd);
}
