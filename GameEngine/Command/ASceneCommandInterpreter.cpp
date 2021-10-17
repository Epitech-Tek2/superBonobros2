/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ASceneCommandInterpreter
*/

#include "ASceneCommandInterpreter.hpp"

#include <iostream>

bool gameEngine::ASceneCommandInterpreter::execCommand(std::vector<std::string> const &command)
{
    if (command.empty() || command[0].empty())
        return true;
    auto action = _commands.find(command[0]);

    if (action != _commands.end()) {
        return action->second(_system, command);
    }
    return true;
}

void gameEngine::ASceneCommandInterpreter::setSystem(NetworkSystem *system)
{
    _system = system;
}