/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SfmlExceptions
*/

#ifndef SFMLEXCEPTIONS_HPP_
#define SFMLEXCEPTIONS_HPP_

#include <string>
#include <exception>

class SfmlException : public std::exception
{
    public:
        SfmlException(const std::string &);

    protected:
        std::string _message;
};

class SfmlAssetException : public SfmlException
{
    public:
        SfmlAssetException(const std::string &);
};

class SfmlBitCrushException : public SfmlException
{
    public:
        SfmlBitCrushException(const std::string &);
};

#endif /* !SFMLEXCEPTIONS_HPP_ */
