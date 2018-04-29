//
// MyGame.cpp for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sun May  5 17:30:41 2013 christopher steel
// Last update Sat Jun  8 17:31:35 2013 christopher steel
//

#include        <iostream>
#include        <fstream>

#include	<MyGame.hh>
#include	<Bot.hh>
#include	<Bomber.hh>
#include	<Bomb.hh>
#include        <Vector3.hh>
#include	<MapLoader.hh>

#include	<Text.hpp>

void		MyGame::initialize(void)
{
  std::list<AObject *>::iterator	it;
  Options				*opt = new Options();

  this->players_ = 0;
  this->toUnload = false;
  this->window_.setWidth(WINDOW_WIDTH);
  this->window_.setHeight(WINDOW_HEIGHT);
  this->window_.setTitle(WINDOW_NAME);
  this->window_.create();
  this->camera_.initialize();

  this->loadModels();
  MyGame::getWorld(this);
  MyGame::getOptions(opt);
  MyGame::getHighScore(&this->highscore_);
  ColorManager::create();

  for (it = this->objects_.begin(); it != this->objects_.end(); it++)
    (*it)->initialize();
}

void		MyGame::update(void)
{
  std::list<AObject *>::iterator it;

  if (this->players_ == 0)
    endGame();
  if (this->toUnload == true)
    startUp();
  else
    {
      this->camera_.update(this->gameClock_, this->input_);
      for (it = this->objects_.begin(); it != this->objects_.end(); it++)
	{
	  while (it != this->objects_.end() && (*it)->todelete_ == true)
	    {
	      if ((*it)->type == BOMBER_TYPE)
		{
		  transferBombs(dynamic_cast<Model::ABomber *>(*it));
		  this->players_--;
		}
	      delete (*it);
	      it = this->objects_.erase(it);
	    }
	  if (it != this->objects_.end())
	    (*it)->update(this->gameClock_, this->input_);
	}
    }
}

void    MyGame::startUp()
{
  std::list<AObject *>::iterator it;
  int   pl;

  this->unload();
  pl = (this->singlePlayer ? 1 : 2);
  if (this->Map == "MAP_RANDOM")
    {
      MapLoader::Random map(2 + rand() % 20, 2 + rand() % 20, pl, nbBots);
      map.generate();
    }
  else
    {
      MapLoader::Premade  map(this->Map, pl, nbBots);
      map.generate();
    }
  for (int i = 0; i < pl; i++)
    addPlayer(true, (bool)(!i));
  for (it = this->objects_.begin(); it != this->objects_.end(); it++)
    (*it)->initialize();
}

void		MyGame::focusPlayer(bool player1, bool singleP)
{
  Vector3f				camPos;
  Vector3f				plPos;
  unsigned int				winW;
  unsigned int				winH;

  if (player1)
    plPos = (*this->playersList_.begin())->getPosition();
  else
    plPos = (*(++this->playersList_.begin()))->getPosition();
  winW = this->window_.getWidth();
  winH = this->window_.getHeight();
  camPos = plPos + this->camera_.position_;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glViewport((player1 ? 0 : (winW / 2) + 2), 0, (singleP ? winW : (winW / 2) - 2), winH);
  gluPerspective(60.0f, ((float)winW / (singleP ? 1 : 2)) / (float)winH, 1.0f, 10000.0f);
  gluLookAt(camPos.x, camPos.y, camPos.z,
	    plPos.x, plPos.y, plPos.z,
	    0.0f, 1.0f, 0.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void		MyGame::draw(void)
{
  std::list<AObject *>::iterator	it;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0, 0, 0, 1.0f);
  glClearDepth(1.0f);

  focusPlayer(true, this->singlePlayer);
  for (it = this->objects_.begin(); it != this->objects_.end(); it++)
    (*it)->draw();

  if (!this->singlePlayer)
    {
      focusPlayer(false, false);
      for (it = this->objects_.begin(); it != this->objects_.end(); it++)
	(*it)->draw();
    }
}

void		MyGame::unload(void)
{
  std::list<AObject *>::iterator  it;
  Model::ABomber                  *bomber;

  it = this->objects_.begin();
  while (it != this->objects_.end())
    {
      if ((bomber = dynamic_cast<Model::ABomber *>(*it)))
	{
	  std::list<Model::Bomb *>::iterator bomb;

	  bomb = bomber->bombs.begin();
	  while (bomb != bomber->bombs.end())
	    {
	      delete(*bomb);
	      bomb = bomber->bombs.erase(bomb);
	    }
	  this->players_--;
	}
      delete (*it);
      it = this->objects_.erase(it);
    }
  this->toUnload = false;
}

void		MyGame::closeWindow(void)
{
  this->window_.close();
}

void		MyGame::addPlayer(bool type, bool p1)
{
  this->players_++;
  if (type)
    {
      this->objects_.push_front(new Model::Bomber(Vector3f(300, 100, 100), p1));
      this->playersList_.push_front(this->objects_.front());
    }
  else
    {
      this->objects_.push_front(new Model::Bot(Vector3f(300, 100, 100), Model::Bot::EASY));
      (void) p1;
    }
}

void		MyGame::transferBombs(Model::ABomber *bomber)
{
  std::list<Model::Bomb *>::iterator	it;

  for (it = bomber->bombs.begin(); it != bomber->bombs.end();)
    {
      this->objects_.push_front(dynamic_cast<Model::Bomb *>(*it));
      it = bomber->bombs.erase(it);
    }
}

void		MyGame::endGame(void)
{
  this->toUnload = true;
  this->Map = MAP_MENU;
  this->singlePlayer = true;
}

void		MyGame::loadModels(void)
{
  gdl::Model::load(BOMBER_MESH);
  gdl::Model::load(BOMB_MESH);
}

std::list<AObject *>	*MyGame::getOccupant(World world, const Vector2f& pos)
{
  std::list<AObject *>::iterator	it;
  std::list<Model::Bomb *>::iterator	itb;
  std::list<AObject *>			*found = new std::list<AObject *>;

  for (it = world->begin(); it != world->end(); it++)
    {
      if (!(*it)->todelete_ &&
	  TILE(((*it)->getPosition().x)) == TILE(pos.x) &&
	  TILE(((*it)->getPosition().y)) == TILE(pos.y))
	found->push_back(*it);
      if ((*it)->type == BOMBER_TYPE && (*it)->todelete_ == false)
	for (itb = ((Model::Bomber *)(*it))->bombs.begin(); itb != ((Model::Bomber *)(*it))->bombs.end(); itb++)
	  if (!(*itb)->todelete_ &&
	      TILE(((*itb)->getPosition().x)) == TILE(pos.x) &&
	      TILE(((*itb)->getPosition().y)) == TILE(pos.y))
	    found->push_back(*itb);
    }
  return (found);
}

bool		MyGame::isOccupied(World world, const Vector2f& pos)
{
  std::list<AObject *>	*obj;
  std::list<AObject *>::iterator	it;

  obj = MyGame::getOccupant(world, pos);
  for (it = obj->begin(); it != obj->end(); it++)
    {
      if ((*it)->collision == true)
	return (true);
    }
  return (false);
}

World		MyGame::getWorld(MyGame *game, MyGame **stockHere)
{
  static MyGame	*gameWorld = NULL;

  if (game)
    gameWorld = game;
  if (stockHere)
    *stockHere = gameWorld;
  if (gameWorld)
    return (gameWorld->getObjects());
  return (NULL);
}

Options			*MyGame::getOptions(Options *opt)
{
  static Options	*options = NULL;

  if (opt)
    options = opt;
  if (options)
    return (options);
  return (NULL);
}

HighScore			*MyGame::getHighScore(HighScore *hs)
{
  static HighScore	*scores = NULL;

  if (hs)
    scores = hs;
  if (scores)
    return (scores);
  return (NULL);
}

World		MyGame::getObjects()
{
  return (&this->objects_);
}


//////////////////////////////////////////////////////////////////////
//////////
//////////
//////////                MUSIQUE
//////////
//////////////////////////////////////////////////////////////////////

// sf::SoundBuffer buffer;

// buffer.LoadFromFile("sounds/music.ogg");
// sf::Sound sound;
// sound.SetBuffer(buffer);
// sound.SetLoop(true);
// sound.SetPitch(1.5f);
// sound.SetVolume(75.f);
// sound.Play();

// while(sound.GetStatus() == sf::Sound::Playing)
//   ;

// usleep(10000);
