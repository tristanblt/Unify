##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for
##

NAME	=	../lib_arcade_sfml.so

SRCPATH	=	src/
SRCS_FILES=	Graphical/Rectangle.cpp					\
			Graphical/Window.cpp					\
			Graphical/Circle.cpp					\
			Graphical/Text.cpp						\
			Graphical/Sprite.cpp					\
			Audio/Audio.cpp							\
			SFMLLibrary.cpp							\
			Entry.cpp								\
			SfmlExceptions.cpp						\

SRC	=	$(addprefix $(SRCPATH), $(SRCS_FILES))

OBJ			= 	$(SRC:%.cpp=%.o)

CXXFLAGS	=	-W -Wall -Wextra -Wshadow	\
			-I../../	-std=c++17 -fpic

LDFLAGS		= -lsfml-system -lsfml-graphics -lsfml-audio -lsfml-window

UNAME_S	= $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CXXFLAGS +=	-DARCADE_LINUX
else
	CXXFLAGS += -DARCADE_MAC
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
