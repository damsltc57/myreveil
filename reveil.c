/*
** reveil.c for reveil.c in /home/dams/delivery/perso/reveil/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Thu Mar  9 22:42:32 2017 Damien Laurent
** Last update Fri Mar 10 14:01:24 2017 Damien Laurent
*/
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "reveil.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Audio.h>

char		*init_calcul(t_calcul *calcul)
{
  int		a;
  int		b;
  int		fd;
  char		*stra;
  char		*strb;

  stra = malloc(sizeof(char) * 40);
  strb = malloc(sizeof(char) * 40);

  a = (rand() % 100);
  b = (rand() % 100);
  calcul->a = a;
  calcul->b = b;
  sprintf(stra, "%d", a);
  sprintf(strb, "%d", b);
  fd = open(strcat(strcat(stra, "+"), strb), O_WRONLY | O_CREAT, 0644);
  write(fd, stra, strlen(stra));
  close(fd);
  open("resultat", O_CREAT, 0644);
  return (stra);
}

int		get_calcul(t_calcul *calcul)
{
  char		*s;
  int		nb;
  int		nb1;
  int		fd;

  fd = open("resultat", O_RDONLY);
  nb1 = calcul->a + calcul->b;
  if ((s = get_next_line(fd)) == NULL)
    {
      close(fd);
      return (1);
    }
  nb = atoi(s);
  if (nb1 == nb)
    {
      close(fd);
      return (0);
    }
  close(fd);
  return (1);
}

void		dringgg(t_rev *rev, t_calcul *calcul, t_allr **allr)
{
  time_t	current;
  struct tm	instant;
  sfMusic	*music;
  int 		revok;
  char		*name;
  float		vol;

  vol = 0;
  revok = 0;
  music = NULL;
  while (42)
    {
      if (revok == 0)
	usleep(1000000);
      else
      usleep(4000000);
      time(&current);
      instant = *localtime(&current);
      // printf("%d/%d ; %d:%d:%d\n", instant.tm_mday+1, instant.tm_mon+1, instant.tm_hour, instant.tm_min, instant.tm_sec);
      if (check_in_link(allr, instant) == 0)
	{
	  name = init_calcul(calcul);
	  music = sfMusic_createFromFile("res/daft_punk.ogg");
	  sfMusic_play(music);
	  sfMusic_setVolume(music, vol);
	  revok = 1;
	}
      if (revok == 1)
	{
	  if (vol < 100)
	    vol += 4;
	  sfMusic_setVolume(music, vol);
	  if (get_calcul(calcul) == 0)
	    {
	      sfMusic_pause(music);
	      remove(name);
	      revok = 0;
	    }
	}
    }
}

int		main(void)
{
  t_rev		rev;
  t_calcul	calcul;
  t_allr	*allr;

  allr = NULL;
  srand(time(NULL));
  read_input(&rev, &allr);
  my_show_list(&allr);
  dringgg(&rev, &calcul, &allr);
  return (0);
}
