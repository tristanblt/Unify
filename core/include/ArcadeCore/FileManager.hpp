/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** FileManager
*/

#ifndef FILEMANAGER_HPP_
#define FILEMANAGER_HPP_


#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include "core/include/ArcadeCore/CoreException.hpp"

class FileManager {
    public:
        FileManager(const std::string &);
        ~FileManager();

        std::vector<std::string> _file;
    private:
};

#endif /* !FILEMANAGER_HPP_ */
