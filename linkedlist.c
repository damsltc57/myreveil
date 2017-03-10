/*
** linkedlist.c for linkedlist.c in /home/dams/delivery/perso/reveil/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 10 11:53:14 2017 Damien Laurent
** Last update Fri Mar 10 13:57:13 2017 Damien Laurent
*/
#include "reveil.h"
#include "unistd.h"
#include <stdlib.h>
#include <stdio.h>
void		my_put_in_list(t_allr **allr, t_rev rev)
{
 t_allr		*element;

 element = malloc(sizeof(*element));
 element->rev = rev;
 element->next = (*allr);
 (*allr) = element;
}

void		my_show_list(t_allr **allr)
{
  t_allr	*tmp;

  tmp = *allr;
  while (tmp != NULL)
    {
      // printf("boucle\n");
      // printf("min: %d\n", tmp->rev.min);
      // printf("heures: %d\n", tmp->rev.heures);
      tmp = tmp->next;
    }
}

int		check_in_link(t_allr **allr, struct tm instant)
{
  t_allr	*tmp;

  tmp = *allr;
  while (tmp != NULL)
    {
      if (instant.tm_hour == tmp->rev.heures && instant.tm_min == tmp->rev.min && instant.tm_sec == 1)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}
