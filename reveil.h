/*
** reveil.h for reveil.h in /home/dams/delivery/perso/reveil/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Thu Mar  9 22:58:33 2017 Damien Laurent
** Last update Fri Mar 10 13:57:21 2017 Damien Laurent
*/

#ifndef REVEIL_H_
#define REVEIL_H_
#include <SFML/Audio.h>
#include "time.h"
typedef struct s_rev
{
  time_t	min;
  time_t	heures;
}		t_rev;

typedef struct s_allr
{
  t_rev		rev;
  struct s_allr	*next;
}		t_allr;

typedef struct	s_calcul
{
  int		a;
  int		b;
}		t_calcul;

char		*get_next_line(int fd);
void		read_input(t_rev *rev, t_allr **allr);
void		music_menu(int track, sfMusic *music);
void		my_put_in_list(t_allr **allr, t_rev rev);
void		my_show_list(t_allr **allr);
int		check_in_link(t_allr **allr, struct tm instant);

#endif /*REVEIL_H_*/
