/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** CollideBuilder
*/

#include "core/include/ArcadeCore/Builder/Builder.hpp"

/* -------------------------------- collider -------------------------------- */

bool Builder::isMouseInBox(Box box)
{
    return ((_events.mouseEvents.pos.x >= box.x &&
            _events.mouseEvents.pos.x <= box.x + box.w &&
            _events.mouseEvents.pos.y >= box.y &&
            _events.mouseEvents.pos.y <= box.y + box.h) ||
            (_events.joyConEvents.cursorPos.x >= box.x &&
            _events.joyConEvents.cursorPos.x <= box.x + box.w &&
            _events.joyConEvents.cursorPos.y >= box.y &&
            _events.joyConEvents.cursorPos.y <= box.y + box.h));
}

bool Builder::circleToCircleCollide(Box b1, Box b2)
{
    Vector2 diff = {std::abs((b1.x + b1.w) - (b2.x + b2.w)), std::abs((b1.y + b1.w) - (b2.y + b2.w))};

    if (pow(diff.x, 2) + pow(diff.y, 2) > pow(b1.w + b2.w, 2))
        return (false);
    return (true);
}

bool Builder::circleToRectCollide(Box b1, Box b2)
{
    Vector2 diff = {std::abs((b1.x + b1.w) - b2.x), std::abs((b1.y + b1.w) - b2.y)};

    if (diff.x > (b2.w / 2) + b1.w || diff.y > (b2.h / 2) + b1.w ||
        (pow(diff.x - b2.w / 2, 2) + pow(diff.y - b2.h / 2, 2)) > pow(b1.w, 2))
        return (false);
    return (true);
}

bool Builder::rectToRectCollide(Box b1, Box b2)
{
    if (!(b1.x < b2.x + b2.w && b1.x + b1.w > b2.x && b1.y + b1.h > b2.y && b1.y < b2.y + b2.h))
        return (false);
    return (true);
}

bool Builder::gameObjectCollide(const std::string &obj1, const std::string &obj2)
{
    Box b1;
    Box b2;
    if (_gameObjects.find(obj1) == _gameObjects.end() || _gameObjects.find(obj2) == _gameObjects.end() ||
        (_gameObjects[obj1].type != ObjectType::TYPE_RECT && _gameObjects[obj1].type != ObjectType::TYPE_RADIUS_RECT && _gameObjects[obj1].type != ObjectType::TYPE_CIRCLE && _gameObjects[obj1].type != ObjectType::TYPE_SPRITE) ||
        (_gameObjects[obj2].type != ObjectType::TYPE_RECT && _gameObjects[obj2].type != ObjectType::TYPE_RADIUS_RECT && _gameObjects[obj2].type != ObjectType::TYPE_CIRCLE && _gameObjects[obj2].type != ObjectType::TYPE_SPRITE))
        return (false);  /////////////////////// TO DO
    b1 = getBody(obj1);
    b2 = getBody(obj2);
    if (_gameObjects[obj1].type == ObjectType::TYPE_CIRCLE && _gameObjects[obj2].type == ObjectType::TYPE_CIRCLE)
        return (circleToCircleCollide(b1, b2));
    else if (_gameObjects[obj1].type == ObjectType::TYPE_CIRCLE)
        return (circleToRectCollide(b1, b2));
    else if (_gameObjects[obj2].type == ObjectType::TYPE_CIRCLE)
        return (circleToRectCollide(b2, b1));
    return (rectToRectCollide(b1, b2));
}

bool Builder::gameObjectCollideToBox(const std::string &obj, Box b)
{
    Box objBox;
    if (_gameObjects.find(obj) == _gameObjects.end() ||
        (_gameObjects[obj].type != ObjectType::TYPE_RECT && _gameObjects[obj].type != ObjectType::TYPE_RADIUS_RECT && _gameObjects[obj].type != ObjectType::TYPE_CIRCLE && _gameObjects[obj].type != ObjectType::TYPE_SPRITE))
        return (false);  /////////////////////// TO DO
    objBox = getBody(obj);
    if (_gameObjects[obj].type != ObjectType::TYPE_CIRCLE)
        return (rectToRectCollide(objBox, b));
    return (circleToRectCollide(objBox, b));
}

bool Builder::gameObjectCollideToRadius(const std::string &obj, Vector2 pos, float r)
{
    Box objBox;

    if (_gameObjects.find(obj) == _gameObjects.end() ||
        (_gameObjects[obj].type != ObjectType::TYPE_RECT && _gameObjects[obj].type != ObjectType::TYPE_RADIUS_RECT && _gameObjects[obj].type != ObjectType::TYPE_CIRCLE && _gameObjects[obj].type != ObjectType::TYPE_SPRITE))
        return (false);  /////////////////////// TO DO
    objBox = getBody(obj);
    if (_gameObjects[obj].type == ObjectType::TYPE_CIRCLE)
        return (circleToCircleCollide(objBox, {pos.x, pos.y, r, 0}));
    return (circleToRectCollide({pos.x, pos.y, r, 0}, objBox));
}
