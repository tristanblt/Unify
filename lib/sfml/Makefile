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
			SFMLLibrary.cpp							\
			Entry.cpp								\

SRC	=	$(addprefix $(SRCPATH), $(SRCS_FILES))

OBJ			= 	$(SRC:%.cpp=%.o)

CXXFLAGS	=	-W -Wall -Wextra -Wshadow	\
			-I../../	-std=c++11 -fpic

LDFLAGS		= -lsfml-system -lsfml-graphics -lsfml-window -ldl

CXX		=	g++

RM		=	rm -f

$(NAME):$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS) -shared

all:	$(NAME)

clean:
		$(RM) $(OBJ) $(OBJ_FLOGIC) *.gc*

fclean: clean
		$(RM) $(NAME)

re	:	fclean all

tests_run:

.PHONY:	clean fclean re tests_run
