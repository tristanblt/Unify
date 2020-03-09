/*
** EPITECH PROJECT, 2020
** core
** File description:
** DLLoader template class
*/

#include <dlfcn.h>
#include <string>
#include <iostream>

template <typename T>
class DLLoader {
    public:
        DLLoader(const char *path) { std::cout << path << std::endl; _handler = dlopen(path, RTLD_GLOBAL);std::cout << path << std::endl; }
        ~DLLoader() { dlclose(_handler); }

        T *getInstance() {
            T *(*tempEntryPoint)(void) = reinterpret_cast<T*(*)()>(dlsym(_handler, "entryPoint"));
            return (tempEntryPoint == nullptr ? nullptr : (*tempEntryPoint)());
        };
    private:
        void *_handler;
};

