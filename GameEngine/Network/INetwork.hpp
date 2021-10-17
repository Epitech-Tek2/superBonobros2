/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** INetwork
*/

#ifndef INETWORK_HPP_
#define INETWORK_HPP_

#include <string>
#include <unordered_map>

namespace gameEngine {
    struct NetworkTarget {
        NetworkTarget(std::string const &IP = "", unsigned short Port = 0) : ip(IP), port(Port) {}
        std::string ip;
        unsigned short port;
    };

    class INetwork {
        public:
            virtual ~INetwork() = default;

            virtual void sendTo(std::string const &id, std::string const &command) = 0;
            virtual void sendToAll(std::string const &command) = 0;
            virtual void addTarget(std::string const &id, std::string const &ip, unsigned short port) = 0;
            virtual void removeTarget(std::string const &id) = 0;
            virtual void removeTarget(std::string const &ip, unsigned short port) = 0;
            virtual std::unordered_map<std::string, NetworkTarget> const &getTargets() const = 0;
    };
}

#endif /* !INETWORK_HPP_ */