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

    b->textInit("UnifyScoreText");
    b->textSetColor("UnifyScoreText", b->hexToColor(0xFFFFFFFF));
    b->textSetFont("UnifyScoreText", "UnifyLightFont");

    b->textInit("UnifyScoreCountText");
    b->textSetColor("UnifyScoreCountText", b->hexToColor(0xFFFFFFFF));
    b->textSetFont("UnifyScoreCountText", "UnifyBoldFont");

    b->textInit("UnifyBestScoreText");
    b->textSetColor("UnifyBestScoreText", b->hexToColor(0xFFFFFFFF));
    b->textSetFont("UnifyBestScoreText", "UnifyBoldFont");

    b->basicButtonInit("UnifySaveScore");
    b->basicButtonSetBackgroundColors("UnifySaveScore", b->hexToColor(0x505050FF), b->hexToColor(0x505050FF), b->hexToColor(0x505050FF));
    b->basicButtonSetTextColors("UnifySaveScore", b->hexToColor(0x1B79E6FF), b->hexToColor(0xDEDEDEFF), b->hexToColor(0xFFFFFFFF));
    b->basicButtonSetFont("UnifySaveScore", "UnifyBoldFont");
    b->basicButtonSetText("UnifySaveScore", "Save score");

    b->basicButtonInit("UnifyScoreBackToMenu");
    b->basicButtonSetBackgroundColors("UnifyScoreBackToMenu", b->hexToColor(0x505050FF), b->hexToColor(0x505050FF), b->hexToColor(0x505050FF));
    b->basicButtonSetTextColors("UnifyScoreBackToMenu", b->hexToColor(0x1B79E6FF), b->hexToColor(0xDEDEDEFF), b->hexToColor(0xFFFFFFFF));
    b->basicButtonSetFont("UnifyScoreBackToMenu", "UnifyBoldFont");
    b->basicButtonSetText("UnifyScoreBackToMenu", "Back to menu");
}

void Score::drawSelector(IBuilder *b)
{
    Vector2 offset = {VW(44), VH(45)};

    b->radiusRectSetRadius("UnifyNicknameEntry", VH(1));
    b->radiusRectSetPosition("UnifyNicknameEntry", offset);
    b->radiusRectSetSize("UnifyNicknameEntry", {VW(12), VW(4)});
    b->radiusRectDraw("UnifyNicknameEntry");

    b->radiusRectSetRadius("UnifyNicknameSelector", VH(1));
    b->radiusRectSetPosition("UnifyNicknameSelector", {offset.x + VW(4 * _selectOffset), offset.y});
    b->radiusRectSetSize("UnifyNicknameSelector", {VW(4), VW(4)});
    b->radiusRectDraw("UnifyNicknameSelector");

    b->radiusRectSetRadius("UnifyNicknameSelector2", VH(1));
    b->radiusRectSetPosition("UnifyNicknameSelector2", {offset.x + VW(0.21875) + VW(4 * _selectOffset), offset.y + VW(0.21875)});
    b->radiusRectSetSize("UnifyNicknameSelector2", {VW(3.563), VW(3.563)});
    b->radiusRectDraw("UnifyNicknameSelector2");

    b->textSetFontSize("UnifyNicknameLetter", (int)VW(2));
    b->textSetText("UnifyNicknameLetter", std::string(1, _nickname[0]));
    b->textSetPosition("UnifyNicknameLetter", {offset.x + VW(0.875), offset.y + VW(0.75)});
    b->textDraw("UnifyNicknameLetter");
    b->textSetText("UnifyNicknameLetter", std::string(1, _nickname[1]));
    b->textSetPosition("UnifyNicknameLetter", {offset.x + VW(4.875), offset.y + VW(0.75)});
    b->textDraw("UnifyNicknameLetter");
    b->textSetText("UnifyNicknameLetter", std::string(1, _nickname[2]));
    b->textSetPosition("UnifyNicknameLetter", {offset.x + VW(8.875), offset.y + VW(0.75)});
    b->textDraw("UnifyNicknameLetter");
}

void Score::drawBackground(IBuilder *b)
{
    b->rectSetPosition("UnifyScoreBackground", {0, 0});
    b->rectSetSize("UnifyScoreBackground", {VW(100), VH(100)});
    b->rectDraw("UnifyScoreBackground");

    b->textSetPosition("UnifyScoreLogoName", {VW(50) - 5 * VH(1.5), VH(6.5)});
    b->textSetFontSize("UnifyScoreLogoName", (int)VH(5));
    b->textDraw("UnifyScoreLogoName");

    b->textSetText("UnifyScoreText", "Your score :");
    b->textSetPosition("UnifyScoreText", {VW(45), VH(15)});
    b->textSetFontSize("UnifyScoreText", VH(3));
    b->textDraw("UnifyScoreText");

    b->textSetText("UnifyScoreText", "Your nickname :");
    b->textSetPosition("UnifyScoreText", {VW(43.4), VH(39)});
    b->textSetFontSize("UnifyScoreText", VH(3));
    b->textDraw("UnifyScoreText");
}

void Score::drawBestScores(IBuilder *b)
{
    int i = 0;
    b->textSetText("UnifyScoreCountText", "Leaderboard :");
    b->textSetPosition("UnifyScoreCountText", {VW(10), VH(27)});
    b->textSetFontSize("UnifyScoreCountText", VH(4));
    b->textDraw("UnifyScoreCountText");

    for_each(_bestScore.begin(), _bestScore.end(), [&b, &i](std::pair<std::string, int> elem) {
        b->textSetText("UnifyScoreText", elem.first);
        b->textSetPosition("UnifyScoreText", {VW(10), VH(35) + i * VH(5)});
        b->textSetFontSize("UnifyScoreText", VH(3));
        b->textDraw("UnifyScoreText");
        b->textSetText("UnifyScoreText", std::to_string(elem.second));
        b->textSetPosition("UnifyScoreText", {VW(26), VH(35) + i * VH(5)});
        b->textSetFontSize("UnifyScoreText", VH(3));
        b->textDraw("UnifyScoreText");
        i++;
    });
}

void Score::manageInputs(IBuilder *b)
{
    if (b->getEvents().keyboardState[Key::UP] == InputState::RELEASED || b->getEvents().joyConEvents.buttons1[JOY_X] == InputState::RELEASED) {
        if (_nickname[_selectOffset] == 'A')
        _nickname[_selectOffset] = 'Z';
        else
        _nickname[_selectOffset]--;
    } else if (b->getEvents().keyboardState[Key::DOWN] == InputState::RELEASED || b->getEvents().joyConEvents.buttons1[JOY_Y] == InputState::RELEASED) {
        if (_nickname[_selectOffset] == 'Z')
        _nickname[_selectOffset] = 'A';
        else
        _nickname[_selectOffset]++;
    }
    if ((b->getEvents().keyboardState[Key::LEFT] == InputState::RELEASED || b->getEvents().joyConEvents.buttons1[JOY_L1] == InputState::RELEASED) && _selectOffset != 0)
        _selectOffset--;
    else if ((b->getEvents().keyboardState[Key::RIGHT] == InputState::RELEASED || b->getEvents().joyConEvents.buttons1[JOY_R1] == InputState::RELEASED) && _selectOffset != 2)
        _selectOffset++;
}

void Score::update(IBuilder *b, int score, std::string gameName, CoreState &coreState)
{
    if (_bestScore.size() == 0) {
        std::replace(gameName.begin(), gameName.end(), ' ', '_');
        _bestScore = _sm->getBestScores(gameName);
    }
    manageInputs(b);
    drawBackground(b);
    drawSelector(b);
    drawBestScores(b);
    b->textSetText("UnifyScoreCountText", std::to_string(score));
    b->textSetPosition("UnifyScoreCountText", {VW(50) - VH(2) * std::to_string(score).size(), VH(25)});
    b->textSetFontSize("UnifyScoreCountText", VH(7));
    b->textDraw("UnifyScoreCountText");
    b->basicButtonSetDisplayBox("UnifySaveScore", {VW(43), VH(83), VW(14), VH(5)});
    b->basicButtonSetFontSize("UnifySaveScore", VH(2));
    b->basicButtonSetRadius("UnifySaveScore", VH(2.5));
    if (b->buttonDraw("UnifySaveScore")) {
        std::replace(gameName.begin(), gameName.end(), ' ', '_');
        if (_sm->_profiles[_nickname].find(gameName) == _sm->_profiles[_nickname].end() || _sm->_profiles[_nickname][gameName] <= score)
           _sm->_profiles[_nickname][gameName] = score;
        _sm->saveScores();
        coreState = CoreState::CORE_GAME;
    }
    b->basicButtonSetDisplayBox("UnifyScoreBackToMenu", {VW(43), VH(90), VW(14), VH(5)});
    b->basicButtonSetFontSize("UnifyScoreBackToMenu", VH(2));
    b->basicButtonSetRadius("UnifyScoreBackToMenu", VH(2.5));
    if (b->buttonDraw("UnifyScoreBackToMenu"))
        coreState = CoreState::CORE_MENU;
    if (coreState != CoreState::CORE_SCORE)
       _bestScore.clear();
}
