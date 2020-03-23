/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CoreException
*/

#ifndef COREEXCEPTION_HPP_
#define COREEXCEPTION_HPP_

#include <string>
#include <exception>

class CoreException : public std::exception
{
    public:
        CoreException(const std::string &);

        const char *what() const noexcept override { return _message.c_str(); };
    protected:
        std::string _message;
};

class FileException : public CoreException
{
    public:
        FileException(const std::string &);
};

class BuilderException : public CoreException
{
    public:
        BuilderException(const std::string &);
};

class PngLibException : public CoreException
{
    public:
        PngLibException(const std::string &);
};

#endif /* !COREEXCEPTION_HPP_ */
