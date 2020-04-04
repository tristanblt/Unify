/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Score
*/

#include "core/include/ArcadeCore/Components/Score.hpp"

Score::Score(ScoreManager *sm):
_sm(sm), _nickname("AAA"), _selectOffset(0)
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

    b->radiusRectInit("UnifyNicknameEntry");
    b->radiusRectSetColor("UnifyNicknameEntry", b->hexToColor(0x1A1A1AFF));

    b->radiusRectInit("UnifyNicknameSelector");
    b->radiusRectSetColor("UnifyNicknameSelector", b->hexToColor(0x1B79E6FF));

    b->radiusRectInit("UnifyNicknameSelector2");
    b->radiusRectSetColor("UnifyNicknameSelector2", b->hexToColor(0x1A1A1AFF));

    b->textInit("UnifyNicknameLetter");
    b->textSetColor("UnifyNicknameLetter", b->hexToColor(0xFFFFFFFF));
    b->textSetFont("UnifyNicknameLetter", "UnifyBoldFont");
}

void Score::drawSelector(IBuilder *b)
{
    b->radiusRectSetRadius("UnifyNicknameEntry", VH(1));
    b->radiusRectSetPosition("UnifyNicknameEntry", {VW(50), VH(50)});
    b->radiusRectSetSize("UnifyNicknameEntry", {VW(12), VW(4)});
    b->radiusRectDraw("UnifyNicknameEntry");

    b->radiusRectSetRadius("UnifyNicknameSelector", VH(1));
    b->radiusRectSetPosition("UnifyNicknameSelector", {VW(50) + VW(4 * _selectOffset), VH(50)});
    b->radiusRectSetSize("UnifyNicknameSelector", {VW(4), VW(4)});
    b->radiusRectDraw("UnifyNicknameSelector");

    b->radiusRectSetRadius("UnifyNicknameSelector2", VH(1));
    b->radiusRectSetPosition("UnifyNicknameSelector2", {VW(50.21875) + VW(4 * _selectOffset), VH(50) + VW(0.21875)});
    b->radiusRectSetSize("UnifyNicknameSelector2", {VW(3.563), VW(3.563)});
    b->radiusRectDraw("UnifyNicknameSelector2");

    b->textSetFontSize("UnifyNicknameLetter", (int)VW(2));
    b->textSetText("UnifyNicknameLetter", std::string(1, _nickname[0]));
    b->textSetPosition("UnifyNicknameLetter", {VW(50.875), VH(50) + VW(0.75)});
    b->textDraw("UnifyNicknameLetter");
    b->textSetText("UnifyNicknameLetter", std::string(1, _nickname[1]));
    b->textSetPosition("UnifyNicknameLetter", {VW(54.875), VH(50) + VW(0.75)});
    b->textDraw("UnifyNicknameLetter");
    b->textSetText("UnifyNicknameLetter", std::string(1, _nickname[2]));
    b->textSetPosition("UnifyNicknameLetter", {VW(58.875), VH(50) + VW(0.75)});
    b->textDraw("UnifyNicknameLetter");
}

void Score::drawBackground(IBuilder *b)
{
    b->rectSetPosition("UnifyScoreBackground", {0, 0});
    b->rectSetSize("UnifyScoreBackground", {VW(100), VH(100)});
    b->rectDraw("UnifyScoreBackground");

    b->textSetPosition("UnifyScoreLogoName", {VW(50) - 5 * VH(2), VH(6.5)});
    b->textSetFontSize("UnifyScoreLogoName", (int)VH(5));
    b->textDraw("UnifyScoreLogoName");
}

void Score::manageInputs(IBuilder *b)
{
    if (b->getEvents().keyboardState[Key::UP] == InputState::RELEASED) {
        if (_nickname[_selectOffset] == 'A')
        _nickname[_selectOffset] = 'Z';
        else
        _nickname[_selectOffset]--;
    } else if (b->getEvents().keyboardState[Key::DOWN] == InputState::RELEASED) {
        if (_nickname[_selectOffset] == 'Z')
        _nickname[_selectOffset] = 'A';
        else
        _nickname[_selectOffset]++;
    }
    if (b->getEvents().keyboardState[Key::LEFT] == InputState::RELEASED && _selectOffset != 0)
        _selectOffset--;
    else if (b->getEvents().keyboardState[Key::RIGHT] == InputState::RELEASED && _selectOffset != 2)
        _selectOffset++;
}

void Score::update(IBuilder *b)
{
    manageInputs(b);
    drawBackground(b);
    drawSelector(b);
}
