//
// Primitives.hh for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sat May  4 20:05:27 2013 christopher steel
// Last update Wed May 22 13:35:32 2013 christopher steel
//

#ifndef		PRIMITIVES_HH_
# define	PRIMITIVES_HH_

# include	<GL/gl.h>
# include	<GL/glu.h>

# include	<defines.hh>
# include	<Image.hpp>
# include	<AObject.hpp>
# include	<Vector3.hh>
# include	<Vector2.hh>

namespace	Primitive
{
  class		Triangle : public AObject
  {
  public:
    void	initialize(void);
    void	update(gdl::GameClock const &, gdl::Input &);
    void	draw(void);
  };

  class		Rectangle : public AObject
  {
  public:
    Rectangle(const Vector3f&, const Vector3f&, const Vector2f&, const Vector3f &);
    Rectangle(const Vector3f&, const Vector3f&, const Vector2f&, const std::string &);
    ~Rectangle();

    void	initialize(void);
    void	update(gdl::GameClock const &, gdl::Input &);
    void	draw(void);

  private:
    gdl::Image	texture_;
    Vector3f	color_;
    Vector2f	size_;
    const bool	tex_;
  };
}

#endif
