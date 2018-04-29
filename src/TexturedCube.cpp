//
// TexturedCube.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sat May 18 16:35:27 2013 christopher steel
// Last update Fri May 24 11:20:12 2013 christopher steel
//

#include	<Objects.hh>

namespace	Object
{
  TexturedCube::TexturedCube(const Vector3f& pos, const Vector3f& rot,
			     float size, const std::string& tex) :
    TexturedCuboid(pos, rot, Vector3f(size, size, size), tex)
  {
  }

  TexturedCube::~TexturedCube()
  {

  }
}
