//
// MyGame.hh for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sun May  5 17:27:34 2013 christopher steel
// Last update Sat Jun  8 17:18:34 2013 christopher steel
//

#ifndef			MYGAME_HH_
# define		MYGAME_HH_

# include		<list>
# include		<GL/gl.h>
# include		<GL/glu.h>

# include		<defines.hh>
# include		<HighScore.hh>
# include		<ColorManager.hh>
# include		<Options.hh>
# include		<Camera.hh>
# include		<Game.hpp>
# include		<AObject.hpp>
# include		<Objects.hh>
# include		<Primitives.hh>
# include		<Vector2.hh>
# include		<Vector3.hh>
# include		<ABomber.hh>

typedef			std::list<AObject *> *	World;

class			MyGame : public gdl::Game
{
public:
  void			initialize(void);
  void			update(void);
  void			startUp(void);
  void			focusPlayer(const bool, const bool); // true = pl1, false = pl2
  void			draw(void);
  void			unload(void);
  void			closeWindow(void);
  void			addPlayer(const bool, const bool);
  void			transferBombs(Model::ABomber *);
  void			endGame(void);
  void			loadModels(void);
  static bool		isOccupied(World, const Vector2f&);
  static std::list<AObject *>	*getOccupant(World, const Vector2f&);
  static World		getWorld(MyGame * = NULL, MyGame ** = NULL);
  static Options	*getOptions(Options * = NULL);
  static HighScore	*getHighScore(HighScore * = NULL);
  World			getObjects();

  bool			toUnload;
  std::string		Map;
  bool			singlePlayer;
  int			nbBots;

private:
  Camera		camera_;
  std::list<AObject *>	objects_;
  std::list<std::string>	text_;
  unsigned int		players_;
  std::list<AObject *>	playersList_;
  HighScore		highscore_;
};

#endif
