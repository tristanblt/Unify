##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## tests
##

NAME_TESTS	=	unit_tests

SRCS	=	test_tmp.cpp		\


RM		=	rm -f

CXXFLAGS	= -std=c++11 -W -Wall -Wextra -fprofile-arcs -ftest-coverage

OBJS	=	$(SRCS:.cpp=.o)

LDFLAGS	=	--coverage -lcriterion

DEL =   $(SRCS:%.cpp=%.gcno) \
        $(SRCS:%.cpp=%.gcda) \

CC	=	c++

clean:
	$(RM) $(OBJS)
	$(RM) $(DEL)

fclean: clean
	$(RM) $(NAME_TESTS)

tests_run: fclean $(OBJS)
	$(CC) -o $(NAME_TESTS) $(OBJS) $(LDFLAGS)
	./unit_tests
	gcovr -e tests

.PHONY: clean fclean tests_run
