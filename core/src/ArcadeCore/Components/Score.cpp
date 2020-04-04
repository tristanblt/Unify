/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Score
*/

#include "core/include/ArcadeCore/Components/Score.hpp"

Score::Score(ScoreManager *sm): _sm(sm)
{

}

Score::~Score()
{

}

void Score::start(IBuilder *b)
{
    b->rectInit("UnifyScoreBackground");
    b->rectSetColor("UnifyScoreBackground", b->hexToColor(0x212121FF));

    b->textInit("UnifyScoreLogoName");
    b->textSetText("UnifyScoreLogoName", "Unify");
    b->textSetColor("UnifyScoreLogoName", b->hexToColor(0xFFFFFFFF));
    b->textSetFont("UnifyScoreLogoName", "UnifyBoldFont");

}

void Score::update(IBuilder *b)
{
    b->rectSetPosition("UnifyScoreBackground", {0, 0});
    b->rectSetSize("UnifyScoreBackground", {VW(100), VH(100)});
    b->rectDraw("UnifyScoreBackground");

    b->textSetPosition("UnifyScoreLogoName", {VW(50) - 5 * VH(2), VH(6.5)});
    b->textSetFontSize("UnifyScoreLogoName", (int)VH(5));
    b->textDraw("UnifyScoreLogoName");
}
