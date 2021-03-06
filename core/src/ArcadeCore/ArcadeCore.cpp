/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ArcadeCore
*/

#include "core/include/ArcadeCore/ArcadeCore.hpp"
#include "core/include/DLLoader.hpp"
#include "core/include/ArcadeCore/CoreException.hpp"

ArcadeCore::ArcadeCore():
_sm(ScoreManager(FileManager("assets/files/profiles.config"))), _score(Score(&_sm))
{
    _coreState = CoreState::CORE_MENU;
    _gameState.score = 0;
    _gameState.state = State::STATE_NONE;
    _libCtrl = LibraryControl::LIB_CTRL_NONE;
}

ArcadeCore::~ArcadeCore()
{
}

void ArcadeCore::loadCoreAssets(IBuilder *builder)
{
    builder->loadAsset("assets/fonts/Montserrat-Light.ttf", "UnifyLightFont", AssetType::FONT);
    builder->loadAsset("assets/fonts/Montserrat-Regular.ttf", "UnifyRegularFont", AssetType::FONT);
    builder->loadAsset("assets/fonts/Montserrat-Bold.ttf", "UnifyBoldFont", AssetType::FONT);
    builder->loadAsset("assets/imgs/flaticons/icons.png", "UnifyIcons", AssetType::SPRITE);
    builder->loadAsset("assets/imgs/logo.png", "UnifyLogo", AssetType::SPRITE);
    builder->loadAsset("assets/fonts/UnifyFontImg.png", "UnifyFontImg", AssetType::SPRITE);
    builder->loadAsset("assets/imgs/wii-cursors.png", "UnifyJoyConsCursors", AssetType::SPRITE);
    builder->loadAsset("assets/audio/Klick.wav", "UnifyClickSound", AssetType::AUDIO);
    builder->loadAsset("assets/audio/RunGame.wav", "UnifyRunGameSound", AssetType::AUDIO);
    builder->loadAsset("assets/audio/Border.wav", "UnifyBorderSound", AssetType::AUDIO);
}

ADisplayLibrary *ArcadeCore::importGraphicalLibs(const std::string &firstLib)
{
    FileManager fm("assets/files/displaylibs.config");
    ADisplayLibrary *ret = NULL;

    for (size_t i = 0; i < fm._file.size(); i++) {
        DLLoader<ADisplayLibrary> *loader = new DLLoader<ADisplayLibrary>(fm._file[i].c_str());
        ADisplayLibrary *tmp = loader->getInstance();
        if (fm._file[i] == firstLib) {
            ret = tmp;
            _currentLib = i;
        }
        _libs.push_back(tmp);
    }
    return (ret);
}

void ArcadeCore::switchGraphicalLibrary(Builder *b, int i, Start *&game)
{
    if (static_cast<size_t>(i) > _libs.size() - 1)
        i = 0;
    if (i < 0)
        i = _libs.size() - 1;
    b->reloadLibrary(_libs[i]);
    b->unlockUnifyGameObjects();
    loadCoreAssets(b);
    _menu.start(b);
    _layout.start(b);
    _score.start(b);
    if (game)
        game->start(b);
    b->lockUnifyGameObjects();
    _currentLib = i;
}

void ArcadeCore::triggerSwitchGraphicalLibrary(Builder *b, Start *&game)
{
    if (b->getEvents().keyboardState[Key::F2] == InputState::RELEASED || _libCtrl == LibraryControl::LIB_CTRL_NEXT) {
        switchGraphicalLibrary(b, _currentLib + 1, game);
        b->getEvents().keyboardState[Key::F2] = InputState::NONE;
        _libCtrl = LibraryControl::LIB_CTRL_NONE;
    }
    if (b->getEvents().keyboardState[Key::F1] == InputState::RELEASED || _libCtrl == LibraryControl::LIB_CTRL_PREV) {
        switchGraphicalLibrary(b, _currentLib - 1, game);
        b->getEvents().keyboardState[Key::F1] = InputState::NONE;
        _libCtrl = LibraryControl::LIB_CTRL_NONE;
    }
}

void ArcadeCore::updateJoyConCursors(IBuilder *b)
{
    if (b->getEvents().joyConEvents.cursorPos.x == -1 && b->getEvents().joyConEvents.cursorPos.y == -1)
        return;
    b->spriteSetPosition("UnifyJoyConCursor", {b->getEvents().joyConEvents.cursorPos.x - 15,
    b->getEvents().joyConEvents.cursorPos.y});
    b->spriteDraw("UnifyJoyConCursor");
}

void ArcadeCore::startLaunchCore(Builder *b)
{
    loadCoreAssets(b);
    _menu.start(b);
    _layout.start(b);
    _score.start(b);
    b->spriteInit("UnifyJoyConCursor");
    b->spriteSetSprite("UnifyJoyConCursor", "UnifyJoyConsCursors");
    b->spriteSetSize("UnifyJoyConCursor", {VW(5), VW(4.2f)}, {481, 3, 44, 30});
    b->lockUnifyGameObjects();
}

void ArcadeCore::manageMenuAndGame(Builder *b, DLLoader<Start> *&gameLib, Start *&game)
{
    static DLLoader<Start> *currentGame = NULL;

    if (_coreState == CoreState::CORE_MENU) {
        if ((gameLib = _menu.update(b, _libCtrl)) != NULL) {
            if (gameLib != currentGame) {
                game = gameLib->getInstance();
                game->start(b);
            }
            currentGame = gameLib;
            _coreState = CoreState::CORE_GAME;
        }
        if (b->getEvents().keyboardState[Key::ESCAPE] == InputState::RELEASED)
            b->windowClose();
        updateJoyConCursors(b);
    }
    else if (_coreState == CoreState::CORE_SCORE) {
        _score.update(b, _gameState.score, game->getName(), _coreState);
        updateJoyConCursors(b);
    }
    else {
        if (_coreState != CoreState::CORE_PAUSE) {
            if (b->getEvents().keyboardState[Key::F3] == InputState::RELEASED) {
                game->restart(b);
            }
            _gameState = game->update(b);
        }
        else
            updateJoyConCursors(b);
        _layout.update(b, _coreState, game->getName(), _libCtrl);
        if (_gameState.state == State::STATE_SCORE) {
            _coreState = CoreState::CORE_SCORE;
            _gameState.state = State::STATE_NONE;
        }
    }
}

bool ArcadeCore::launchCore(ADisplayLibrary *library)
{
    Start *game = NULL;
    DLLoader<Start> *gameLib;
    Builder builder(library);

    startLaunchCore(&builder);
    while (builder.windowIsOpen()) {
        builder.updateEvents();
        builder.windowClear();
        manageMenuAndGame(&builder, gameLib, game);
        builder.windowDisplay();
        triggerSwitchGraphicalLibrary(&builder, game);
    }
    _sm.saveScores();
    return (_menu.getInterruptType());
}