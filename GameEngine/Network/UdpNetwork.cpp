/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** UdpNetwork
*/

#include "UdpNetwork.hpp"
#include "IUdpSocket.hpp"

gameEngine::UdpNetwork::UdpNetwork(IUdpSocket *socket) : _socket(socket)
{
}

gameEngine::UdpNetwork::~UdpNetwork()
{
}

void gameEngine::UdpNetwork::sendTo(std::string const &id, std::string const &command)
{
    auto target = _targets.find(id);

    if (target != _targets.end() && _socket)
        _socket->sendData(command, target->second.ip, target->second.port);

}

void gameEngine::UdpNetwork::sendToAll(std::string const &command)
{
    if (!_socket)
        return;
    for (auto i = _targets.begin(); i != _targets.end(); ++i)
        _socket->sendData(command, i->second.ip, i->second.port);
}

void gameEngine::UdpNetwork::addTarget(std::string const &id, std::string const &ip, unsigned short port)
{
    _targets[id] = {ip, port};
}

void gameEngine::UdpNetwork::removeTarget(std::string const &id)
{
    auto i = _targets.find(id);

    if (i != _targets.end())
        _targets.erase(i);
}

void gameEngine::UdpNetwork::removeTarget(std::string const &ip, unsigned short port)
{
    for (auto i = _targets.begin(); i != _targets.end(); ++i)
        if (i->second.ip == ip && i->second.port == port) {
            i = _targets.erase(i);
            if (i == _targets.end())
                break;
        }
}

std::unordered_map<std::string, gameEngine::NetworkTarget> const &gameEngine::UdpNetwork::getTargets() const
{
    return _targets;
}
