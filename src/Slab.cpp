//
// Slab.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Wed May 15 14:20:17 2013 christopher steel
// Last update Wed May 15 15:30:47 2013 christopher steel
//

#include	<Objects.hh>

namespace	Object
{
  Slab::Slab(const Vector3f& pos, float size, const Vector3f& color) :
    Cube(pos + Vector3f(0, 0, size / 4), size, color)
  {

  }

  Slab::Slab(const Vector3f& pos, float size, const std::string& tex) :
    Cube(pos + Vector3f(0, 0, size / 4), size, tex)
  {

  }

  Slab::~Slab()
  {

  }

  void		Slab::initialize(void)
  {
    std::list<Primitive::Rectangle>::iterator it;

    this->addPolygon(position_ + Vector3f(0, 0, size_ / 4), Vector3f(0, 0, 0), Vector2f(size_, size_));		//haut
    this->addPolygon(position_ + Vector3f(0, size_ / 2, 0), Vector3f(-90, 0, 0), Vector2f(size_, size_ / 2));	//arriere
    this->addPolygon(position_ + Vector3f(size_ / 2, 0, 0), Vector3f(0, 90, 0), Vector2f(size_ / 2, size_));	//droite
    this->addPolygon(position_ - Vector3f(0, size_ / 2, 0), Vector3f(90, 0, 0), Vector2f(size_, size_ / 2));	//avant
    this->addPolygon(position_ - Vector3f(size_ / 2, 0, 0), Vector3f(0, -90, 0), Vector2f(size_ / 2, size_));	//gauche
    this->addPolygon(position_ - Vector3f(0, 0, size_ / 4), Vector3f(0, 180, 0), Vector2f(size_, size_));	//bas

    for (it = this->polygons_.begin(); it != this->polygons_.end(); it++)
      (*it).initialize();
  }
}
