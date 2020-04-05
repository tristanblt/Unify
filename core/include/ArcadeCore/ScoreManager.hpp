/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ScoreManager
*/

#ifndef SCOREMANAGER_HPP_
#define SCOREMANAGER_HPP_

#include "core/include/ArcadeCore/FileManager.hpp"
#include <fstream>
#include <map>

class ScoreManager {
    public:
        ScoreManager(FileManager fm);
        ~ScoreManager();

        void saveScores();
        std::vector<std::pair<std::string, int>> getBestScores(const std::string &game);

        std::map<std::string, std::map<std::string, int>> _profiles;
    protected:
    private:

};

#endif /* !SCOREMANAGER_HPP_ */
