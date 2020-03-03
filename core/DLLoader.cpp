/*
** EPITECH PROJECT, 2020
** core
** File description:
** DLLoader template class
*/

#include <dlfcn.h>

template <typename T>
class DLLoader {
    public:
        DLLoader(const std::string &path) { _handler = dlopen(path.c_str(), RTLD_LAZY); }
        ~DLLoader() { dlclose(_handler); }

        T *getInstance() {
            T *(*tempEntryPoint)(void) = reinterpret_cast<T*(*)()>(dlsym(_handler, "entryPoint"));
            return ((*tempEntryPoint)());
        };
    private:
        void *_handler;
};

