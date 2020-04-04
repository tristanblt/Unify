##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for
##

NAME	=	../arcade

SRCPATH	=	src/

SRCS_FILES=	main.cpp													\
			ArcadeCore/CoreException.cpp								\
			DLLoader.cpp												\
			ArcadeCore/ArcadeCore.cpp									\
			ArcadeCore/FileManager.cpp									\
			ArcadeCore/Components/Layout.cpp							\
			ArcadeCore/Components/Score.cpp								\
			ArcadeCore/Components/Menu.cpp								\
			ArcadeCore/Builder/BasicBuilder.cpp							\
			ArcadeCore/Builder/DrawBuilder.cpp							\
			ArcadeCore/Builder/CollideBuilder.cpp						\
			ArcadeCore/Builder/AudioBuilder.cpp							\
			ArcadeCore/Builder/UIBuilder.cpp							\
			ArcadeCore/Builder/UIButtonsBuilder.cpp						\
			ArcadeCore/Builder/UISliderBuilder.cpp						\
			ArcadeCore/Builder/UISelectorBuilder.cpp					\

SRC	=	$(addprefix $(SRCPATH), $(SRCS_FILES))

OBJ			= 	$(SRC:%.cpp=%.o)

CXXFLAGS	=	-W -Wall -Wextra -Wshadow	\
			-I../	-std=c++17

LDFLAGS		=	-ldl -lpthread

CXX		=	g++

RM		=	rm -f

$(NAME):$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)
all:	$(NAME)

clean:
		$(RM) $(OBJ) *.gc*

fclean: clean
		$(RM) $(NAME)

re	:	fclean all

tests_run:

.PHONY:	clean fclean re tests_run
