//
// ColorManager.hh for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sat May 18 22:10:06 2013 christopher steel
// Last update Sat May 18 23:23:11 2013 christopher steel
//

#ifndef			COLORMANAGER_HH_
# define		COLORMANAGER_HH_

# include		<iostream>

# include		<Color.hpp>

class			ColorManager
{
public:
  ColorManager();
  ~ColorManager();
  static void		create();
  static gdl::Color	*getColor();

private:
  unsigned int		colorsGiven_;
  unsigned int		degression_;
};

#endif
