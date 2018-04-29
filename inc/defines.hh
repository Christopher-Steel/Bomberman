//
// defines.hh for bomberman in /home/steel_c//Code/bomberman-2016-dubdub
//
// Made by christopher steel
// Login   <steel_c@epitech.net>
//
// Started on  Fri May 17 18:02:02 2013 christopher steel
// Last update Thu Jun  6 09:31:21 2013 christopher steel
//

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
/////
/////			This file contains defines that are important for the game's logic.
/////	WARNING /!\	If you decide to modify any value contained hereafter, we can not
/////			guarantee that the game will work to any extent and will not be
/////			held responsible for any software failures.
/////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

# include	<math.h>
# include	<Input.hpp>

//
// defines
//

// anim speeds
# define	ANIM_START_SPEED	2
# define	ANIM_RUN_SPEED		0.6
# define	ANIM_END_SPEED		1

// collision and grid placement compensations
# define	COLL_COMP_DIST		70.0f
# define	BOMB_COMP_DIST		55.0f

// size related
# define	TILE_SCALE		200
# define	TILE(a)			(((int)floor(a) / TILE_SCALE) - (a >= 0 ? 0 : 1))
# define	TILE3F(a)		Vector3f(TILE(a.x), TILE(a.y), TILE(a.z))
# define	MAP_CENTER		Vector2f(100, 100)
# define	BONUS_SCALE		0.65

// bomber defaults
# define	DEFAULT_SPEED		TILE_SCALE * 2
# define	DEFAULT_BOMB_CAPACITY	1
# define	DEFAULT_BOMB_RANGE	2
# define 	GOD_MODE		false

// player default keys
# define	PL1_UP			gdl::Keys::Up
# define	PL1_DOWN		gdl::Keys::Down
# define	PL1_LEFT		gdl::Keys::Left
# define	PL1_RIGHT		gdl::Keys::Right
# define	PL1_BOMB		gdl::Keys::RControl
# define	PL1_ACTION		gdl::Keys::RAlt

# define	PL2_UP			gdl::Keys::Z
# define	PL2_DOWN		gdl::Keys::S
# define	PL2_LEFT		gdl::Keys::Q
# define	PL2_RIGHT		gdl::Keys::D
# define	PL2_BOMB		gdl::Keys::LControl
# define	PL2_ACTION		gdl::Keys::LAlt

// bomb related
# define	FUSE_LENGTH		3
# define	EXPLOSION_ADDED_SIZE	TILE_SCALE * 0.75f
# define	EXPLOSION_LIFESPAN	0.25f

// bonus related
#define		BONUS_SPAWN_RATE	40

// camera related
# define	WINDOW_WIDTH		1280
# define	WINDOW_HEIGHT		1024
# define	WINDOW_NAME		"Inglorious Blasters"
# define	CAMERA_HDIST		-1500.0f
# define	CAMERA_VDIST		1900.0f
# define	IMAGE_RATIO		16/9

// map related
# define	MIN_RAND_CRATES		10
# define	MAX_RAND_CRATES		40
# define	WALL_C			'X'
# define	CRATE_C			'O'
# define	PLAYER_1_C		'A'
# define	PLAYER_2_C		'B'
# define	EXIT_C			'E'
# define	RESUME_C		'L'
# define	OPTION_C		'P'
# define	MAP1_C			'1'
# define	MAP2_C			'2'
# define	MAP3_C			'3'
# define	MAP4_C			'4'
# define	MAP_RANDOM_C		'R'
# define	FX_C			'F'
# define	MUSIC_C			'M'
# define	RETOUR_C		'T'

// AObject types
# define	WALL_TYPE		"wall"
# define	CRATE_TYPE		"crate"
# define	BOMBER_TYPE		"bomber"
# define	BOMB_TYPE		"bomb"
# define	BONUS_TYPE		"bonus"

//
// assets
//

# define	ASSETS_DIR		std::string("assets/")
# define	TEX_DIR			ASSETS_DIR + "textures/"
# define	MESH_DIR		ASSETS_DIR + "meshes/"
# define	MAP_DIR			ASSETS_DIR + "maps/"

// textures
# define	WALL_TEXTURE		TEX_DIR + "wall.png"
# define	CRATE_TEXTURE		TEX_DIR + "crate.png"
# define	FLOOR_TEXTURE		TEX_DIR + "floor.jpg"
# define	BOMBS_TEXTURE		TEX_DIR + "bombs.png"
# define	SPEED_TEXTURE		TEX_DIR + "speed.png"
# define	RANGE_TEXTURE		TEX_DIR + "range.png"
# define	LASER_TEXTURE		TEX_DIR + "explosion.jpg"
# define	INTRO_BG_TEXTURE	TEX_DIR + ""
# define	GAME1P_TEXTURE		TEX_DIR + "game1p.png"
# define	GAME2P_TEXTURE		TEX_DIR + "game2p.png"
# define	OPTIONS_TEXTURE		TEX_DIR + "option.png"
# define	RESUME_TEXTURE		TEX_DIR + "load.png"
# define	CREDITS_TEXTURE		TEX_DIR + "crate.png"
# define 	QUIT_TEXTURE		TEX_DIR + "exit.jpg"
# define	MAP1_TEXTURE		TEX_DIR + "1.png"
# define	MAP2_TEXTURE		TEX_DIR + "2.png"
# define 	MAP3_TEXTURE		TEX_DIR + "3.png"
# define 	MAP4_TEXTURE		TEX_DIR + "4.png"
# define	MAPRANDOM_TEXTURE	TEX_DIR + "random.png"
# define	MUSIC_TEXTURE		TEX_DIR + "music.png"
# define	FX_TEXTURE		TEX_DIR + "fx.png"
# define	RETOUR_TEXTURE		TEX_DIR + "retour.jpg"

// models
# define	BOMB_MESH		MESH_DIR + "bomb.fbx"
# define	BOMBER_MESH		MESH_DIR + "marvin.fbx"

// maps
# define	MAP1			"crown.bmap"
# define	MAP2			"timer.bmap"
# define	MAP3			"strip.bmap"
# define	MAP4			"epi.bmap"
# define	MAP_MENU		"map_menu.bmap"
# define	MAP_SELECT		"map_player.bmap"
# define	MAP_OPT			"map_option.bmap"

// highscore
# define	HIGHSCORE_FILE		ASSETS_DIR + ".highscores"

// music
# define	MUSIC_BACKGROUND	"sounds/music.mp3"
