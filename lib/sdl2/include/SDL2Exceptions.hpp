/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SDL2Exceptions
*/

#ifndef SDL2EXCEPTIONS_HPP_
#define SDL2EXCEPTIONS_HPP_

#include <string>
#include <exception>

class SDL2Exception : public std::exception
{
    public:
        SDL2Exception(const std::string &);

        const char *what() const noexcept override { return _message.c_str(); };
    protected:
        std::string _message;
};

class SDL2AssetException : public SDL2Exception
{
    public:
        SDL2AssetException(const std::string &);
};

class SDL2BitCrushException : public SDL2Exception
{
    public:
        SDL2BitCrushException(const std::string &);
};

#endif /* !SDL2EXCEPTIONS_HPP_ */
