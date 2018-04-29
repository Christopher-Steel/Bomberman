//
// main.cpp for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sun May  5 17:42:57 2013 christopher steel
// Last update Mon Jun  3 18:09:54 2013 christopher steel
//

#include	<cstdlib>
#include	<ctime>
#include	<MyGame.hh>

int		main(void)
{
  MyGame	game;

  srand(time(NULL));
  game.run();
  return (1);
}
