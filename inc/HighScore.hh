#ifndef	HIGHSCORE_HH__
#define	HIGHSCORE_HH__

#include	<string>
#include	<vector>
#include	<defines.hh>

class	HighScore
{
private:
  struct	Score
  {
    Score();
    Score(const std::string& name, const long score);

    std::string	player;
    long		score;
  };

public:
  HighScore();
  ~HighScore();
  void dead(std::string player, long score);
private:
  std::vector<Score> scores;
};

#endif
