/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** FileManager
*/

#include "core/include/ArcadeCore/FileManager.hpp"

FileManager::FileManager(const std::string &filepath)
{
    std::ifstream f(filepath);
    std::string buffer;
    std::string name;

    if (!f)
        throw FileException("Could not open file '"+std::string(filepath)+"'");
    while (std::getline(f, buffer))
        if(buffer.size() > 0)
            _file.push_back(buffer);
    f.close();
}

FileManager::~FileManager()
{
}