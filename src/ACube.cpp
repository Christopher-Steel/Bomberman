//
// Cube.cpp for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sat May  4 20:28:04 2013 christopher steel
// Last update Fri May 24 11:03:10 2013 christopher steel
//

#include	<Objects.hh>

namespace	Object
{
  ACube::ACube(const Vector3f& position, const Vector3f& rotation, float size) :
    ACuboid(position, rotation, Vector3f(size, size, size))
  {
    this->type = "cube";
  }

  ACube::~ACube()
  {
  }
}
