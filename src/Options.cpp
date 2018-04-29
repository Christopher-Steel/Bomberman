//
// Options.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Mon May 20 11:43:07 2013 christopher steel
// Last update Mon Jun  3 23:00:01 2013 christopher steel
//

#include	<Options.hh>

Options::Options()
{
  music = false;
  sfx = false;
  p1 = KeySet(PL1_UP, PL1_DOWN, PL1_LEFT, PL1_RIGHT, PL1_BOMB, PL1_ACTION);
  p2 = KeySet(PL2_UP, PL2_DOWN, PL2_LEFT, PL2_RIGHT, PL2_BOMB, PL2_ACTION);
  name1 = "PL1";
  name2 = "PL2";
}

Options::~Options()
{

}

Options::KeySet::KeySet()
{

}

Options::KeySet::KeySet(const gdl::Keys::Key& up,
			const gdl::Keys::Key& down,
			const gdl::Keys::Key& left,
			const gdl::Keys::Key& right,
			const gdl::Keys::Key& bomb,
			const gdl::Keys::Key& action) :
  up(up), down(down), left(left), right(right), bomb(bomb), action(action)
{

}

Options::KeySet::~KeySet()
{

}

Options::KeySet&	Options::KeySet::operator=(const KeySet& other)
{
  up = other.up;
  down = other.down;
  left = other.left;
  right = other.right;
  bomb = other.bomb;
  action = other.action;
  return (*this);
}
