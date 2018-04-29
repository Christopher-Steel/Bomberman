//
// LayoutLoader.cpp for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Mon May 27 18:14:47 2013 christopher steel
// Last update Wed May 21 14:31:49 2014 Christopher Steel
//

#include	<vector>
#include	<MapLoader.hh>

namespace	MapLoader
{
  void		AMapLoader::addFloor(void)
  {
    Vector2f	pos;

    pos = min + ((max - min) * 0.5f);
    world->push_back(new Object::Floor(pos, Vector2f(size->x, size->y)));
  }

  void		AMapLoader::createBorder(void)
  {
    Vector2f	pos;

    for (pos.x = min.x - TILE_SCALE; pos.x <= max.x + TILE_SCALE; pos.x += TILE_SCALE)
      {
	for (pos.y = min.y - TILE_SCALE; pos.y <= max.y + TILE_SCALE; pos.y += TILE_SCALE)
	  {
	    if (pos.y == min.y - TILE_SCALE || pos.y == max.y + TILE_SCALE ||
		pos.x == min.x - TILE_SCALE || pos.x == max.x + TILE_SCALE)
	      world->push_back(new Object::Wall(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
						Vector3f(0, 0, 0), TILE_SCALE));
	  }
      }
  }

  void		AMapLoader::createWallsNCrates(void)
  {
    Vector2f	pos;
    int		cursor;
    char	c;

    pos = Vector2f(min.x, max.y);
    for (cursor = 0; (c = (*this->layout)[cursor]); cursor++)
      {
	switch (c)
	  {
	  case WALL_C:
	    world->push_back(new Object::Wall(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
					      Vector3f(0, 0, 0), TILE_SCALE));
	    pos.x += TILE_SCALE;
	    break;
	  case CRATE_C:
	    world->push_back(new Object::Crate(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
					       Vector3f(0, 0, 0), TILE_SCALE));
	    pos.x += TILE_SCALE;
	    break;
          case PLAYER_1_C:
	    world->push_back(new Object::Eventoid::Game1p(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
							  Vector3f(0,0,0), TILE_SCALE));
	    pos.x +=  TILE_SCALE;
	    break;
	  case PLAYER_2_C:
	    world->push_back(new Object::Eventoid::Game2p(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
							  Vector3f(0,0,0), TILE_SCALE));
	    pos.x +=  TILE_SCALE;
	    break;
	  case EXIT_C:
	    world->push_back(new Object::Eventoid::Quit(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
							Vector3f(0,0,0), TILE_SCALE));
	    pos.x +=  TILE_SCALE;
	    break;
	  case OPTION_C:
	    world->push_back(new Object::Eventoid::Option(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
							  Vector3f(0,0,0), TILE_SCALE));
	    pos.x +=  TILE_SCALE;
	    break;
	  case RESUME_C:
	    world->push_back(new Object::Eventoid::Resume(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
							  Vector3f(0,0,0), TILE_SCALE));
	    pos.x +=  TILE_SCALE;
	    break;
	  case MAP1_C:
	    world->push_back(new Object::Eventoid::Map1(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
							Vector3f(0,0,0), TILE_SCALE));
	    pos.x +=  TILE_SCALE;
	    break;
	  case MAP2_C:
	    world->push_back(new Object::Eventoid::Map2(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
							Vector3f(0,0,0), TILE_SCALE));
	    pos.x +=  TILE_SCALE;
	    break;
	  case MAP3_C:
	    world->push_back(new Object::Eventoid::Map3(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
							Vector3f(0,0,0), TILE_SCALE));
	    pos.x +=  TILE_SCALE;
	    break;
	  case MAP4_C:
	    world->push_back(new Object::Eventoid::Map4(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
							Vector3f(0,0,0), TILE_SCALE));
	    pos.x +=  TILE_SCALE;
	    break;
	  case MAP_RANDOM_C:
	    world->push_back(new Object::Eventoid::MapRandom(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
							     Vector3f(0,0,0), TILE_SCALE));
	    pos.x +=  TILE_SCALE;
	    break;
	  case FX_C:
	    world->push_back(new Object::Eventoid::Fx(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
						      Vector3f(0,0,0), TILE_SCALE));
	    pos.x +=  TILE_SCALE;
	    break;
	  case MUSIC_C:
	    world->push_back(new Object::Eventoid::Music(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
							 Vector3f(0,0,0), TILE_SCALE));
	    pos.x +=  TILE_SCALE;
	    break;
	  case RETOUR_C:
	    world->push_back(new Object::Eventoid::Retour(Vector3f(pos.x, pos.y, TILE_SCALE / 2),
							  Vector3f(0,0,0), TILE_SCALE));
	    pos.x +=  TILE_SCALE;
	    break;
	  case '\n':
	    pos.y -= TILE_SCALE;
	    pos.x = min.x;
	    break;
	  default:
	    pos.x += TILE_SCALE;
	    break;
	  }
      }
  }

  Premade::Premade(const std::string& layoutName, const int nbPl, const int nbBot)
  {
    layout = getFileContents(MAP_DIR + layoutName);
    size = getSize(layout);
    world = MyGame::getWorld();
    *size = Vector2f(size->x * TILE_SCALE, size->y * TILE_SCALE);
    min = MAP_CENTER - (Vector2f(size->x / 2, size->y / 2));
    min = min - Vector2f((int)min.x % TILE_SCALE - TILE_SCALE / 2, (int)min.y % TILE_SCALE - TILE_SCALE / 2);
    max = MAP_CENTER + (Vector2f(size->x / 2, size->y / 2));
    max = max - Vector2f((int)max.x % TILE_SCALE + TILE_SCALE / 2, (int)max.y % TILE_SCALE + TILE_SCALE / 2);
    this->nbPl = nbPl;
    this->nbBot = nbBot;
  }

  Premade::~Premade(void)
  {

  }

  void			Premade::generate(void)
  {
    createBorder();
    addFloor();
    createWallsNCrates();
    //addBombers();
  }

  std::string		*Premade::getFileContents(const std::string& path) const
  {
    std::ifstream	file;
    std::stringstream	contents;

    file.open(path.c_str());
    if (file.good())
      {
	contents << file.rdbuf();
	file.close();
	return (new std::string(contents.str()));
      }
    std::cerr << "Bmap \"" << path << "\" not found" << std::endl;
    file.close();
    return (new std::string);
  }

  Vector2f		*Premade::getSize(const std::string *layout) const
  {
    Vector2f		*size;
    int			i;
    int			curLineSize = 0;

    size = new Vector2f();
    for (i = 0; (*layout)[i]; i++)
      {
	if ((*layout)[i] == '\n')
	  {
	    if (curLineSize > size->x)
	      size->x = curLineSize;
	    curLineSize = 0;
	    size->y++;
	  }
	else
	  curLineSize++;
      }
    if (curLineSize != 0)
      size->y++;
    return (size);
  }

  Random::Random(const int xray, const int yray, const int nbPl, const int nbBot)
  {
    layout = new std::string("");
    size = new Vector2f((xray * 2) + 1, (yray * 2) + 1);
    world = MyGame::getWorld();
    createMap();
    *size = Vector2f(size->x * TILE_SCALE, size->y * TILE_SCALE);
    min = MAP_CENTER - (Vector2f(size->x / 2, size->y / 2));
    min = min - Vector2f((int)min.x % TILE_SCALE - TILE_SCALE / 2, (int)min.y % TILE_SCALE - TILE_SCALE / 2);
    max = MAP_CENTER + (Vector2f(size->x / 2, size->y / 2));
    max = max - Vector2f((int)max.x % TILE_SCALE + TILE_SCALE / 2, (int)max.y % TILE_SCALE + TILE_SCALE / 2);
    this->nbPl = nbPl;
    this->nbBot = nbBot;
  }

  Random::~Random(void)
  {

  }

  void			Random::generate(void)
  {
    createBorder();
    addFloor();
    createWallsNCrates();
    //    addBombers();
  }

  int			Random::calculateNbCrates(void) const
  {
    int			compSpace;
    int			mapSpace;
    int			minCrateNb;
    int			maxCrateNb;
    int			crates;
    int			range;

    compSpace = ((int)size->x % 2 ? size->y : 0) + ((int)size->y % 2 ? size->x : 0);
    mapSpace = (size->x * size->y * 0.75) + compSpace + (compSpace == size->x + size->y ? 1 : 0);
    minCrateNb = MIN_RAND_CRATES * mapSpace / 100;
    maxCrateNb = MAX_RAND_CRATES * mapSpace / 100;
    range = (minCrateNb >= maxCrateNb ? 0 : (rand() % (maxCrateNb - minCrateNb)));
    crates = minCrateNb + range;
    return (crates);
  }

  void					Random::createMap(void)
  {
    std::vector<std::vector<char> >	genned((int)size->x, std::vector<char>((int)size->y, '.'));
    Vector2f				pos;
    int					crates;

    crates = calculateNbCrates();
    for (pos.x = 0; pos.x < size->x; pos.x++)
      for (pos.y = 0; pos.y < size->y; pos.y++)
	if ((int)pos.x % 2 && (int)pos.y % 2)
	  genned[(int)pos.x][(int)pos.y] = 'X';
    while (crates)
      {
    	pos.x = rand() % (int)size->x;
    	pos.y = rand() % (int)size->y;
    	if ((int)pos.x % 2 && (int)pos.y % 2)
	  {
	    pos.x += (pos.x + 1 >= size->x ? -1 : 1);
	    pos.y += (pos.y + 1 >= size->y ? -1 : 1);
	  }
	crates--;
	genned[(int)pos.x][(int)pos.y] = 'O';
      }
    for (pos.x = 0; pos.x < size->x; pos.x++)
      {
	for (pos.y = 0; pos.y < size->y; pos.y++)
	  layout->push_back(genned[(int)pos.x][(int)pos.y]);
	layout->push_back('\n');
      }
  }
}
