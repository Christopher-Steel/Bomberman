//
// ColoredCuboid.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Fri May 24 11:08:52 2013 christopher steel
// Last update Fri May 24 11:10:32 2013 christopher steel
//

#include	<Objects.hh>

namespace	Object
{
  ColoredCuboid::ColoredCuboid(const Vector3f& pos, const Vector3f& rot,
			       const Vector3f& size, const gdl::Color& color) :
    ACuboid(pos, rot, size)
  {
    this->color_ = color;
  }

  ColoredCuboid::~ColoredCuboid()
  {

  }

  void		ColoredCuboid::initialize(void)
  {
    this->model_ = glGenLists(1);
    glNewList(model_, GL_COMPILE);
    glColor3f(this->color_.r / 255, this->color_.g / 255, this->color_.b / 255);
    glBegin(GL_QUADS);

    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);

    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);

    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);

    glEnd();
    glEndList();
  }

  void		ColoredCuboid::update(gdl::GameClock const &gameClock, gdl::Input & input)
  {
    (void) gameClock;
    (void) input;
  }
}
