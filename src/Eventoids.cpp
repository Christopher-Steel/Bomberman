//
// Eventoids.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Mon May 27 14:39:13 2013 christopher steel
// Last update Thu Jun  6 09:55:37 2013 christopher steel
//

#include  <iostream>

#include  <Eventoids.hh>
#include  <MapLoader.hh>
#include  <MyGame.hh>

namespace Object
{
  namespace Eventoid
  {
    AEventoid::AEventoid(const Vector3f& position, const Vector3f& rotation,
			 float size, const std::string& texture) :
      TexturedCube(position, rotation, size, texture)
    {
    }

    AEventoid::~AEventoid()
    {

    }

    Game1p::Game1p(const Vector3f& position, const Vector3f& rotation, const float size) :
      AEventoid(position, rotation, size, GAME1P_TEXTURE)
    {

    }

    Game1p::~Game1p()
    {

    }

    void  Game1p::destroy(void)
    {
      this->todelete_ = true;
      this->event();
    }

    void  Game1p::event(void)
    {
      MyGame *game;
      MyGame::getWorld(NULL, &game);

      game->toUnload = true;
      game->Map = MAP_SELECT;
      game->singlePlayer = true;
    }

    Game2p::Game2p(const Vector3f& position, const Vector3f& rotation, const float size) :
      AEventoid(position, rotation, size, GAME2P_TEXTURE)
    {

    }

    Game2p::~Game2p()
    {

    }

    void  Game2p::destroy(void)
    {
      this->todelete_ = true;
      this->event();
    }

    void  Game2p::event(void)
    {
      MyGame *game;
      MyGame::getWorld(NULL, &game);

      game->toUnload = true;
      game->Map = MAP_SELECT;
      game->singlePlayer = false;
    }

    Option::Option(const Vector3f& position, const Vector3f& rotation, const float size) :
      AEventoid(position, rotation, size, OPTIONS_TEXTURE)
    {

    }

    Option::~Option()
    {

    }

    void  Option::destroy(void)
    {
      this->todelete_ = true;
      this->event();
    }

    void  Option::event(void)
    {
      MyGame *game;
      MyGame::getWorld(NULL, &game);

      game->toUnload = true;
      game->Map = MAP_OPT;
    }

    Resume::Resume(const Vector3f& position, const Vector3f& rotation, const float size) :
      AEventoid(position, rotation, size, RESUME_TEXTURE)
    {

    }

    Resume::~Resume()
    {

    }

    void  Resume::destroy(void)
    {
      this->event();
    }

    void  Resume::event(void)
    {
      std::cout << "Load save - WIP" << std::endl;
    }

    Quit::Quit(const Vector3f& position, const Vector3f& rotation, const float size) :
      AEventoid(position, rotation, size, QUIT_TEXTURE)
    {

    }

    Quit::~Quit()
    {

    }

    void  Quit::destroy(void)
    {
      this->event();
    }

    void  Quit::event(void)
    {
      MyGame	*game;

      MyGame::getWorld(NULL, &game);
      game->closeWindow();
    }

    Map1::Map1(const Vector3f& position, const Vector3f& rotation, const float size) :
      AEventoid(position, rotation, size, MAP1_TEXTURE)
    {

    }

    Map1::~Map1()
    {

    }

    void  Map1::destroy(void)
    {
      this->todelete_ = true;
      this->event();
    }

    void  Map1::event(void)
    {
      MyGame *game;
      MyGame::getWorld(NULL, &game);

      game->toUnload = true;
      game->Map = MAP1;
    }

    Map2::Map2(const Vector3f& position, const Vector3f& rotation, const float size) :
      AEventoid(position, rotation, size, MAP2_TEXTURE)
    {

    }

    Map2::~Map2()
    {

    }

    void  Map2::destroy(void)
    {
      this->todelete_ = true;
      this->event();
    }

    void  Map2::event(void)
    {
      MyGame *game;
      MyGame::getWorld(NULL, &game);

      game->toUnload = true;
      game->Map = MAP2;
    }

    Map3::Map3(const Vector3f& position, const Vector3f& rotation, const float size) :
      AEventoid(position, rotation, size, MAP3_TEXTURE)
    {

    }

    Map3::~Map3()
    {

    }

    void  Map3::destroy(void)
    {
      this->todelete_ = true;
      this->event();
    }

    void  Map3::event(void)
    {
      MyGame *game;
      MyGame::getWorld(NULL, &game);

      game->toUnload = true;
      game->Map = MAP3;
    }

    Map4::Map4(const Vector3f& position, const Vector3f& rotation, const float size) :
      AEventoid(position, rotation, size, MAP4_TEXTURE)
    {

    }

    Map4::~Map4()
    {

    }

    void  Map4::destroy(void)
    {
      this->todelete_ = true;
      this->event();
    }

    void  Map4::event(void)
    {
      MyGame *game;
      MyGame::getWorld(NULL, &game);

      game->toUnload = true;
      game->Map = MAP4;
    }

    MapRandom::MapRandom(const Vector3f& position, const Vector3f& rotation, const float size) :
      AEventoid(position, rotation, size, MAPRANDOM_TEXTURE)
    {

    }

    MapRandom::~MapRandom()
    {

    }

    void  MapRandom::destroy(void)
    {
      this->todelete_ = true;
      this->event();
    }

    void  MapRandom::event(void)
    {
      MyGame *game;
      MyGame::getWorld(NULL, &game);

      game->toUnload = true;
      game->Map = "MAP_RANDOM";
    }

    Retour::Retour(const Vector3f& position, const Vector3f& rotation, const float size) :
      AEventoid(position, rotation, size, RETOUR_TEXTURE)
    {

    }

    Retour::~Retour()
    {

    }

    void  Retour::destroy(void)
    {
      this->todelete_ = true;
      this->event();
    }

    void  Retour::event(void)
    {
      MyGame *game;
      MyGame::getWorld(NULL, &game);

      game->toUnload = true;
      game->Map = MAP_MENU;
      game->singlePlayer = true;
    }

    Fx::Fx(const Vector3f& position, const Vector3f& rotation, const float size) :
      AEventoid(position, rotation, size, FX_TEXTURE)
    {
      this->activation_ = true;
    }

    Fx::~Fx()
    {

    }

    void  Fx::destroy(void)
    {
      if (this->activation_ == true)
        this->activation_ = false;
      else
        this->activation_ = true;
      this->todelete_ = false;
      this->event();
    }

    void  Fx::event(void)
    {
      if (this->activation_ == false)
        std::cout << "No Fx" << std::endl;
      else
        std::cout << "Launch Fx" << std::endl;
    }

    Music::Music(const Vector3f& position, const Vector3f& rotation, const float size) :
      AEventoid(position, rotation, size, MUSIC_TEXTURE)
    {
      this->activation_ = true;
    }

    Music::~Music()
    {

    }

    void  Music::destroy(void)
    {
      if (this->activation_ == true)
        this->activation_ = false;
      else
        this->activation_ = true;
      this->todelete_ = false;
      this->event();
    }

    void  Music::event(void)
    {
      if (this->activation_ == false)
        std::cout << "No Music" << std::endl;
      else
        std::cout << "Launch Music" << std::endl;
    }
  }
}
