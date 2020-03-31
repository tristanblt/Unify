/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** GameInstance
*/

#ifndef GAMEINSTANCE_HPP_
#define GAMEINSTANCE_HPP_
#include "games/solarfox/include/IEntity.hpp"
#include "games/solarfox/include/enemies/BasicEnemy.hpp"
#include "games/solarfox/include/components/IComponent.hpp"
#include "games/solarfox/include/Player.hpp"
#include "games/solarfox/include/Coin.hpp"
#include <algorithm>

class GameInstance: public IComponent {
    public:
        GameInstance(int level, int score, IBuilder *b);
        ~GameInstance();

        SFGameState occurs(IBuilder *b);
        void addEntity(IEntity *e);
        Player *getPlayer();
        void incrementScore();
        int getLevel() const;
        int getScore() const;
    protected:
        void setMap(IBuilder *b);
        void setEnemies(IBuilder *b);
        void drawBackground(IBuilder *b, bool part);

    private:
        int _level;
        int _score;
        int _nbCoins;
        std::string _backgroundIdx;
        std::vector<IEntity *> _entities;
        Player *_player;
};

#endif /* !GAMEINSTANCE_HPP_ */
