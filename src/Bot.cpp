//
// Bot.cpp for bomberman in /home/dubour_f//projects/Bomberman/bomberman-2016-dubdub
// 
// Made by frederic dubourg
// Login   <dubour_f@epitech.net>
// 
// Started on  Wed May 22 13:59:56 2013 frederic dubourg
// Last update Wed Jun  5 23:29:16 2013 frederic dubourg
//

#include	<MyGame.hh>
#include	<defines.hh>
#include	<stdlib.h>
#include	<Bot.hh>

namespace	Model
{
  Bot::Bot(const Vector3f& pos, const eDifficulty level) :
    ABomber(pos)
  {
    this->goal_ = STAND;
    this->level_ = level;
    this->currentAnim_ = "RUN";
    this->nextAnim_ = "RUN";
  }

  Bot::~Bot()
  {}

  void		Bot::update(gdl::GameClock const& gameClock, gdl::Input &input)
  {
    this->isRunning_ = true;
    this->seekDanger();
    this->seekCollisions();
    this->updateAnim();
    this->model_.update(gameClock);
    if (this->goal_ != STAND)
      {
	this->moveTileLeft(NULL, gameClock);
	this->moveTileRight(NULL, gameClock);
	this->moveTileUp(NULL, gameClock);
	this->moveTileDown(NULL, gameClock);
      }
    // else if (this->isInDanger_)
    //   this->toSafePath(gameClock);
    else
      setNewGoal(gameClock);
    this->updateBombs(gameClock, input);
  }

  bool		Bot::isDangerous(Vector3f aim)
  {
    // std::list<Vector3f>::iterator it;

    // for (it = this->danger_.begin(); it != this->danger_.end(); it++)
    //   {
    // 	if (TILE3F(aim) == TILE3F((*it)))
    // 	  {
    // 	    // this->isInDanger = true;
    // 	    return (true);
    // 	  }
    //   }
    (void)aim;
    return (false);
  }

  // void		Bot::findAnEscape(const gdl::GameClock &gameClock)
  // {
  //   bool	find = false;
  //   int		dir = 0;
  //   int		tiles;
  //   std::list<Vector3f>::iterator	it;
  //   Vector3f	aim;
  //   Vector3f	directions[] = {Vector3f(200, 0, 0),
  // 				Vector3f(-200, 0, 0),
  // 				Vector3f(0, 200, 0),
  // 				Vector3f(0, -200, 0)};

  //   while (find != true && dir < 4)
  //     {
  // 	aim = this->getPosition();
  // 	tiles = 0;
  // 	for (it = this->collisions_.begin(); it != this->collisions_.end(); it++)
  // 	  {

  // 	  }
  // 	dir++;
  //     }
  // }

  void		Bot::seekDanger()
  {
    World	world = MyGame::getWorld();
    std::list<AObject *>::iterator it;
    std::list<Bomb *>::iterator	bomb;
    float	i = 1;
    int		dir = 0;
    Vector2f	aim;
    Vector3f	directions[] = {Vector3f(200, 0, 0),
				Vector3f(-200, 0, 0),
				Vector3f(0, 200, 0),
				Vector3f(0, -200, 0)};

    this->danger_.clear();
    for (it = world->begin(); it != world->end(); it++)
      {
	if ((*it)->type == BOMBER_TYPE)
	  {
	    for (bomb = ((ABomber *)(*it))->bombs.begin(); bomb != ((ABomber *)(*it))->bombs.end(); bomb++)
	      {
		dir = 0;
		this->danger_.push_back((*bomb)->getPosition());
		while (dir < 4)
		  {
		    i = 1;
		    while (i <= (*bomb)->getRange())
		      {
			aim.x += (*bomb)->getPosition().x + (directions[dir].x * i);
			aim.y += (*bomb)->getPosition().y + (directions[dir].y * i);
			if (MyGame::isOccupied(world, aim))
			  i = (*bomb)->getRange();
			else
			  {
			    this->danger_.push_back((*bomb)->getPosition() + (directions[dir] * i));
			    i++;
			  }
		      }
		    dir++;
		  }
	      }
	  }
      }
  }

  void		Bot::seekCollisions()
  {
    World	world = MyGame::getWorld();
    std::list<AObject *>::iterator it;

    for (it = world->begin(); it != world->end(); it++)
      {
    	if ((*it)->collision == true)
    	  this->collisions_.push_back((*it)->getPosition());
      }
  }

  void		Bot::moveTileLeft(Vector3f* vector, gdl::GameClock const& gameClock)
  {
    static Vector3f	goal;

    if (vector != NULL)
      {
	if (checkCollision(Vector2f(vector->x - 200, vector->y)))
	  goal = *vector + Vector3f(-200, 0, 0);
	else
	  this->goal_ = STAND;
      }
    else if (this->goal_ == LEFT)
      {
	if (this->position_.x > goal.x && this->checkCollision(Vector2f(goal.x, goal.y)) && !isDangerous(goal))
	  {
	    this->moveLeft(gameClock.getElapsedTime());
	    this->currentAnim_ = "RUN";
	  }
	else
	  {
	    this->tryBomb();
	    this->model_.stop_animation("RUN");
	    this->currentAnim_ = "END";
	    this->goal_ = STAND;
	  }
      }
  }

  void		Bot::moveTileRight(Vector3f* vector, gdl::GameClock const& gameClock)
  {
    static Vector3f	goal;

    if (vector != NULL)
      {
	if (checkCollision(Vector2f(vector->x + 200, vector->y)))
	  goal = *vector + Vector3f(200, 0 , 0);
	else
	  this->goal_ = STAND;
      }
    else if (this->goal_ == RIGHT)
      {
	if (this->position_.x < goal.x && this->checkCollision(Vector2f(goal.x, goal.y)) && !isDangerous(goal))
	  {
	    this->moveRight(gameClock.getElapsedTime());
	    this->currentAnim_ = "RUN";
	  }
	else
	  {
	    this->tryBomb();
	    this->goal_ = STAND;
	  }
      }
  }

  void		Bot::moveTileUp(Vector3f* vector, gdl::GameClock const& gameClock)
  {
    static Vector3f	goal;

    if (vector != NULL)
      {
	if (checkCollision(Vector2f(vector->x, vector->y + 190)))
	  goal = *vector + Vector3f(0, 200, 0);
	else
	  {
	    this->goal_ = STAND;
	  }
      }
    else if (this->goal_ == UP)
      {
	if (this->position_.y < goal.y && this->checkCollision(Vector2f(goal.x, goal.y)) && !isDangerous(goal))
	  {
	    this->moveUp(gameClock.getElapsedTime());
	    this->currentAnim_ = "RUN";
	  }
	else
	  {
	    this->tryBomb();
	    this->goal_ = STAND;
	  }
      }
  }

  void		Bot::moveTileDown(Vector3f* vector, gdl::GameClock const& gameClock)
  {
    static Vector3f	goal;

    if (vector != NULL)
      {
	if (checkCollision(Vector2f(vector->x, vector->y - 190)))
	  goal = *vector + Vector3f(0, -200, 0);
	else
	  {
	    this->goal_ = STAND;
	  }
      }
    else if (this->goal_ == DOWN)
      {
	if (this->position_.y > goal.y && this->checkCollision(Vector2f(goal.x, goal.y)) && !isDangerous(goal))
	  {
	    this->moveDown(gameClock.getElapsedTime());
	    this->currentAnim_ = "RUN";
	  }
	else
	  {
	    this->tryBomb();
	    this->goal_ = STAND;
	  }
      }
  }

  void		Bot::setNewGoal(gdl::GameClock const& gameClock)
  {
    int		r = random() % 4;
    void	(Bot::*fn[4])(Vector3f* ,gdl::GameClock const&) =
      {
	&Bot::moveTileRight,
	&Bot::moveTileLeft,
	&Bot::moveTileUp,
	&Bot::moveTileDown
      };

    this->goal_ = (eDirection)(r + 1);
    (this->*fn[r])(&this->position_, gameClock);
  }

  void		Bot::tryBomb()
  {
    int		r = random() % 100;

    if (r >= 85)
      this->addBomb();
  }
}
