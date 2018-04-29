//
// Options.hh for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Mon May 20 11:43:15 2013 christopher steel
// Last update Mon Jun  3 22:59:21 2013 christopher steel
//

#ifndef		OPTIONS_HH_
# define	OPTIONS_HH_

# include	<defines.hh>
# include	<Input.hpp>

struct		Options
{
  struct		KeySet
  {
    KeySet();
    KeySet(const gdl::Keys::Key&,
	   const gdl::Keys::Key&,
	   const gdl::Keys::Key&,
	   const gdl::Keys::Key&,
	   const gdl::Keys::Key&,
	   const gdl::Keys::Key&);
    ~KeySet();
    Options::KeySet&	operator=(const KeySet&);

    gdl::Keys::Key	up;
    gdl::Keys::Key	down;
    gdl::Keys::Key	left;
    gdl::Keys::Key	right;
    gdl::Keys::Key	bomb;
    gdl::Keys::Key	action;
  };

  Options();
  ~Options();

  bool		music;
  bool		sfx;
  KeySet	p1;
  KeySet	p2;
  std::string	name1;
  std::string	name2;
};

#endif
