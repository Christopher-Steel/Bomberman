//
// ColoredCube.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sat May 18 17:12:03 2013 christopher steel
// Last update Fri May 24 11:17:41 2013 christopher steel
//

#include	<Objects.hh>

namespace	Object
{
  ColoredCube::ColoredCube(const Vector3f& pos, const Vector3f& rot,
			   float size, const gdl::Color& color) :
    ColoredCuboid(pos, rot, Vector3f(size, size, size), color)
  {
  }

  ColoredCube::~ColoredCube()
  {
  }
}
