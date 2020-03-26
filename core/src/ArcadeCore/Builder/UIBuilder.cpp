/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Builder
*/

#include "core/include/ArcadeCore/Builder/Builder.hpp"
#include "core/include/ArcadeCore/CoreException.hpp"

/* --------------------------------- buttons -------------------------------- */

void Builder::basicButtonInit(const std::string &name)
{
    BasicButton *o = new BasicButton();

    _gameObjects[name] = {
        ObjectType::TYPE_BASIC_BUTTON,
        (void *)o
    };
    textInit(name + "_text");
    radiusRectInit(name + "_radiusRect");
}

void Builder::basicButtonSetDisplayBox(const std::string &name, Box box)
{
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);

    o->displayBox = box;
}

void Builder::basicButtonSetRadius(const std::string &name, float radius)
{
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);

    o->radius = radius;
}

void Builder::basicButtonSetBackgroundColors(const std::string &name, Color color_n, Color color_h, Color color_c)
{
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);

    o->boxColors[0] = color_n;
    o->boxColors[1] = color_h;
    o->boxColors[2] = color_c;
}

void Builder::basicButtonSetTextColors(const std::string &name, Color color_n, Color color_h, Color color_c)
{
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);

    o->textColors[0] = color_n;
    o->textColors[1] = color_h;
    o->textColors[2] = color_c;
}

void Builder::basicButtonSetText(const std::string &name, const std::string &text)
{
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);

    o->text = text;
}

void Builder::basicButtonSetFontSize(const std::string &name, int size)
{
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);

    o->fontSize = size;
}

void Builder::basicButtonSetFont(const std::string &name, const std::string &idx)
{
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);

    o->fontIdx = idx;
}

void Builder::spriteButtonInit(const std::string &name)
{
    SpriteButton *o = new SpriteButton();

    _gameObjects[name] = {
        ObjectType::TYPE_SPRITE_BUTTON,
        (void *)o
    };
    spriteInit(name + "_sprite");
}

void Builder::spriteButtonSetDisplayBox(const std::string &name, Box box)
{
    SpriteButton *o = static_cast<SpriteButton *>(_gameObjects[name].item);

    o->displayBox = box;
}

void Builder::spriteButtonSetSpriteBoxes(const std::string &name, Box box_n, Box box_h, Box box_c)
{
    SpriteButton *o = static_cast<SpriteButton *>(_gameObjects[name].item);

    o->spriteBoxes[0] = box_n;
    o->spriteBoxes[1] = box_h;
    o->spriteBoxes[2] = box_c;
}

void Builder::spriteButtonSetSprite(const std::string &name, const std::string &idx)
{
    SpriteButton *o = static_cast<SpriteButton *>(_gameObjects[name].item);

    o->spriteSheetIndex = idx;
}

void Builder::switchButtonInit(const std::string &name)
{
    SwitchButton *o = new SwitchButton();

    _gameObjects[name] = {
        ObjectType::TYPE_SWITCH_BUTTON,
        (void *)o
    };
}


bool Builder::buttonDraw(const std::string &name)
{
    if (_gameObjects.find(name) == _gameObjects.end())
        throw BuilderException("could not find button");
    if (_gameObjects[name].type == ObjectType::TYPE_BASIC_BUTTON)
        return (basicButtonDraw(name) && _events.mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED);
    if (_gameObjects[name].type == ObjectType::TYPE_SPRITE_BUTTON)
        return (spriteButtonDraw(name) && _events.mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED);
    return (switchButtonDraw(name) && _events.mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED);
}


bool Builder::basicButtonDraw(const std::string &name)
{
    BasicButton *o = static_cast<BasicButton *>(_gameObjects[name].item);
    bool state = isMouseInBox(o->displayBox);

    radiusRectSetRadius(name + "_radiusRect", o->radius);
    radiusRectSetPosition(name + "_radiusRect", {o->displayBox.x, o->displayBox.y});
    radiusRectSetSize(name + "_radiusRect", {o->displayBox.w, o->displayBox.h});
    textSetText(name + "_text", o->text);
    textSetPosition(name + "_text", {static_cast<float>(o->displayBox.x + (o->displayBox.w / 2) - (o->text.size() / 2 * o->fontSize / 1.6)),
                                    o->displayBox.y + (o->displayBox.h / 2) - o->fontSize / 1.5f});
    textSetFontSize(name + "_text", o->fontSize);
    textSetFont(name + "_text", o->fontIdx);
    if (state == true && getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::HOLD) {
        radiusRectSetColor(name + "_radiusRect", o->boxColors[0]);
        textSetColor(name + "_text", o->textColors[0]);
    } else if (state == true) {
        radiusRectSetColor(name + "_radiusRect", o->boxColors[1]);
        textSetColor(name + "_text", o->textColors[1]);
    } else {
        radiusRectSetColor(name + "_radiusRect", o->boxColors[2]);
        textSetColor(name + "_text", o->textColors[2]);
    }
    radiusRectDraw(name + "_radiusRect");
    textDraw(name + "_text");
    return (state);
}

bool Builder::spriteButtonDraw(const std::string &name)
{
    SpriteButton *o = static_cast<SpriteButton *>(_gameObjects[name].item);
    bool state = isMouseInBox(o->displayBox);

    spriteSetOpacity(name + "_sprite", 255);
    spriteSetSprite(name + "_sprite", o->spriteSheetIndex);
    spriteSetPosition(name + "_sprite", {o->displayBox.x, o->displayBox.y});
    if (state == true && getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::HOLD)
        spriteSetSize(name + "_sprite", {o->displayBox.w, o->displayBox.h}, o->spriteBoxes[0]);
    else if (state == true)
        spriteSetSize(name + "_sprite", {o->displayBox.w, o->displayBox.h}, o->spriteBoxes[1]);
    else
        spriteSetSize(name + "_sprite", {o->displayBox.w, o->displayBox.h}, o->spriteBoxes[2]);
    spriteDraw(name + "_sprite");
    return (state);
}

bool Builder::switchButtonDraw(const std::string &name)
{
    return (false);
}

void Builder::selectorInit(const std::string &name)
{
    Selector *o = new Selector();

    _gameObjects[name] = {
        ObjectType::TYPE_SELECTOR,
        (void *)o
    };
    rectInit(name + "_rect");
    textInit(name + "_text");
    textSetColor(name + "_text", hexToColor(0xFFFFFFFF));
}

void Builder::selectorSetDisplayBox(const std::string &name, Box box)
{
    Selector *o = static_cast<Selector *>(_gameObjects[name].item);

    o->displayBox = box;
}

void Builder::selectorSetBackgroundColors(const std::string &name, Color color_n, Color color_h, Color color_c)
{
    Selector *o = static_cast<Selector *>(_gameObjects[name].item);

    o->boxColors[0] = color_n;
    o->boxColors[1] = color_h;
    o->boxColors[2] = color_c;
}

void Builder::selectorSetItems(const std::string &name, const std::vector<std::string> &items)
{
    Selector *o = static_cast<Selector *>(_gameObjects[name].item);

    o->items = items;
}

void Builder::selectorSetFont(const std::string &name, const std::string &idx)
{
    Selector *o = static_cast<Selector *>(_gameObjects[name].item);

    o->fontIdx = idx;
}

int Builder::selectorDraw(const std::string &name)
{
    Selector *o = static_cast<Selector *>(_gameObjects[name].item);
    int i = 0;
    float height = (windowHeight() * ((float)8 / 100));

    rectSetPosition(name + "_rect", {o->displayBox.x, o->displayBox.y});
    rectSetSize(name + "_rect", {o->displayBox.w, o->displayBox.h});
    rectSetColor(name + "_rect", o->boxColors[0]);
    rectDraw(name + "_rect");
    textSetFont(name + "_text", o->fontIdx);
    textSetFontSize(name + "_text", (windowHeight() * ((float)2 / 100)));
    for (auto &elem : o->items) {
        bool state = isMouseInBox({o->displayBox.x, o->displayBox.y + i * height, o->displayBox.w, height});
        rectSetPosition(name + "_rect", {o->displayBox.x, o->displayBox.y + i * height});
        rectSetSize(name + "_rect", {o->displayBox.w, height});
        if (state && getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::RELEASED)
            o->selected = i;
        else if (state)
            rectSetColor(name + "_rect", o->boxColors[2]);
        else if (i == o->selected)
            rectSetColor(name + "_rect", o->boxColors[1]);
        else
            rectSetColor(name + "_rect", o->boxColors[0]);
        rectDraw(name + "_rect");
        textSetText(name + "_text", elem);
        textSetPosition(name + "_text", {o->displayBox.x + 60, o->displayBox.y + i * height + (windowHeight() * ((float)3 / 100))});
        textDraw(name + "_text");
        i++;
    }
    return (o->selected);
}

void Builder::sliderInit(const std::string &name)
{
    Slider *o = new Slider();

    _gameObjects[name] = {
        ObjectType::TYPE_SLIDER,
        (void *)o
    };
    radiusRectInit(name + "_radiusRect");
    circleInit(name + "_circle");
    textInit(name + "_text");
    textSetColor(name + "_text", hexToColor(0xFFFFFFFF));
}

void Builder::sliderSetWidth(const std::string &name, float width)
{
    Slider *o = static_cast<Slider *>(_gameObjects[name].item);

    o->width = width;
} 

void Builder::sliderSetPosition(const std::string &name, Vector2 position)
{
    Slider *o = static_cast<Slider *>(_gameObjects[name].item);

    o->pos = position;
}

void Builder::sliderSetBackgroundColor(const std::string &name, Color color)
{
    Slider *o = static_cast<Slider *>(_gameObjects[name].item);

    o->backgroundColor = color;
}

void Builder::sliderSetSliderColor(const std::string &name, Color color)
{
    Slider *o = static_cast<Slider *>(_gameObjects[name].item);

    o->slideColor = color;
}

void Builder::sliderDraw(const std::string &name, int &value)
{
    Slider *o = static_cast<Slider *>(_gameObjects[name].item);
    float mouseX = getEvents().mouseEvents.pos.x;

    radiusRectSetPosition(name + "_radiusRect", {o->pos.x, o->pos.y});
    radiusRectSetSize(name + "_radiusRect", {o->width, windowHeight() * ((float)2 / 100)});
    radiusRectSetRadius(name + "_radiusRect", windowHeight() * ((float)1 / 100));
    radiusRectSetColor(name + "_radiusRect", o->backgroundColor);
    radiusRectDraw(name + "_radiusRect");
    if (isMouseInBox({o->pos.x, o->pos.y, o->width, windowHeight() * ((float)2 / 100)}) &&
        getEvents().mouseEvents.mouseStates[MouseButton::LEFT_CLICK] == InputState::HOLD)
        value = (mouseX - o->pos.x) * 100 / o->width;
    circleSetRadius(name + "_circle", windowHeight() * (1.5f / 100));
    circleSetColor(name + "_circle", o->slideColor);
    circleSetPosition(name + "_circle", {o->pos.x + o->width * ((float)value / 100) - windowHeight() * (0.75f / 100), o->pos.y - windowHeight() * (0.5f / 100)});
    circleDraw(name + "_circle");
}
