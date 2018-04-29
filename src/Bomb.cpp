//
// Bomb.cpp for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Wed May  8 17:13:19 2013 christopher steel
// Last update Thu Jun  6 02:01:59 2013 simon bonin
//

#include	<Bomb.hh>
#include	<MyGame.hh>
#include	<ABomber.hh>
#include	<Objects.hh>

namespace	Model
{
  void		Bomb::initialize(void)
  {
    this->model_ = gdl::Model::load(BOMB_MESH);
  }

  Bomb::Bomb(const Vector3f& position, int range)
  {
    type = BOMB_TYPE;
    this->position_ = position;
    this->range_ = range;
    this->explodeTime_ = 0;
    this->exploding_ = false;
    this->score = 0;
  }

  Bomb::~Bomb(void)
  {

  }


  void					Bomb::getscore(AObject *obj)
  {
    Model::Bomb	*tnt;
    Model::ABomber	*brigitte;
    Object::Crate      	*box;
    
    if ((tnt = dynamic_cast<Model::Bomb *>(obj)) != NULL)
      {
	this->score += tnt->score;
      }
    else if ((brigitte = dynamic_cast<Model::ABomber *>(obj)) != NULL)
      {
	this->score += 420;
      }
    else if ((box = dynamic_cast<Object::Crate *>(obj)) != NULL)
      {
	this->score += 7;
      }
  }

  int					Bomb::getRange(void)
  {
    return (this->range_);
  }

  bool					Bomb::killList(std::list<AObject *> *list, AObject *except)
  {
    std::list<AObject *>::iterator	it;
    bool				blocked = false;

    for (it = list->begin(); it != list->end(); it++)
      {
	while (it != list->end() && (*it) != except)
	  {
	    if ((*it)->collision)
	      blocked = true;
	    if (!(*it)->immortal)
	      {
		getscore(*it);
		(*it)->destroy();
		it = list->erase(it);
	      }
	    else
	      break;
	  }
      }
    return (blocked);
  }

  void				Bomb::destroy(void)
  {
    World			world;
    Vector2f			ori[4] =
      {
	Vector2f(-1, 0),
	Vector2f(0, 1),
	Vector2f(1, 0),
	Vector2f(0, -1)
      };
    Vector2f			pos;
    std::list<AObject *>	*obj = NULL;
    int				i;
    int				d;
    Vector3f			laserPos;
    bool			blocked;

    this->todelete_ = true;
    world = MyGame::getWorld();
    pos = Vector2f(this->position_.x, this->position_.y);
    obj = MyGame::getOccupant(world, pos);
    killList(obj, this);
    world->push_back(new Object::Laseroid(Vector3f(pos.x, pos.y, TILE_SCALE / 2)));
    world->back()->initialize();
    world->push_back(new Object::Laseroid(Vector3f(pos.x, pos.y, TILE_SCALE / 2), true));
    world->back()->initialize();
    for (i = 0; i < 4; i++)
      {
	for (d = 1; d <= this->range_; d++)
	  {
	    obj = MyGame::getOccupant(world, Vector2f(pos.x + (ori[i].x * d * TILE_SCALE),
						      pos.y + (ori[i].y * d * TILE_SCALE)));
	    blocked = killList(obj);
	    if (obj->empty())
	      {
		laserPos = Vector3f(pos.x + (ori[i].x * d * TILE_SCALE),
				    pos.y + (ori[i].y * d * TILE_SCALE),
				    TILE_SCALE / 2);
		world->push_back(new Object::Laseroid(laserPos, (ori[i].x), (ori[i].x < 0)));
		world->back()->initialize();
	      }
	    if (blocked)
	      break;
	  }
      }
  }

  void		Bomb::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    (void) input;
    if (!this->todelete_)
      {
	this->model_.update(gameClock);
	if (!this->explodeTime_)
	  this->explodeTime_ = gameClock.getTotalGameTime() + FUSE_LENGTH;
	if (gameClock.getTotalGameTime() > this->explodeTime_)
	  this->destroy();
      }
  }

  void		Bomb::draw(void)
  {
    glPushMatrix();
    glTranslatef(position_.x, position_.y, position_.z);
    glRotatef(90, 1, 0, 0);
    glScalef(0.50, 0.50, 0.50);
    this->model_.draw();
    glPopMatrix();
  }
}
