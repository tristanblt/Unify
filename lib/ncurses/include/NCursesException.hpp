/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** NCursesException
*/

#ifndef NCURSESEXCEPTION_HPP_
#define NCURSESEXCEPTION_HPP_

#include <string>
#include <exception>

class NCursesException : public std::exception
{
    public:
        NCursesException(const std::string &);

        const char *what() const noexcept override { return _message.c_str(); };
    protected:
        std::string _message;
};

class NCursesAssetException : public NCursesException
{
    public:
        NCursesAssetException(const std::string &);
};

class NCursesBitCrushException : public NCursesException
{
    public:
        NCursesBitCrushException(const std::string &);
};

#endif /* !NCURSESEXCEPTION_HPP_ */
