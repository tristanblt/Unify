/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "lib/include/ADisplayLibrary.hpp"
#include "lib/include/Graphical/IWindow.hpp"
#include "lib/include/Graphical/IRectangle.hpp"
#include "core/include/DLLoader.hpp"
#include "core/include/ArcadeCore/ArcadeCore.hpp"
#include <iostream>
#define EPITECH_EXIT_SUCCESS 0
#define EPITECH_EXIT_FAILURE 84

static const std::string USAGE = \
"USAGE:\n"\
"\t./arcade [path]\n"\
"\n\tpath: Path to the graphic library you want to launch your arcade with,"\
" it must be a shared object library (.so)";

int main(int argc, char const *argv[])
{
    ArcadeCore arcadeCore;
    ADisplayLibrary *lib;

    if (argc != 2) {
        std::cerr << USAGE << std::endl;
        return (EPITECH_EXIT_FAILURE);
    }
    try {
        lib = arcadeCore.importGraphicalLibs(std::string(argv[1]));
        if (lib == NULL) {
            std::cerr << "error: Could not open '"+std::string(argv[1])+"' graphical library." << std::endl;
            return (EPITECH_EXIT_FAILURE);
        }
        while (arcadeCore.launchCore(lib));
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (EPITECH_EXIT_FAILURE);
    }
    return (EPITECH_EXIT_SUCCESS);
}