//
// Rectangle.cpp for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sat May  4 20:13:45 2013 christopher steel
// Last update Tue May  7 20:14:32 2013 christopher steel
//

#include	<Primitives.hh>

namespace	Primitive
{
  Rectangle::Rectangle(const Vector3f& position,
		       const Vector3f& rotation,
		       const Vector2f& size,
		       const Vector3f& color) :
    tex_(false)
  {
    this->position_ = position;
    this->rotation_ = rotation;
    this->size_ = size;
    this->color_ = color;
  }

  Rectangle::Rectangle(const Vector3f& position,
		       const Vector3f& rotation,
		       const Vector2f& size,
		       const std::string& texture) :
    tex_(true)
  {
    this->position_ = position;
    this->rotation_ = rotation;
    this->size_ = size;
    this->texture_ = gdl::Image::load(texture);
  }

  Rectangle::~Rectangle()
  {

  }

  void		Rectangle::initialize(void)
  {

  }

  void		Rectangle::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    (void) gameClock;
    (void) input;
  }

  void		Rectangle::draw(void)
  {
    if (this->tex_)
      this->texture_.bind();

    glPushMatrix();
    glLoadIdentity();

    glTranslatef(this->position_.x, this->position_.y, this->position_.z);
    glRotatef(this->rotation_.x, 1.0f, 0.0f, 0.0f);
    glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);
    glRotatef(this->rotation_.z, 0.0f, 0.0f, 1.0f);

    glBegin(GL_QUADS);

    if (!this->tex_)
      glColor3f(this->color_.x, this->color_.y, this->color_.z);
    else
      glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1 * size_.x / 2, size_.y / 2, 0.0f);

    if (this->tex_)
      glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-1 * size_.x / 2, -1 * size_.y / 2, 0.0f);

    if (this->tex_)
      glTexCoord2f(1.0f, 1.0f);
    glVertex3f(size_.x / 2, -1 * size_.y / 2, 0.0f);

    if (this->tex_)
      glTexCoord2f(1.0f, .0f);
    glVertex3f(size_.x / 2, size_.y / 2, 0.0f);

    glEnd();

    glPopMatrix();
  }
}
