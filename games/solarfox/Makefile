##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NAME	=	../lib_arcade_solarfox.so

SRCPATH	=	src/
SRCS_FILES=	Entry.cpp							\
			StartSolarfox.cpp					\
			Player.cpp							\
			Coin.cpp							\
			enemies/BasicEnemy.cpp				\
			shots/BasicShot.cpp					\
			components/GameInstance.cpp			\

SRC	=	$(addprefix $(SRCPATH), $(SRCS_FILES))

OBJ			= 	$(SRC:%.cpp=%.o)

CXXFLAGS	=	-W -Wall -Wextra -Wshadow	\
			-I../../	-std=c++11 -fpic

LDFLAGS		=

CXX		=	g++

RM		=	rm -f

$(NAME):$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS) -shared

all:	$(NAME)

clean:
		$(RM) $(OBJ) $(OBJ_FLOGIC) *.gc*

fclean: clean
		$(RM) $(NAME)

re	:	fclean all

tests_run:

.PHONY:	clean fclean re tests_run
