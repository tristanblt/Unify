##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for
##

NAME	=	../lib_arcade_ncurses.so

SRCPATH	=	src/
SRCS_FILES=	Graphical/Rectangle.cpp							\
			../../../core/src/ArcadeCore/CoreException.cpp	\
			Graphical/Window.cpp							\
			Graphical/Circle.cpp							\
			Graphical/Text.cpp								\
			Graphical/Sprite.cpp							\
			Graphical/Bitcrush.cpp							\
			Audio/Audio.cpp									\
			nCursesLibrary.cpp								\
			Entry.cpp										\
			PngFile.cpp										\
			NCursesException.cpp							\

SRC	=	$(addprefix $(SRCPATH), $(SRCS_FILES))

OBJ			= 	$(SRC:%.cpp=%.o)

CXXFLAGS	=	-W -Wall -Wextra -Wshadow	\
			-I../../	-std=c++17 -fpic

LDFLAGS		= -lpng -lpthread

UNAME_S	= $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CXXFLAGS +=	-DARCADE_LINUX
    LDFLAGS += -lncursesw
else
	CXXFLAGS += -DARCADE_MAC
    LDFLAGS += -lncurses
endif

CXX		=	g++

RM		=	rm -f

$(NAME):$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS) -shared

all:	$(NAME)

clean:
		$(RM) $(OBJ) *.gc*

fclean: clean
		$(RM) $(NAME)

re	:	fclean all

tests_run:

.PHONY:	clean fclean re tests_run
