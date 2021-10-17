/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** UdpNetwork
*/

#ifndef UDPNETWORK_HPP_
#define UDPNETWORK_HPP_

#include "INetwork.hpp"

#include <memory>

class IUdpSocket;

namespace gameEngine {
    class UdpNetwork : public INetwork {
        public:
            UdpNetwork(IUdpSocket *socket);
            ~UdpNetwork();

            void sendTo(std::string const &id, std::string const &command) final;
            void sendToAll(std::string const &command) final;
            void addTarget(std::string const &id, std::string const &ip, unsigned short port) final;
            void removeTarget(std::string const &id) final;
            void removeTarget(std::string const &ip, unsigned short port) final;
            std::unordered_map<std::string, NetworkTarget> const &getTargets() const final;

        private:
            std::unordered_map<std::string, NetworkTarget> _targets;
            IUdpSocket *_socket;
    };
}

#endif /* !UDPNETWORK_HPP_ */