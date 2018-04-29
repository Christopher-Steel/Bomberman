//
// Bomber.hh for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sun May  5 17:06:29 2013 christopher steel
// Last update Wed Jun  5 23:24:55 2013 simon bonin
//

#ifndef		BOMBER_HH_
# define	BOMBER_HH_

# include	<Options.hh>
# include	<ABomber.hh>
# include	<HighScore.hh>

namespace	Model
{
  class		Bomber : public ABomber
  {
  public:
    enum	eOrientation
      {
	Left = 0,
	Up = 1,
	Right = 2,
	Down = 3
      };

    struct		keyPress
    {
      gdl::Keys::Key	key;
      void		(Bomber::*fn)(const float&);
    };

  public:
    Bomber(const Vector3f&, const bool);
    ~Bomber(void);

    void	save();
    void	load();
    void    	destroy();
    void	update(gdl::GameClock const &, gdl::Input &);

  private:
    bool	pressedKey(const eOrientation ori) const;
    void	removeKey(const eOrientation ori);
    void	checkMove(gdl::GameClock const &, gdl::Input &);
    
    gdl::Color	*color_;
    std::list<eOrientation>	keys_;
    const bool	p1_;
  };
}

#endif
