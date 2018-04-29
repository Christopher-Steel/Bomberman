//
// Laseroid.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Fri May 24 11:45:23 2013 christopher steel
// Last update Sat May 25 18:12:00 2013 christopher steel
//

#include	<Objects.hh>

namespace	Object
{
  Laseroid::Laseroid(const Vector3f& position, const bool horizontal, const bool inverted)
    : TexturedCuboid(position,
		     Vector3f(0, 0, (horizontal ? 90 : 0) + (inverted ? 180 : 0)),
		     Vector3f(TILE_SCALE / 4, TILE_SCALE, TILE_SCALE / 4),
		     LASER_TEXTURE)
  {
    this->type = "laseroid";
    this->immortal = true;
    this->finalTime_ = 0;
    this->updateTime_ = 0;
    this->totalAdded_ = 0;
  }

  Laseroid::~Laseroid()
  {

  }

  void		Laseroid::update(gdl::GameClock const& gameClock, gdl::Input& input)
  {
    float	currentTime;
    float	addedSize;

    (void) input;
    currentTime = gameClock.getTotalGameTime();
    if (!this->finalTime_)
      this->finalTime_ = currentTime + EXPLOSION_LIFESPAN;
    else if (this->finalTime_ < currentTime)
      this->destroy();
    addedSize = (EXPLOSION_ADDED_SIZE / EXPLOSION_LIFESPAN) * gameClock.getElapsedTime();
    if (this->totalAdded_ + addedSize > EXPLOSION_ADDED_SIZE)
      addedSize = EXPLOSION_ADDED_SIZE - this->totalAdded_;
    this->size_ += Vector3f(addedSize, 0, addedSize);
    this->totalAdded_ += addedSize;
   }
}
