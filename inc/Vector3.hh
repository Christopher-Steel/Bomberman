//
// Vector3.hh for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sun May  5 17:47:52 2013 christopher steel
// Last update Wed Jun  5 18:54:05 2013 frederic dubourg
//

#ifndef		VECTOR3_HH_
# define	VECTOR3_HH_

# include	<iostream>

struct		Vector3f
{
  float		x;
  float		y;
  float		z;

  Vector3f(void);
  Vector3f(float, float, float);
  Vector3f(const Vector3f&);
  Vector3f&	operator+(const Vector3f&) const;
  Vector3f&	operator+=(const Vector3f&);
  Vector3f&	operator-(const Vector3f&) const;
  Vector3f&	operator-=(const Vector3f&);
  Vector3f&	operator=(const Vector3f&);
  bool		operator==(const Vector3f&) const;
  Vector3f&	operator*(const float) const;
  Vector3f&	operator+=(const float);
};
std::ostream&	operator<<(std::ostream& stream, const Vector3f&);

#endif
