//
// Vector3.cpp for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sun May  5 17:49:21 2013 christopher steel
// Last update Wed Jun  5 18:54:05 2013 frederic dubourg
//

#include	<Vector3.hh>

Vector3f::Vector3f(void) :
  x(0.0f), y(0.0f), z(0.0f)
{
}

Vector3f::Vector3f(float x, float y, float z) :
  x(x), y(y), z(z)
{
}

Vector3f::Vector3f(const Vector3f& other) :
  x(other.x), y(other.y), z(other.z)
{
}

Vector3f&	Vector3f::operator+(const Vector3f &other) const
{
  Vector3f	*noob = new Vector3f;

  noob->x = x + other.x;
  noob->y = y + other.y;
  noob->z = z + other.z;
  return (*noob);
}

Vector3f&	Vector3f::operator-(const Vector3f &other) const
{
  Vector3f	*noob = new Vector3f;

  noob->x = x - other.x;
  noob->y = y - other.y;
  noob->z = z - other.z;
  return (*noob);
}

Vector3f&	Vector3f::operator*(const float mult) const
{
  Vector3f	*noob = new Vector3f;

  noob->x = x * mult;
  noob->y = y * mult;
  noob->z = z * mult;
  return (*noob);
}

bool		Vector3f::operator==(const Vector3f &other) const
{
  if (this->x == other.x && this->y == other.y && this->z == other.z)
    return (true);
  return (false);
}

Vector3f&	Vector3f::operator+=(const float sum)
{
  this->x += sum;
  this->y += sum;
  this->z += sum;
  return (*this);
}

Vector3f&	Vector3f::operator+=(const Vector3f &other)
{
  this->x += other.x;
  this->y += other.y;
  this->z += other.z;
  return (*this);
}

Vector3f&	Vector3f::operator-=(const Vector3f &other)
{
  this->x -= other.x;
  this->y -= other.y;
  this->z -= other.z;
  return (*this);
}

Vector3f&	Vector3f::operator=(const Vector3f &other)
{
  this->x = other.x;
  this->y = other.y;
  this->z = other.z;
  return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Vector3f& vec)
{
  out << "Vector3f("
      << vec.x << ", "
      << vec.y << ", "
      << vec.z << ")";
  return (out);
}
