//
// Pyramide.cpp for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sun May  5 16:25:13 2013 christopher steel
// Last update Tue May  7 11:54:03 2013 christopher steel
//

#include	<GL/gl.h>
#include	<GL/glu.h>

#include	<Objects.hh>

namespace	Object
{
  void		Pyramide::initialize(void)
  {

  }

  void		Pyramide::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    (void) gameClock;

    if (input.isKeyDown(gdl::Keys::Right) == true)
      this->rotation_.y = ((int)rotation_.y + 1) % 360;
    if (input.isKeyDown(gdl::Keys::Left) == true)
      this->rotation_.y = ((int)rotation_.y - 1) % 360;
  }

  void		Pyramide::draw(void)
  {
    glPushMatrix();
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -900.0f);
    glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, -150.0f, -150.0f);
    glVertex3f(-150.0f, -150.0f, 150.0f);
    glVertex3f(150.0f, -150.0f, 150.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 150.0f, 0.0f);
    glVertex3f(-150.0f, -150.0f, 150.0f);
    glVertex3f(150.0f, -150.0f, 150.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 150.0f, 0.0f);
    glVertex3f(0.0f, -150.0f, -150.0f);
    glVertex3f(-150.0f, -150.0f, 150.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 150.0f, 0.0f);
    glVertex3f(150.0f, -150.0f, 150.0f);
    glVertex3f(0.0f, -150.0f, -150.0f);

    glEnd();

    glPopMatrix();
  }
}
