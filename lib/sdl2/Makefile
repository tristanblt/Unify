##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for
##

NAME	=	../lib_arcade_sdl2.so

SRCPATH	=	src/
SRCS_FILES=	SDL2Library.cpp							\
			Entry.cpp								\
			Graphical/Window.cpp					\
			Graphical/Rectangle.cpp					\
			Graphical/Circle.cpp					\
			Graphical/Text.cpp						\
			Graphical/Sprite.cpp					\
			Audio/Audio.cpp							\
			SDL2Exceptions.cpp						\

SRC	=	$(addprefix $(SRCPATH), $(SRCS_FILES))

OBJ			= 	$(SRC:%.cpp=%.o)

CXXFLAGS	=	-W -Wall -Wextra -Wshadow	\
			-I../../	-std=c++17 -fpic

LDFLAGS		= -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

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
