##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for
##

NAME	=	arcade

SRCPATH	=	src/
SRCS_FILES=	main.cpp										\
			ArcadeMenu/ArcadeMenu.cpp						\
			../../lib/src/Graphical/ERectangle.cpp			\

SRC	=	$(addprefix $(SRCPATH), $(SRCS_FILES))

OBJ			= 	$(SRC:%.cpp=%.o)

CXXFLAGS	=	-W -Wall -Wextra -Wshadow	\
			-I../	-std=c++11

CXX		=	g++

RM		=	rm -f

$(NAME):$(OBJ)
		$(CXX) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
		$(RM) $(OBJ) $(OBJ_FLOGIC) *.gc*

fclean: clean
		$(RM) $(NAME)

re	:	fclean all

tests_run:

.PHONY:	clean fclean re tests_run
