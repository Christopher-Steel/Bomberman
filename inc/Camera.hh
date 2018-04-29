//
// Camera.hh for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sat May  4 19:52:31 2013 christopher steel
// Last update Sat Jun  1 18:35:58 2013 christopher steel
//

#ifndef			CAMERA_HH_
# define		CAMERA_HH_

# include		<GL/gl.h>
# include		<GL/glu.h>

# include		<defines.hh>
# include		<GameClock.hpp>
# include		<Input.hpp>
# include		<Vector3.hh>

class			Camera
{
public:
  Camera();
  ~Camera();

  void			initialize(void);
  void			update(gdl::GameClock const &, gdl::Input &);

  Vector3f		position_;
  Vector3f		rotation_;
};

#endif
