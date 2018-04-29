//
// Vector2.hh for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Tue May  7 19:49:01 2013 christopher steel
// Last update Fri May 31 15:21:45 2013 christopher steel
//

#ifndef		VECTOR2_HH_
# define	VECTOR2_HH_

# include	<iostream>

struct		Vector2f
{
  float		x;
  float		y;

  Vector2f(void);
  Vector2f(float, float);
  Vector2f&	operator+(const Vector2f&) const;
  Vector2f&	operator-(const Vector2f&) const;
  Vector2f&	operator*(const Vector2f&) const;
  Vector2f&	operator*(const float) const;
  bool		operator!=(const Vector2f&) const;
  bool		operator==(const Vector2f&) const;
  Vector2f&	operator=(const Vector2f&);
};

std::ostream&	operator<<(std::ostream&, const Vector2f&);

#endif
