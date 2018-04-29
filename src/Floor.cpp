//
// Floor.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Wed May 29 15:52:43 2013 christopher steel
// Last update Wed May 29 16:36:58 2013 christopher steel
//

#include	<Objects.hh>

namespace	Object
{
  Floor::Floor(const Vector2f& pos, const Vector2f& size) :
    TexturedCuboid(Vector3f(pos.x, pos.y, -1), Vector3f(0, 0, 0),
		   Vector3f(size.x, size.y, 1), FLOOR_TEXTURE)
  {
    collision = false;
    immortal = true;
  }

  Floor::~Floor(void)
  {

  }
}
