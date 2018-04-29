//
// Vector2.cpp for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Tue May  7 19:48:53 2013 christopher steel
// Last update Fri May 31 15:24:02 2013 christopher steel
//

#include	<Vector2.hh>

Vector2f::Vector2f(void) :
  x(0.0f), y(0.0f)
{

}

Vector2f::Vector2f(float x, float y) :
  x(x), y(y)
{

}

Vector2f&	Vector2f::operator+(const Vector2f& other) const
{
  Vector2f	*noob = new Vector2f;

  noob->x = x + other.x;
  noob->y = y + other.y;
  return (*noob);
}

Vector2f&	Vector2f::operator-(const Vector2f& other) const
{
  Vector2f	*noob = new Vector2f;

  noob->x = x - other.x;
  noob->y = y - other.y;
  return (*noob);
}

Vector2f&	Vector2f::operator*(const Vector2f& other) const
{
  Vector2f	*noob = new Vector2f;

  noob->x = x * other.x;
  noob->y = y * other.y;
  return (*noob);
}

Vector2f&	Vector2f::operator*(const float factor) const
{
  Vector2f	*noob = new Vector2f;

  noob->x = x * factor;
  noob->y = y * factor;
  return (*noob);
}

bool		Vector2f::operator!=(const Vector2f& other) const
{
  return (!(*this == other));
}

bool		Vector2f::operator==(const Vector2f& other) const
{
  if (this->x == other.x && this->y == other.y)
    return (true);
  return (false);
}

Vector2f&	Vector2f::operator=(const Vector2f& other)
{
  this->x = other.x;
  this->y = other.y;
  return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Vector2f& vec)
{
  out << "Vector2f("
      << vec.x << ", "
      << vec.y << ")";
  return (out);
}
