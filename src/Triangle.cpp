//
// Primitives.cpp for bomberman in /home/steel_c//Code/Bomberman
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Sat May  4 20:08:26 2013 christopher steel
// Last update Sat May  4 20:13:13 2013 christopher steel
//

#include	<Primitives.hh>

namespace	Primitive
{
  void		Triangle::initialize(void)
  {

  }

  void		Triangle::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {

  }

  void		Triangle::draw(void)
  {
    // Demarrage d'un contexte de rendu
    glBegin(GL_TRIANGLES);

    // Configuration de la couleur des vertices
    glColor3f(1.0f, 0.50f, 0.75f);

    // Dessin des vertices
    glVertex3f(0.0f, 150.0f, 0.0f);
    glVertex3f(-150.0f, 0.0f, 0.0f);
    glVertex3f(150.0f, 0.0f, 0.0f);

    // Fin du contexte de rendu
    glEnd();
  }
}
