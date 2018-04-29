//
// Crate.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sat May 18 17:09:14 2013 christopher steel
// Last update Mon Jun  3 17:49:19 2013 frederic dubourg
//

#include	<stdlib.h>
#include	<ABonus.hh>
#include	<MyGame.hh>
#include	<Objects.hh>

namespace	Object
{
  Crate::Crate(const Vector3f& pos, const Vector3f& rot, float size) :
    TexturedCube(pos, rot, size, CRATE_TEXTURE)
  {
    this->type = "crate";
  }

  Crate::~Crate()
  {

  }

  void		Crate::destroy(void)
  {
    World	world = MyGame::getWorld();
    int		r = rand() % 100;
    int		b = rand() % 3;

    this->todelete_ = true;
    if (r < BONUS_SPAWN_RATE)
      {
	if (b == 0)
	  world->push_back(new Object::Bonus::Bomb(this->position_));
	else if (b == 1)
	  world->push_back(new Object::Bonus::Speed(this->position_));
	else
	  world->push_back(new Object::Bonus::Range(this->position_));
	world->back()->initialize();
      }
  }
}
