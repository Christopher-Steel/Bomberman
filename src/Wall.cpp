//
// Wall.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sat May 18 17:03:21 2013 christopher steel
// Last update Sat Jun  1 19:22:50 2013 christopher steel
//

#include	<Objects.hh>

namespace	Object
{
  Wall::Wall(const Vector3f& pos, const Vector3f& rot, float size) :
    TexturedCube(pos, rot, size, WALL_TEXTURE)
  {
    this->type = WALL_TYPE;
    this->immortal = true;
  }

  Wall::~Wall()
  {

  }
};
