/*
** song.c for song.c in /home/dams/delivery/perso/reveil/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Thu Mar  9 23:19:11 2017 Damien Laurent
** Last update Fri Mar 10 00:30:09 2017 Damien Laurent
*/
#include <SFML/Audio.h>

void		music_menu(int track, sfMusic *music)
{
  if (track == 0)
    {
      sfMusic_pause(music);
      return ;
    }

  if (track == 1)
    music = sfMusic_createFromFile("res/daft_punk.ogg");
  else if (track == 2)
    music = sfMusic_createFromFile("res/overdoz.ogg");
  else if (track == 3)
    music = sfMusic_createFromFile("res/nina.ogg");
  sfMusic_play(music);
}
