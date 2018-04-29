//
// TexturedCuboid.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Fri May 24 11:15:34 2013 christopher steel
// Last update Fri Jun  7 17:30:18 2013 christopher steel
//

#include	<Objects.hh>

namespace	Object
{
  TexturedCuboid::TexturedCuboid(const Vector3f& pos, const Vector3f& rot,
				 const Vector3f& size, const std::string& tex) :
    ACuboid(pos, rot, size)
  {
    texture_ = gdl::Image::load(tex);
  }

  TexturedCuboid::~TexturedCuboid()
  {

  }

  void		TexturedCuboid::initialize(void)
  {
    this->model_ = glGenLists(1);
    glNewList(model_, GL_COMPILE);
    this->texture_.bind();
    glBegin(GL_QUADS);

    //front
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);

    //top
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,	1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f,  1.0f);

    //right
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);

    //left
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f); //br
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f); //bl
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f); //tl
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f); //tr

    glEnd();
    glEndList();
  }

  void		TexturedCuboid::update(gdl::GameClock const &gameClock, gdl::Input & input)
  {
    (void) gameClock;
    (void) input;
  }
}
