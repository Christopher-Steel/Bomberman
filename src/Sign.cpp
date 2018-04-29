//
// Sign.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Wed May 29 16:25:06 2013 christopher steel
// Last update Wed May 29 16:29:51 2013 christopher steel
//

#include	<Objects.hh>

namespace	Object
{
  Sign::Sign(const Vector3f& position, const Vector3f& rotation,
	     const Vector2f& size, const std::string& texture) :
    TexturedCuboid(position, rotation,
		   Vector3f(size.x, size.y, 1), texture)
  {

  }

  Sign::~Sign()
  {

  }
}
