/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DLLoader
*/

#include "core/include/DLLoader.hpp"
#include "games/include/Start.hpp"
#include "lib/include/ADisplayLibrary.hpp"

template <typename T>
DLLoader<T>::DLLoader(const char *path)
{
    _path = std::string(path);
    _handler = dlopen(path, RTLD_LAZY);
    if (!_handler)
        throw DLLoaderException("could not open '"+std::string(path)+"' dynamic library.");
}

template <typename T>
DLLoader<T>::~DLLoader()
{
    dlclose(_handler);
}

template <typename T>
T *DLLoader<T>::getInstance()
{
    T *(*tempEntryPoint)(void) = reinterpret_cast<T*(*)()>(dlsym(_handler, "entryPoint"));

    if (tempEntryPoint == nullptr)
        throw DLLoaderException("could not find the entry point of '"+_path+"' library.");
    return ((*tempEntryPoint)());
}

template class DLLoader<Start>;
template class DLLoader<ADisplayLibrary>;