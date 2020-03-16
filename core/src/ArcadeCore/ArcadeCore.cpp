/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ArcadeCore
*/

#include "core/include/ArcadeCore/ArcadeCore.hpp"
#include "core/include/DLLoader.hpp"

ArcadeCore::ArcadeCore()
{
    _coreState = CoreState::CORE_MENU;
}

ArcadeCore::~ArcadeCore()
{
}

void ArcadeCore::loadCoreAssets(IBuilder *builder)
{
    builder->loadAsset("assets/fonts/Montserrat-Light.otf", "UnifyLightFont", AssetType::FONT);
    builder->loadAsset("assets/fonts/Montserrat-Regular.otf", "UnifyRegularFont", AssetType::FONT);
    builder->loadAsset("assets/fonts/Montserrat-Bold.otf", "UnifyBoldFont", AssetType::FONT);
    builder->loadAsset("assets/imgs/flaticons/icons.png", "UnifyIcons", AssetType::SPRITE);
    builder->loadAsset("assets/imgs/logo.png", "UnifyLogo", AssetType::SPRITE);
}

DisplayLibrary *ArcadeCore::importGraphicalLibs(const std::string &firstLib)
{
    std::ifstream f("assets/files/displaylibs.config");
    std::string buffer;
    std::vector<std::string> file;
    DisplayLibrary *ret = NULL;

    if (!f)
        throw std::invalid_argument("Could not open file displaylibs.config");
    while (std::getline(f, buffer))
        if(buffer.size() > 0)
            file.push_back(buffer);
    f.close();
    for (size_t i = 0; i < file.size(); i++) {
        DLLoader<DisplayLibrary> *loader = new DLLoader<DisplayLibrary>(file[i].c_str());
        DisplayLibrary *tmp = loader->getInstance();
        if (file[i] == firstLib) {
            ret = tmp;
            _currentLib = i;
        }
        _libs.push_back(tmp);
    }
    return (ret);
}

void ArcadeCore::switchGraphicalLibrary(IBuilder *b)
{
    static bool first = true;
    if (b->getEvents().keyboardState[Key::N] == InputState::RELEASED && first) {
        unsigned long tmp = static_cast<unsigned long>(_currentLib);
        //std::cout << static_cast<unsigned long>(_currentLib) << std::endl;
        tmp++;
        //std::cout << static_cast<unsigned long>(_currentLib) << std::endl;
        if (tmp > _libs.size() - 1)
            _currentLib = 0;
        //std::cout << static_cast<unsigned long>(_currentLib) << std::endl;
        b->reloadLibrary(_libs[tmp]);
        //std::cout << "zcz" << static_cast<unsigned long>(_currentLib) << std::endl;
        loadCoreAssets(b);
        _menu.start(b);
        b->getEvents().keyboardState[Key::N] = InputState::NONE;
        first = false;
    }
}

void ArcadeCore::launchCore(DisplayLibrary *library)
{
    Start *game = NULL;
    DLLoader<Start> *gameLib;
    Builder builder(library);

    loadCoreAssets(&builder);
    _menu.start(&builder);
    _layout.start(&builder);
    while (builder.windowIsOpen()) {
        builder.updateEvents();
        builder.windowClear();
        if (_coreState == CoreState::CORE_MENU) {
            if ((gameLib = _menu.update(&builder)) != NULL) {
                game = gameLib->getInstance();
                game->start(&builder);
                _coreState = CoreState::CORE_GAME;
            }
        }
        else {
            if (_coreState != CoreState::CORE_PAUSE)
                game->update(&builder);
            _layout.update(&builder, _coreState, game->getName());
        }
        builder.windowDisplay();
        switchGraphicalLibrary(&builder);
    }
}