//
// Object.hh for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sat May  4 20:24:48 2013 christopher steel
// Last update Mon Jun  3 17:48:39 2013 frederic dubourg
//

#ifndef		OBJECT_HH_
# define	OBJECT_HH_

# include	<GL/gl.h>
# include	<GL/glu.h>
# include	<string>

# include	<defines.hh>
# include	<Vector3.hh>
# include	<AObject.hpp>
# include	<Image.hpp>
# include	<Color.hpp>
# include	<Primitives.hh>

namespace	Object
{
  //
  // Cuboids
  //

  class			ACuboid : public AObject
  {
  public:
    ACuboid(const Vector3f&, const Vector3f&, const Vector3f&);
    virtual ~ACuboid(void);
    virtual void	initialize(void) = 0;
    virtual void	update(gdl::GameClock const &, gdl::Input &) = 0;
    void		draw(void);

  protected:
    Vector3f		size_;
    GLuint		model_;
  };

  class			ColoredCuboid : public ACuboid
  {
  public:
    ColoredCuboid(const Vector3f&, const Vector3f&, const Vector3f&, const gdl::Color&);
    virtual ~ColoredCuboid(void);
    void		initialize(void);
    virtual void	update(gdl::GameClock const &, gdl::Input &);

  private:
    gdl::Color		color_;
  };

  class			TexturedCuboid : public ACuboid
  {
  public:
    TexturedCuboid(const Vector3f&, const Vector3f&, const Vector3f&, const std::string&);
    virtual ~TexturedCuboid(void);
    void		initialize(void);
    virtual void	update(gdl::GameClock const &, gdl::Input &);

  private:
    gdl::Image		texture_;
  };

  class			Laseroid : public TexturedCuboid
  {
  public:
    Laseroid(const Vector3f&, const bool = false, const bool = false);
    virtual ~Laseroid(void);
    virtual void	update(gdl::GameClock const &, gdl::Input &);

  private:
    float		finalTime_;
    float		updateTime_;
    float		totalAdded_;
  };

  class			Floor : public TexturedCuboid
  {
  public:
    Floor(const Vector2f&, const Vector2f&);
    virtual ~Floor(void);
  };

  class			Sign : public TexturedCuboid
  {
    Sign(const Vector3f&, const Vector3f&, const Vector2f&, const std::string&);
    ~Sign();
  };

  //
  // Cubes
  //

  class			ACube : public ACuboid
  {
  public:
    ACube(const Vector3f&, const Vector3f&, float);
    virtual ~ACube(void);
    virtual void	initialize(void) = 0;
    virtual void	update(gdl::GameClock const &, gdl::Input &) = 0;

  protected:
    float		size_;
  };

  class			ColoredCube : public ColoredCuboid
  {
  public:
    ColoredCube(const Vector3f&, const Vector3f&, float, const gdl::Color&);
    virtual ~ColoredCube(void);
  };

  class			TexturedCube : public TexturedCuboid
  {
  public:
    TexturedCube(const Vector3f&, const Vector3f&, float, const std::string&);
    virtual ~TexturedCube(void);
  };

  class			Wall : public TexturedCube
  {
  public:
    Wall(const Vector3f&, const Vector3f&, float);
    ~Wall(void);
  };

  class			Crate : public TexturedCube
  {
  public:
    Crate(const Vector3f&, const Vector3f&, float);
    ~Crate(void);

    virtual void		destroy(void);
  };
}

#endif
