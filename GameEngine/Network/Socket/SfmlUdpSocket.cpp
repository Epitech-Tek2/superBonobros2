/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SfmlUdpSocket
*/

#include <iostream>
#include "SfmlUdpSocket.hpp"

server::SfmlUdpSocket::SfmlUdpSocket() : _targetIp(""), _targetPort(0)
{
    _socket.setBlocking(false);
    for (size_t i = 0; i != sf::UdpSocket::MaxDatagramSize; ++i)
        _buffer[i] = 0;
}

server::SfmlUdpSocket::~SfmlUdpSocket()
{
}

unsigned short server::SfmlUdpSocket::getSocketPort() const noexcept
{
    return _socket.getLocalPort();
}

bool server::SfmlUdpSocket::bind(unsigned short port) noexcept
{
    if (_socket.bind(port) != sf::Socket::Done)
        return false;
    return true;
}

bool server::SfmlUdpSocket::sendData(std::string const &dataToSend, std::string const &targetIp, unsigned short const targetPort) noexcept
{
    if (dataToSend.size() > sf::UdpSocket::MaxDatagramSize)
        return false;
    if (_socket.send(dataToSend.c_str(), dataToSend.size(),
        (targetIp.empty() ? _targetIp.toString() : targetIp),
        (targetPort ? targetPort : _targetPort)) != sf::Socket::Done)
        return false;
    return true;
}

bool server::SfmlUdpSocket::receiveData(std::string &dataReceived) noexcept
{
    if (_socket.receive(_buffer, sf::UdpSocket::MaxDatagramSize, _byteReceived, _address, _port) != sf::Socket::Done)
        return false;
    dataReceived = _buffer;
    for (size_t i = 0; _buffer[i] != 0; ++i)
        _buffer[i] = 0;
    return true;
}

void server::SfmlUdpSocket::setBlocking(bool blocking) noexcept
{
    _socket.setBlocking(blocking);
}

bool server::SfmlUdpSocket::isBlocking(void) const noexcept
{
    return _socket.isBlocking();
}

void server::SfmlUdpSocket::setTargetIp(std::string const &targetIp) noexcept
{
    _targetIp = targetIp;
}

void server::SfmlUdpSocket::setTargetPort(unsigned short const targetPort) noexcept
{
    _targetPort = targetPort;
}

std::string server::SfmlUdpSocket::getLastSenderIp() const
{
    return _address.toString();
}

unsigned short server::SfmlUdpSocket::getLastSenderPort() const
{
    return _port;
}