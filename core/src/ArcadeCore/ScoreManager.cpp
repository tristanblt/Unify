/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ScoreManager
*/

#include "core/include/ArcadeCore/ScoreManager.hpp"

ScoreManager::ScoreManager(FileManager fm)
{
    std::stringstream line;
    std::string score;
    std::string name;
    std::string game;

    for (size_t i = 0; i < fm._file.size(); i++) {
        line = std::stringstream(fm._file[i]);
        line >> name;
        while (line >> game) {
            if (!(line >> score))
                throw FileException("Database is not well formated, missing score after game");
            _profiles[name][game] = std::stoi(score);
        }
    }
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::saveScores()
{
    std::ofstream db;
    std::string table;

    db.open("assets/files/profiles.config");
    if (!db.is_open())
        throw FileException("Could not open database file 'profiles.config'");
    for_each(_profiles.begin(), _profiles.end(), [this, &db, &table](std::pair<std::string, std::map<std::string, int>> player) {
        table.append(player.first);
        for_each(player.second.begin() ,player.second.end(), [this, &db, &table](std::pair<std::string, int> game) {
            table.append(" " + game.first + " " + std::to_string(game.second));
        });
        table.append("\n");
        db << table;
        table.clear();
    });
    db.close();
}

std::vector<std::pair<std::string, int>> ScoreManager::getBestScores(const std::string &game)
{
    std::vector<std::pair<std::string, int>> board;
    std::vector<std::string> found;
    std::string tmpName;
    int tmpScore = -1;

    for (int i = 0; i < 5; i++) {
        for_each(_profiles.begin(), _profiles.end(), [&game, &board, &tmpName, &tmpScore, &found](std::pair<std::string, std::map<std::string, int>> player) {
            if (player.second.find(game) != player.second.end() && ((player.second[game] >= tmpScore && std::find(found.begin(), found.end(), player.first) == found.end()))) {
                tmpName = player.first;
                tmpScore = player.second[game];
            }
        });
        if (tmpScore != -1) {
            board.push_back(std::pair<std::string, int>(tmpName, tmpScore));
            found.push_back(tmpName);
            tmpName.clear();
            tmpScore = -1;
        }
    }
    return (board);
}