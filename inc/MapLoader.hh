//
// MapLoader.hh for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Mon May 27 18:09:05 2013 christopher steel
// Last update Sat Jun  8 17:15:19 2013 christopher steel
//

#ifndef		MAPLOADER_HH_
# define	MAPLOADER_HH_

# include	<string>
# include	<fstream>
# include	<sstream>
# include	<iostream>

// for srand and rand
# include	<cstdlib>
# include	<ctime>

# include	<defines.hh>
# include	<Vector2.hh>
# include	<Objects.hh>
# include	<MyGame.hh>
# include	<Eventoids.hh>
# include	<Vector3.hh>

namespace	MapLoader
{
  class		AMapLoader
  {
  protected:
    void		addFloor(void);
    void		createBorder(void);
    void		createWallsNCrates(void);
    void		addBombers(void);
    virtual void	generate(void) = 0;
    Vector2f		*size;
    World		world;
    std::string		*layout;
    Vector2f		min;
    Vector2f		max;
    int			nbPl;
    int			nbBot;
  };

  class		Premade : public AMapLoader
  {
  public:
    Premade(const std::string&, const int, const int);
    ~Premade(void);

    std::string		*getFileContents(const std::string&) const;
    Vector2f		*getSize(const std::string *) const;
    void		generate(void);
  };

  class		Random : public AMapLoader
  {
  public:
    Random(const int, const int, const int, const int);
    ~Random(void);

    void		generate(void);
    int			calculateNbCrates(void) const;
    void		createMap(void);
  };
}

#endif
