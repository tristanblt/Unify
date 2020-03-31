/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Score
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_

#include "core/include/ArcadeCore/Utils/Enums.hpp"
#include "core/include/ArcadeCore/Builder/IBuilder.hpp"

class Score {
    public:
        Score();
        ~Score();

        void update(IBuilder *builder);
        void start(IBuilder *builder);
    protected:
    private:
};

#endif /* !SCORE_HPP_ */
