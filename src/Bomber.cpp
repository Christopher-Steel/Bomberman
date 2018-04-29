//
// Bomber.cpp for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sun May  5 17:10:28 2013 christopher steel
// Last update Thu Jun  6 09:41:15 2013 christopher steel
//

#include	<Bomber.hh>
#include	<MyGame.hh>

namespace	Model
{
  Bomber::Bomber(const Vector3f& position, const bool p1) :
    ABomber(position), p1_(p1)
  {
  }

  Bomber::~Bomber(void)
  {
  }

  void		Bomber::save()
  {

  }

  void		Bomber::load()
  {

  }

  void		Bomber::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    Options	*opt = MyGame::getOptions();

    this->checkMove(gameClock, input);
    this->updateAnim();
    this->model_.update(gameClock);
    if (input.isKeyDown((p1_ ? opt->p1.bomb : opt->p2.bomb)))
      this->addBomb();
    this->updateBombs(gameClock, input);
  }

  void		Bomber::checkMove(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    int		i;
    Options	*opt = MyGame::getOptions();
    keyPress	pressed[4] =
      {
	{(p1_ ? opt->p1.left : opt->p2.left), &Bomber::moveLeft},
	{(p1_ ? opt->p1.up : opt->p2.up), &Bomber::moveUp},
	{(p1_ ? opt->p1.right : opt->p2.right), &Bomber::moveRight},
	{(p1_ ? opt->p1.down : opt->p2.down), &Bomber::moveDown}
      };

    for (i = 0; i < 4; i++)
      {
	if (input.isKeyDown(pressed[i].key))
	  {
	    if (!this->pressedKey((eOrientation)i))
	      this->keys_.push_back((eOrientation)i);
	  }
	else if (this->pressedKey((eOrientation)i))
	  this->removeKey((eOrientation)i);
      }
    if (!this->keys_.empty())
      {
	(this->*pressed[(int)this->keys_.back()].fn)(gameClock.getElapsedTime());
	if (this->isRunning_ == false)
	  {
	    this->model_.stop_animation("END");
	    this->model_.stop_animation("RUN");
	    this->isRunning_ = true;
	    this->currentAnim_ = "RUN";
	    this->nextAnim_ = "RUN";
	  }
      }
  }

  bool		Bomber::pressedKey(const eOrientation ori) const
  {
    std::list<eOrientation>::const_iterator	it;

    for (it = this->keys_.begin(); it != this->keys_.end(); it++)
      if ((*it) == ori)
	return (true);
    return (false);
  }

  void		Bomber::removeKey(const eOrientation ori)
  {
    std::list<eOrientation>::iterator		it;

    for (it = this->keys_.begin(); it != this->keys_.end(); it++)
      if ((*it) == ori)
	{
	  it = this->keys_.erase(it);
	  if (this->keys_.empty())
	    {
	      this->model_.stop_animation(this->currentAnim_);
	      this->nextAnim_ = "END";
	      this->isRunning_ = false;
	    }
	  return ;
	}
  }

  void		Bomber::destroy()
  {
    HighScore	*hs;
    Options	*opt;

    hs = MyGame::getHighScore();
    opt = MyGame::getOptions();
    this->todelete_ = true;
    hs->dead((this->p1_ ? opt->name1 : opt->name2), this->score_);
  }
}
