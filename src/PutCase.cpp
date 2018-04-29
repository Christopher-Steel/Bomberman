//
// PutCase.cpp for BOMberman in /home/lethui_a//projet/bomberman/opengl_test/bomberman-2016-dubdub/src
// 
// Made by anthony lethuillier
// Login   <lethui_a@epitech.net>
// 
// Started on  Fri May 17 17:34:09 2013 anthony lethuillier
// Last update Mon May 27 11:50:52 2013 anthony lethuillier
//

#include        <MyGame.hh>
#include        <Bomber.hh>
#include        <Objects.hh>
#include        <Primitives.hh>
#include        <Vector3.hh>
#include	<iostream>
#include	<fstream>

void		MyGame::CreateBlock(int x, int y)
{
  int	x2 = 1;
  int	x3 = 1;

  while(x2 < x)
    {
      x3 = 1;
	while(x3 < y)
	  {
	    this->objects_.push_front(new Object::Wall(Vector3f(x3 * 200 + 100, x2 * 200 + 100, 0), Vector3f(0, 0, 0), 200));
	    x3 = x3 + 2;
	  }
	x2 = x2 + 2;
    }
}

void		MyGame::PutCase(int x, int y)
{
  int	x2 = 0;
  int	x3 = 0;

  while( x2 < y)
    {
      x3 = 0 ;
      while(x3 < x)
	{
	  this->objects_.push_front(new Object::Crate(Vector3f(x2 * 200 + 100, x3 * 200 + 100, 0), Vector3f(0, 0, 0), 200));
	  x3 = x3 + 1;
	}
      x2 = x2 + 1;
    }
}

void		MyGame::CreateCase(int x, int y)
{
  this->CreateBlock(x, y);
  this->PutCase(x, y);
}
