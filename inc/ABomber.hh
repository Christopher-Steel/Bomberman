//
// ABomber.hh for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Fri May 17 17:59:25 2013 christopher steel
// Last update Wed Jun  5 20:06:50 2013 simon bonin
//

#ifndef		ABOMBER_HH_
# define	ABOMBER_HH_

# include	<list>

# include	<defines.hh>
# include	<AObject.hpp>
# include	<Model.hpp>
# include	<Vector2.hh>
# include	<Vector3.hh>
# include	<ColorManager.hh>
# include	<Bomb.hh>


namespace	Model
{
  class			ABomber : public AObject
  {
  public:
    ABomber(const Vector3f&);
    ~ABomber(void);

    void		initialize(void);
    virtual void	update(gdl::GameClock const &, gdl::Input &) = 0;
    void		draw(void);

    // virtual void	save() = 0;
    // virtual void	load() = 0;

    float		getX(void) const;
    float		getY(void) const;

  protected:
    void		updateAnim(void);
    double		getAnimSpeedRatio(const std::string&) const;
    void		updateBombs(gdl::GameClock const &, gdl::Input &);

    void		addBomb(void);
    void		removeBomb(const int id);

    void		moveLeft(const float&);
    void		moveUp(const float&);
    void		moveRight(const float&);
    void		moveDown(const float&);
    bool		checkCollision(const Vector2f&);

  public:
    float		speed;
    int			bombCapacity;
    int			bombRange;
    std::list<Bomb *>	bombs;

  protected:
    gdl::Model		model_;
    bool		isRunning_;
    std::string		currentAnim_;
    std::string		nextAnim_;
    long			score_;
  };
}

#endif
