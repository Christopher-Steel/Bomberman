//
// ABonus.hh for bomberman in /home/dubour_f//projects/Bomberman/bomberman-2016-dubdub
// 
// Made by frederic dubourg
// Login   <dubour_f@epitech.net>
// 
// Started on  Wed May 29 16:14:09 2013 frederic dubourg
// Last update Fri May 31 16:23:36 2013 frederic dubourg
//

#ifndef		ABONUS_HH_
# define	ABONUS_HH_

#include	<AObject.hpp>
#include	<ABomber.hh>

namespace	Object
{
  namespace	Bonus
  {
    class		ABonus : public TexturedCube
    {
    public:
      ABonus(const Vector3f&, const std::string&);
      ~ABonus();

      virtual void	upgrade(Model::ABomber *) = 0;
    };

    class		Speed : public ABonus
    {
    public:
      Speed(const Vector3f&);
      ~Speed();

      void		upgrade(Model::ABomber *);
    };

    class		Bomb : public ABonus
    {
    public:
      Bomb(const Vector3f&);
      ~Bomb();

      void		upgrade(Model::ABomber *);
    };

    class		Range : public ABonus
    {
    public:
      Range(const Vector3f&);
      ~Range();

      void		upgrade(Model::ABomber *);
    };
  }
}

#endif
