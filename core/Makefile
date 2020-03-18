##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for
##

NAME	=	../arcade

SRCPATH	=	src/
SRCS_FILES=	main.cpp											\
			ArcadeCore/ArcadeCore.cpp							\
			ArcadeCore/Components/Layout.cpp					\
			ArcadeCore/Components/Menu.cpp						\
			ArcadeCore/Builder/Builder.cpp						\
			ArcadeCore/Builder/UI/BasicButton.cpp				\
			ArcadeCore/Builder/UI/SpriteButton.cpp				\

SRC	=	$(addprefix $(SRCPATH), $(SRCS_FILES))

OBJ			= 	$(SRC:%.cpp=%.o)

CXXFLAGS	=	-W -Wall -Wextra -Wshadow	\
			-I../	-std=c++11

LDFLAGS		=	-ldl

CXX		=	g++

RM		=	rm -f

$(NAME):$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS)
all:	$(NAME)

clean:
		$(RM) $(OBJ) $(OBJ_FLOGIC) *.gc*

fclean: clean
		$(RM) $(NAME)

re	:	fclean all

tests_run:

.PHONY:	clean fclean re tests_run
