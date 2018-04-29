##
## Makefile for bomberman in /home/steel_c//Code/Bomberman
##
## Made by christopher steel
## Login   <steel_c@epitech.net>
##
## Started on  Sat Apr 27 17:50:14 2013 christopher steel
## Last update Wed May 14 15:35:59 2014 Christopher Steel
##

NAME=		bomberman

DEBUG ?=	false

OBJDIR=		obj/
SRCDIR=		src/

VPATH=		$(SRCDIR)

GDLGLINC=	gdl/include
GDLGLLIB=	gdl/lib

SFMLDIR=	gdl/SFML-1.6/lib
SFMLLIB=	sfml-audio \
		sfml-graphics \
		sfml-network \
		sfml-system \
		sfml-window
SFMLLD=		-L $(SFMLDIR) $(addprefix -l, $(SFMLLIB))

INCLUDE=	-I inc/ -I $(GDLGLINC)

CXXFLAGS=	-W -Wall -Wextra -Werror

ifeq		($(DEBUG), true)
CXXFLAGS +=	-g3
endif

CXXFLAGS += 	$(INCLUDE)
CXXFLAGS += 	-pthread

LDFLAGS=	$(SFMLLD)
LDFLAGS +=	-L $(GDLGLLIB) -lgdl_gl -lGL -lGLU

LINKERFLAGS=	-Wl,--rpath=$(GDLGLLIB),--rpath=$(SFMLDIR)

CXXFLAGS +=	$(LINKERFLAGS)

SRC=		main.cpp \
			MyGame.cpp \
			Camera.cpp \
			Vector2.cpp \
			Vector3.cpp \
			ColorManager.cpp \
			ABomber.cpp \
			Bot.cpp \
			ABonus.cpp \
			Bomber.cpp \
			Bomb.cpp \
			Eventoids.cpp \
			ACuboid.cpp \
			ACube.cpp \
			TexturedCuboid.cpp \
			TexturedCube.cpp \
			Laseroid.cpp \
			Wall.cpp \
			Crate.cpp \
			Floor.cpp \
			Sign.cpp \
			MapLoader.cpp \
			HighScore.cpp \
			Options.cpp \
			Rectangle.cpp

OBJ=		$(addprefix $(OBJDIR), $(SRC:.cpp=.o))

$(OBJDIR)%.o:	%.cpp
		$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME):	$(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
