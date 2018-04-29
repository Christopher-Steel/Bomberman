//
// Bot.hh for bomberman in /home/dubour_f//projects/Bomberman/bomberman-2016-dubdub/inc
// 
// Made by frederic dubourg
// Login   <dubour_f@epitech.net>
// 
// Started on  Wed May 22 13:46:58 2013 frederic dubourg
// Last update Wed Jun  5 23:14:45 2013 frederic dubourg
//

#ifndef		BOT_HH_
# define	BOT_HH_

#include	<ABomber.hh>

namespace	Model
{
  class		Bot : public ABomber
  {
    enum			eDirection
      {
	STAND,
	RIGHT,
	LEFT,
	UP,
	DOWN
      };

  public:
    enum			eDifficulty
      {
	EASY,
	MEDIUM,
	HARD,
	GODLIKE
      };

  public:
    Bot(const Vector3f&, const eDifficulty);
    ~Bot();

    void			update(gdl::GameClock const&, gdl::Input &);

  private:
    // bool			isInDanger_;
    std::list<Vector3f>		collisions_;
    std::list<Vector3f>		danger_;
    // std::list<Vector3f>		escape_[4];
    eDirection			goal_;
    eDifficulty			level_;

    // void			findAnEscape();
    void			seekCollisions();
    void			seekDanger();
    bool			isDangerous(Vector3f);
    void			toSafePath(gdl::GameClock const&);
    void			toGoal(gdl::GameClock const&);
    void			setNewGoal(gdl::GameClock const&);
    void			moveTileRight(Vector3f*, gdl::GameClock const&);
    void			moveTileLeft(Vector3f*, gdl::GameClock const&);
    void			moveTileUp(Vector3f*, gdl::GameClock const&);
    void			moveTileDown(Vector3f*, gdl::GameClock const&);
    void			tryBomb();
  };
}
#endif
