//
// ColorManager.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sat May 18 22:10:12 2013 christopher steel
// Last update Sun May 19 17:14:39 2013 christopher steel
//

#include	<ColorManager.hh>

static ColorManager	*cm = NULL;
static gdl::Color	colors[6] =
  {
    gdl::Color(0, 255, 0),
    gdl::Color(0, 0, 255),
    gdl::Color(255, 0, 0),
    gdl::Color(255, 255, 0),
    gdl::Color(0, 255, 255),
    gdl::Color(255, 0, 255)
  };

ColorManager::ColorManager()
{
  this->colorsGiven_ = 0;
  this->degression_ = 0;
}

ColorManager::~ColorManager()
{

}

void		ColorManager::create()
{
  if (!cm)
    cm = new ColorManager();
  else
    std::cerr << "ColorManager has already been created." << std::endl;
}

gdl::Color	*ColorManager::getColor()
{
  static unsigned int	cursor = 0;
  gdl::Color		*color;

  if (cursor == 6 ||
      (colors[cursor].r < 100 &&
       colors[cursor].g < 100 &&
       colors[cursor].b < 100))
    {
      cursor = 0;
      cm->degression_ += 20;
      if (cm->degression_ >= 255)
	cm->degression_ = 0 + (cm->colorsGiven_ / 25);
    }
  color = new gdl::Color((colors[cursor].r < 20 ? 0 : colors[cursor].r - cm->degression_),
			 (colors[cursor].g < 20 ? 0 : colors[cursor].g - cm->degression_),
			 (colors[cursor].b < 20 ? 0 : colors[cursor].b - cm->degression_));
  ++cm->colorsGiven_;
  ++cursor;
  return (color);
}
