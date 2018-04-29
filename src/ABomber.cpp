//
// ABomber.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Fri May 17 20:29:08 2013 christopher steel
// Last update Thu Jun  6 09:59:09 2013 christopher steel
//

#include	<ABonus.hh>
#include	<ABomber.hh>
#include	<MyGame.hh>

namespace	Model
{
  ABomber::ABomber(const Vector3f& pos)
  {
    this->type = BOMBER_TYPE;
    this->collision = false;
    this->position_ = pos;
    this->immortal = GOD_MODE;
    this->score_ = 0;
  }

  ABomber::~ABomber(void)
  {

  }

  void		ABomber::initialize(void)
  {
    const std::string	animationName = "Take 001";

    this->model_ = gdl::Model::load(BOMBER_MESH);
    gdl::Model::cut_animation(model_, animationName, 36, 53, "RUN");
    gdl::Model::cut_animation(model_, animationName, 0, 0, "END");
    this->model_.set_default_model_color(*ColorManager::getColor());
    this->isRunning_ = false;
    this->speed = 1.0;
    this->bombCapacity = DEFAULT_BOMB_CAPACITY;
    this->bombRange = DEFAULT_BOMB_RANGE;
  }

  void		ABomber::draw(void)
  {
    std::list<Bomb *>::iterator	it;

    glPushMatrix();
    glTranslatef(position_.x, position_.y, 0);
    glRotatef(rotation_.z, 0, 0, 1);
    glRotatef(90, 1, 0, 0);
    glScalef(0.50, 0.50, 0.50);
    this->model_.draw();
    glPopMatrix();
    for (it = this->bombs.begin(); it != this->bombs.end(); it++)
      (*it)->draw();
  }

  float		ABomber::getX(void) const
  {
    return (this->position_.x);
  }

  float		ABomber::getY(void) const
  {
    return (this->position_.y);
  }

  void		ABomber::updateAnim(void)
  {
    if (this->currentAnim_ != "" && this->model_.anim_is_ended(this->currentAnim_))
      {
	this->model_.stop_animation("END");
	this->currentAnim_ = this->nextAnim_;
	if (this->currentAnim_ == "RUN")
	  this->nextAnim_ = "RUN";
	else
	  this->nextAnim_ = "";
	if (this->currentAnim_ != "")
	  {
	    this->model_.set_anim_speed(this->currentAnim_,
					(this->speed *
					 this->getAnimSpeedRatio(this->currentAnim_)));
	    this->model_.play(this->currentAnim_);
	  }
      }
  }

  void		ABomber::updateBombs(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    std::list<Bomb *>::iterator	it;

    for (it = this->bombs.begin(); it != this->bombs.end(); it++)
      {
	while (it != this->bombs.end() && (*it)->todelete_)
	  {
	    this->score_ += (*it)->score;
   	    delete (*it);
	    it = this->bombs.erase(it);
	  }
	if (it != this->bombs.end())
	  (*it)->update(gameClock, input);
      }
  }

  void		ABomber::addBomb(void)
  {
    Vector2f	vec;
    World	world = MyGame::getWorld();

    if (this->bombs.size() < (size_t)this->bombCapacity)
      {
	vec = Vector2f((TILE(this->position_.x) * TILE_SCALE) + TILE_SCALE / 2,
		       (TILE(this->position_.y) * TILE_SCALE) + TILE_SCALE / 2);
	if (!MyGame::isOccupied(world, vec))
	  {
	    this->bombs.push_back(new Bomb(Vector3f(vec.x, vec.y, BOMB_COMP_DIST), this->bombRange));
	    this->bombs.back()->initialize();
	  }
      }
  }

  double	ABomber::getAnimSpeedRatio(const std::string& name) const
  {
    if (name == "RUN")
      return (ANIM_RUN_SPEED);
    else if (name == "END")
      return (ANIM_END_SPEED);
    else
      return (0);
  }

  void		ABomber::moveLeft(const float& alphaTime)
  {
    float	newcd;

    this->rotation_.z = 270;
    newcd = this->position_.x - this->speed * DEFAULT_SPEED * alphaTime;
    if (this->checkCollision(Vector2f((newcd - COLL_COMP_DIST), this->position_.y)))
      this->position_.x = newcd;
  }

  void		ABomber::moveUp(const float& alphaTime)
  {
    float	newcd;

    this->rotation_.z = 180;
    newcd = this->position_.y + this->speed * DEFAULT_SPEED * alphaTime;
    if (this->checkCollision(Vector2f(this->position_.x, (newcd + COLL_COMP_DIST))))
      this->position_.y = newcd;
  }

  void		ABomber::moveRight(const float& alphaTime)
  {
    float	newcd;

    this->rotation_.z = 90;
    newcd = this->position_.x + this->speed * DEFAULT_SPEED * alphaTime;
    if (this->checkCollision(Vector2f((newcd + COLL_COMP_DIST), this->position_.y)))
      this->position_.x = newcd;
  }

  void		ABomber::moveDown(const float& alphaTime)
  {
    float	newcd;

    this->rotation_.z = 0;
    newcd = this->position_.y - this->speed * DEFAULT_SPEED * alphaTime;
    if (this->checkCollision(Vector2f(this->position_.x, (newcd - COLL_COMP_DIST))))
      this->position_.y = newcd;
  }

  bool		ABomber::checkCollision(const Vector2f & pos)
  {
    World	world = MyGame::getWorld();
    std::list<AObject *>  *obj;
    std::list<AObject *>::iterator        it;

    if (Vector2f(TILE(pos.x), TILE(pos.y)) != Vector2f(TILE(this->position_.x), TILE(this->position_.y)))
      {
	obj = MyGame::getOccupant(world, pos);
	for (it = obj->begin(); it != obj->end(); it++)
	  {
	    if ((*it)->type == "bonus")
	      dynamic_cast<Object::Bonus::ABonus *>(*it)->upgrade(this);
	    if ((*it)->collision && !(*it)->todelete_)
	      return (false);
	  }
      }
    return (true);
  }
}
