//
// ReadMap.cpp for bomberman in /home/lethui_a//projet/bomberman/bomberman-2016-dubdub/src
//
// Made by anthony lethuillier
// Login   <lethui_a@epitech.net>
//
// Started on  Thu May 23 21:41:38 2013 anthony lethuillier
// Last update Mon May 27 18:54:19 2013 christopher steel
//

#include        <MyGame.hh>
#include        <Bomber.hh>
#include        <Objects.hh>
#include        <Primitives.hh>
#include        <Vector3.hh>
#include	<fstream>
#include	<string>
#include	<iostream>
#include	<cstdio>
#include	<sstream>

int		MyGame::ReadCreate(std::string path)
{
  std::ifstream		fichier;
  std::stringstream	map;
  int			i = 0;
  int			tmp = 0;
  int			max_char = 0;
  int			max_line = 0;

  fichier.open(path.c_str());
   if (fichier)
     {
      std::string line;
      map << fichier.rdbuf();
      fichier.close();
    }
   else
     return(-1);
   std::cout<<"MAP CHARGER !"<<std::endl;
   while(map.str()[i])
     {
       if (map.str()[i] == '\n')
	 {
	   if (tmp > max_char)
	     max_char = tmp;
	   tmp = 0;
	   max_line++;
	 }
       std::cout<<map.str()[i];
       i++;
       tmp++;
     }
   this->CreateBorder(max_char - 1, max_line + 1);
   this->FillOut(max_line, max_char, map.str());
   return(0);
}

void		MyGame::FillOut(int x, int y, std::string map)
{
  int		x2 = 0;
  int		x3 = 0;
  int		lastline = 0;

  while (x2 < y && map[lastline])
    {
      x3 = 0;
      while (x3 < x || map[lastline] != '\n')
	{
	  if (map[lastline] == '0')
	    {
	      this->objects_.push_front(new Object::Crate(Vector3f(x2 * 200 + 100, x3 * 200 + 100, 0), Vector3f(0, 0, 0), 200));
	      x3 = x3 + 1;
	    }
	  else if (map[lastline] == '1')
	    {
	      this->objects_.push_front(new Object::Wall(Vector3f(x2 * 200 + 100, x3 * 200 + 100, 0), Vector3f(0, 0, 0), 200));
	      x3 = x3 + 1;
	    }
	  else
	    x3 = x3 + 1;
	  lastline++;
	}
      lastline++;
      x2 = x2 + 1;
    }
}
