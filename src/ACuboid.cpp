//
// ACuboid.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Fri May 24 10:54:09 2013 christopher steel
// Last update Fri May 24 11:02:06 2013 christopher steel
//

#include	<Objects.hh>

namespace	Object
{
  ACuboid::ACuboid(const Vector3f& position, const Vector3f& rotation, const Vector3f& size)
  {
    this->type = "cuboid";
    this->position_ = position;
    this->rotation_ = rotation;
    this->size_ = size;
  }

  ACuboid::~ACuboid()
  {
  }

  void		ACuboid::draw(void)
  {
    glPushMatrix();
    glLoadIdentity();

    glTranslatef(this->position_.x, this->position_.y, this->position_.z);
    glRotatef(this->rotation_.x, 1.0f, 0.0f, 0.0f);
    glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);
    glRotatef(this->rotation_.z, 0.0f, 0.0f, 1.0f);
    glScalef(this->size_.x/2, this->size_.y/2, this->size_.z/2);

    glCallList(this->model_);

    glPopMatrix();
  }
}
