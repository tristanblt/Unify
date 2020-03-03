##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

all:
	make -C core/
	make -C lib/
	#make -C games/

re:
	make re -C core/
	make re -C lib/
	#make re -C games/

clean:
	make clean -C core/
	make clean -C lib/
	#make clean -C games/

fclean:
	make fclean -C core/
	make fclean -C lib/
	#make fclean -C games/