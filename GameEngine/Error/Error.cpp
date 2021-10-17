/*
** EPITECH PROJECT, 2020
** nanotekspace
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(std::string const &message,
    std::string const &component)
{
    _message = message;
    _componant = component;
}

Error::~Error()
{
}

std::string const &Error::getComponent() const
{
    return _componant;
}

const char *Error::what() const noexcept
{
    return _message.c_str();
}
