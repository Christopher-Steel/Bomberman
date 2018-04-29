//
// Eventoids.hh for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Mon May 27 14:26:17 2013 christopher steel
// Last update Mon May 27 15:34:33 2013 christopher steel
//

#ifndef   EVENTOIDS_HH_
# define  EVENTOIDS_HH_

# include <Objects.hh>

namespace Object
{
  namespace   Eventoid
  {
    class   AEventoid : public TexturedCube
    {
    public:
      AEventoid(const Vector3f&, const Vector3f&, float, const std::string&);
      virtual ~AEventoid();
      virtual void  event(void) = 0;
    };

    class   Game1p : public AEventoid
    {
    public:
      Game1p(const Vector3f&, const Vector3f&, float);
      ~Game1p();
      void    destroy(void);
      void    event(void);
    };

        class   Game2p : public AEventoid
    {
    public:
      Game2p(const Vector3f&, const Vector3f&, float);
      ~Game2p();
      void    destroy(void);
      void    event(void);
    };

        class   Quit : public AEventoid
    {
    public:
      Quit(const Vector3f&, const Vector3f&, float);
      ~Quit();
      void    destroy(void);
      void    event(void);
    };

        class   Resume : public AEventoid
    {
    public:
      Resume(const Vector3f&, const Vector3f&, float);
      ~Resume();
      void    destroy(void);
      void    event(void);
    };

    class   Option : public AEventoid
    {
    public:
      Option(const Vector3f&, const Vector3f&, float);
      ~Option();
      void    destroy(void);
      void    event(void);
    };

    class   Map1 : public AEventoid
    {
    public:
      Map1(const Vector3f&, const Vector3f&, float);
      ~Map1();
      void    destroy(void);
      void    event(void);
    };

    class   Map2 : public AEventoid
    {
    public:
      Map2(const Vector3f&, const Vector3f&, float);
      ~Map2();
      void    destroy(void);
      void    event(void);
    };

    class   Map3 : public AEventoid
    {
    public:
      Map3(const Vector3f&, const Vector3f&, float);
      ~Map3();
      void    destroy(void);
      void    event(void);
    };

    class   Map4 : public AEventoid
    {
    public:
      Map4(const Vector3f&, const Vector3f&, float);
      ~Map4();
      void    destroy(void);
      void    event(void);
    };

    class   MapRandom : public AEventoid
    {
    public:
      MapRandom(const Vector3f&, const Vector3f&, float);
      ~MapRandom();
      void    destroy(void);
      void    event(void);
    };

    class   Retour : public AEventoid
    {
    public:
      Retour(const Vector3f&, const Vector3f&, float);
      ~Retour();
      void    destroy(void);
      void    event(void);
    };

    class   Fx : public AEventoid
    {
    public:
      Fx(const Vector3f&, const Vector3f&, float);
      ~Fx();
      void    destroy(void);
      void    event(void);
      bool    activation_;
    };

    class   Music : public AEventoid
    {
    public:
      Music(const Vector3f&, const Vector3f&, float);
      ~Music();
      void    destroy(void);
      void    event(void);
      bool    activation_;
    };
  }
}

#endif
