//
// AObject.hh for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sun May  5 17:23:54 2013 christopher steel
// Last update Wed May 29 16:33:28 2013 christopher steel
//

#ifndef			AOBJECT_HPP_
# define		AOBJECT_HPP_

# include		<defines.hh>
# include		<Game.hpp>
# include		<Clock.hpp>
# include		<Input.hpp>
# include		<Vector3.hh>

class			AObject
{
public:
  AObject(void) : todelete_(false), immortal(false), collision(true),
		  position_(0.0f, 0.0f, 0.0f), rotation_(0.0f, 0.0f, 0.0f){}
  virtual ~AObject(void) {}

  virtual void		initialize(void) = 0;
  virtual void		update(gdl::GameClock const &, gdl::Input &) = 0;
  virtual void		draw(void) = 0;
  const Vector3f&	getPosition() const {return (this->position_);}
  virtual void		destroy() {this->todelete_ = true;}
  // virtual void		save() = 0;
  // virtual void		load() = 0;

  std::string		type;
  bool			todelete_;
  bool			immortal;
  bool			collision;

protected:
  Vector3f		position_;
  Vector3f		rotation_;
};

#endif
