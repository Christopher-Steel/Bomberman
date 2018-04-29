//
// ABonus.cpp for bomberman in /home/dubour_f//projects/Bomberman/bomberman-2016-dubdub
//
// Made by frederic dubourg
// Login   <dubour_f@epitech.net>
//
// Started on  Wed May 29 16:14:37 2013 frederic dubourg
// Last update Sat Jun  1 19:19:58 2013 christopher steel
//

#include	<ABonus.hh>

namespace	Object
{
  namespace	Bonus
  {
    ABonus::ABonus(const Vector3f& pos, const std::string& texture) :
      TexturedCube(pos, Vector3f(0, 0, 0), TILE_SCALE * BONUS_SCALE, texture)
    {
      position_ = pos;
      type = BONUS_TYPE;
      collision = false;
    }

    ABonus::~ABonus()
    {

    }

    Speed::Speed(const Vector3f& pos) : ABonus(pos, SPEED_TEXTURE){}

    Speed::~Speed()
    {

    }

    void	Speed::upgrade(Model::ABomber *bomber)
    {
      bomber->speed += 0.1f;
      this->destroy();
    }

    Bomb::Bomb(const Vector3f& pos) : ABonus(pos, BOMBS_TEXTURE){}

    Bomb::~Bomb(){}

    void	Bomb::upgrade(Model::ABomber *bomber)
    {
      bomber->bombCapacity += 1;
      this->destroy();
    }

    Range::Range(const Vector3f& pos) : ABonus(pos, RANGE_TEXTURE){}

    Range::~Range(){}

    void	Range::upgrade(Model::ABomber *bomber)
    {
      bomber->bombRange += 1;
      this->destroy();
    }
  }
}
