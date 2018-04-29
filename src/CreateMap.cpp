//
// CreateMap.cpp for bomberman in /home/lethui_a//projet/bomberman/bomberman-2016-dubdub/src
//
// Made by anthony lethuillier
// Login   <lethui_a@epitech.net>
//
// Started on  Thu May 23 00:08:33 2013 anthony lethuillier
// Last update Tue May 28 18:08:04 2013 christopher steel
//

#include        <MyGame.hh>
#include        <Bomber.hh>
#include        <Objects.hh>
#include        <Primitives.hh>
#include        <Vector3.hh>


void		MyGame::CreateBorderTop(int x, int y)
{
  int	i = 0;

  while (i < y * 200)
    {
      this->objects_.push_front(new Object::Wall(Vector3f(i + 100, x * 200 + 100, 0), Vector3f(0, 0, 0), 200));
      i = i + 200;
    }
}

void		MyGame::CreateBorderRight(int x, int y)
{
  int	i = 0;

  while (i < x * 200)
    {
      this->objects_.push_front(new Object::Wall(Vector3f(y * 200 + 100, i + 100, 0), Vector3f(0, 0, 0), 200));
      i = i + 200;
    }
}

void		MyGame::CreateBorderBot(int x, int y)
{
  int	i = 0;
  x = x +200;
  while (i < y * 200)
    {
      this->objects_.push_front(new Object::Wall(Vector3f(i + 100, -200  + 100, 0), Vector3f(0, 0, 0), 200));
      i = i + 200;
    }
}

void		MyGame::CreateBorderLeft(int x, int y)
{
  int	i = 0;

  y = y + 200;
  while (i < x * 200)
    {
      this->objects_.push_front(new Object::Wall(Vector3f(-200  + 100, i + 100, 0), Vector3f(0, 0, 0), 200));
      i = i + 200;
    }
}

void		MyGame::CreateBorder(int x, int y)
{
  this->CreateBorderTop(x, y);
  this->CreateBorderRight(x, y);
  this->CreateBorderBot(x, y);
  this->CreateBorderLeft(x, y);
}
