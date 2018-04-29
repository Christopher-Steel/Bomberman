#include	<fstream>
#include	<iostream>
#include	"HighScore.hh"

HighScore::HighScore() : scores(10, Score())
{
  std::ifstream	ifs;
  std::string	ifs_content;
  Score		tmp;
  int			i;

  i = 0;
  ifs.open((HIGHSCORE_FILE).c_str());
  if (ifs.is_open()){
    while (!ifs.eof() && i < 20){
      ifs >> tmp.player >> tmp.score;
      dead(tmp.player, tmp.score);
      ++i;
    }
  }
  if (ifs.is_open())
    ifs.close();
}

HighScore::~HighScore()
{
  std::ofstream					ofs;
  std::string					ofs_content;
  std::vector<Score>::iterator  	it;

  it = scores.begin();
  ofs.open((HIGHSCORE_FILE).c_str(), std::ofstream::trunc);
  if (ofs.is_open()){
    while (it != scores.end()){
      ofs << it->player << " " << it->score << " ";
      it++;
    }
  }
  if (ofs.is_open())
    ofs.close();
}

void	HighScore::dead(std::string player, long score)
{
  std::vector<Score>::iterator	it;
  Score				       	tmp;

  tmp.player = player;
  tmp.score = score;
  it = scores.begin();
  while (it != scores.end()){
    if (score > it->score){
      scores.pop_back();
      scores.insert(it, tmp);
      break;
    }
    ++it;
  }
}

HighScore::Score::Score() : player("???"), score(0)
{

}

HighScore::Score::Score(const std::string& name, const long score) :
  player(name), score(score)
{

}
