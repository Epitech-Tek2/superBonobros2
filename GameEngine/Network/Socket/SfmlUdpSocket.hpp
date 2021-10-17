/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SfmlUdpSocket
*/

#ifndef SFMLUDPSOCKET_HPP_
    #define SFMLUDPSOCKET_HPP_
    #include <SFML/Network/UdpSocket.hpp>
    #include "IUdpSocket.hpp"
    namespace server {
        class SfmlUdpSocket : public IUdpSocket {
            public:
                SfmlUdpSocket();
                ~SfmlUdpSocket();

                SfmlUdpSocket(SfmlUdpSocket const &other) = delete;
                SfmlUdpSocket operator=(SfmlUdpSocket const &other) = delete;

                bool bind(unsigned short const port) noexcept final;
                unsigned short getSocketPort() const noexcept final;
                bool sendData(std::string const &dataToSend, std::string const &targetIp = "", unsigned short const targetPort = 0) noexcept final;
                bool receiveData(std::string &dataReceived) noexcept final;
                void setBlocking(bool blocking) noexcept final;
                bool isBlocking(void) const noexcept final;
                void setTargetIp(std::string const &targetIp) noexcept final;
                void setTargetPort(unsigned short const targetPort) noexcept final;
                inline std::string getLastSenderIp() const final;
                inline unsigned short getLastSenderPort() const final;
            private:
                char _buffer[sf::UdpSocket::MaxDatagramSize];
                sf::UdpSocket _socket;
                std::size_t _byteReceived;
                sf::IpAddress _address;
                sf::IpAddress _targetIp;
                unsigned short _port;
                unsigned short _targetPort;
        };
    };
#endif /* !SFMLUDPSOCKET_HPP_ */