/*
** EPITECH PROJECT, 2020
** core
** File description:
** DLLoader template class
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <dlfcn.h>
#include <string>
#include <iostream>
#include "core/include/ArcadeCore/CoreException.hpp"

template <typename T>
class DLLoader {
    public:
        DLLoader(const char *path);
        ~DLLoader();

        T *getInstance();
    private:
        void *_handler;
        std::string _path;
};

#endif