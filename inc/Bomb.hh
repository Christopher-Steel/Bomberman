//
// Bomb.hh for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Wed May  8 16:25:13 2013 christopher steel
// Last update Thu Jun  6 01:31:42 2013 simon bonin
//

#ifndef					BOMB_HH_
# define				BOMB_HH_

# include				<list>

# include				<defines.hh>
# include				<AObject.hpp>
# include				<Model.hpp>
# include				<Objects.hh>
# include				<Vector3.hh>
# include				<Vector2.hh>

namespace				Model
{
  class					Bomb : public AObject
  {
  public:
    Bomb(const Vector3f&, int);
    ~Bomb(void);

    void				initialize(void);
    void				update(gdl::GameClock const &, gdl::Input &);
    void				draw(void);
    void				getscore(AObject *);
    bool				killList(std::list<AObject *> *, AObject * = NULL);
    void				destroy(void);
    int				getRange(void);
    long				score;

  private:
    gdl::Model				model_;
    float				explodeTime_;
    int					range_;
    bool				exploding_;
  };
}

#endif
