/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** AGame
*/

#include <ctime>

#include "AGame.hpp"
#include "IGraphic.hpp"
#include "INetwork.hpp"
#include "Error.hpp"

gameEngine::AGame::AGame(INetwork *network, IGraphic *graphicLib) : _network(network), _graphicLib(graphicLib), _open(true)
{
    std::srand(std::time(0));
}

gameEngine::AGame::~AGame()
{
}

void gameEngine::AGame::update(float deltaTime)
{
    if (_scenes.size() >= 1) {
        (*_scenes.begin())->update(deltaTime);
    }
    removeDeadScene();
}

void gameEngine::AGame::removeDeadScene(void)
{
    for (auto it = _scenes.begin(); it != _scenes.end(); ++it) {
        if (!(*it)->isAlive()) {
            _scenes.erase(it--);
        }
    }
}

void gameEngine::AGame::addTarget(const std::string &id, const std::string &ip, unsigned short port)
{
    std::vector<std::string> vec;
    vec.push_back("1000");
    vec.push_back(id);
    pushCommand(vec);
    _network->addTarget(id, ip, port);
}

void gameEngine::AGame::removeTarget(const std::string &id)
{
    std::vector<std::string> vec;
    vec.push_back("1001");
    vec.push_back(id);
    pushCommand(vec);
    _network->removeTarget(id);
}

void gameEngine::AGame::removeTarget(const std::string &ip, unsigned short port)
{
    std::vector<std::string> vec;
    auto map = _network->getTargets();

    for (auto it : map) {
        if (it.second.ip == ip && it.second.port == port) {
            vec.push_back("1001");
            vec.push_back(it.first);
            pushCommand(vec);
            _network->removeTarget(it.first);
            return;
        }
    }
}

void gameEngine::AGame::pushCommand(const std::vector<std::string> &command)
{
    _commands.push(command);
}

bool gameEngine::AGame::popCommand(std::vector<std::string> &vecBuffer)
{
    if (_commands.empty())
        return false;
    vecBuffer = _commands.front();
    _commands.pop();
    return true;
}

const std::string &gameEngine::AGame::getTargetId(const std::string &ip, unsigned short port) const
{
    const auto &map = _network->getTargets();

    for (auto &it : map)
        if (it.second.ip == ip && it.second.port == port)
            return it.first;
    throw (Error("Use of unregister target"));
}

const gameEngine::NetworkTarget &gameEngine::AGame::getTarget(const std::string &id) const
{
    const auto &map = _network->getTargets();

    for (auto &it : map)
        if (it.first == id)
            return it.second;
    throw (Error("Use of unknow target id"));

}

