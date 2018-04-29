//
// Camera.cpp for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sat May  4 19:55:38 2013 christopher steel
// Last update Mon Jun  3 21:40:34 2013 christopher steel
//

#include	<Camera.hh>

Camera::Camera() :
  position_(0, CAMERA_HDIST, CAMERA_VDIST),
  rotation_(0.0f, 0.0f, 0.0f)
{

}

Camera::~Camera()
{

}

void		Camera::initialize(void)
{
  // Config du frustrum de la Camera
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0f, IMAGE_RATIO, 1.0f, 10000.0f);
  gluLookAt(this->position_.x, this->position_.y, this->position_.z,
	    0.0f, 0.0f, -1.0f,
	    0.0f, 1.0f, 0.0f);

  // Positionnement de la Camera
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // Activation des tests de profondeur
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

void		Camera::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  (void) gameClock;
  (void) input;
}
