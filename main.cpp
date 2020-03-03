/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "dlfcn.h"
#include "lib/include/IDisplayLibrary.hpp"
#include "lib/include/IDisplayLibrary.hpp"

int main(int argc, char const *argv[])
{
    void *handler = dlopen("liba.so", RTLD_LAZY);
    IDisplayLibrary* (*entryFct) () = (IDisplayLibrary *(*)()) dlsym(handler, "entryPoint");
    IDisplayLibrary *entry = (IDisplayLibrary *)entryFct();

    entry->newWindow();
    return 0;
}
