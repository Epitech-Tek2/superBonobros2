/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** AGame
*/

#ifndef AGAME_HPP_
#define AGAME_HPP_

#include <list>
#include <queue>
#include <memory>
#include "AScene.hpp"
#include "INetwork.hpp"

class IUdpSocket;

namespace gameEngine {

    class INetwork;
    class IGraphic;

    class AGame {
        public:
            INetwork *_network;
            IGraphic *_graphicLib;

            AGame(INetwork *socket, IGraphic *graphicLib);
            virtual ~AGame();

            template<typename T, typename ...Targs>
            void addScene(Targs ...args) {
                auto scene = std::make_shared<T>(this, args...);

                _scenes.push_front(scene);
            }
            void update(float deltaTime);

            void addTarget(const std::string &id, const std::string &ip, unsigned short port);
            void removeTarget(const std::string &id);
            void removeTarget(const std::string &ip, unsigned short port);
            const std::string &getTargetId(const std::string &ip, unsigned short port) const;
            const NetworkTarget &getTarget(const std::string &id) const;
            void pushCommand(const std::vector<std::string> &command);
            bool popCommand(std::vector<std::string> &vecBuffer);

            inline bool isOpen(void)
            {
                return _open;
            }

            inline void kill(void)
            {
                _open = false;
            }

        private:
            bool _open;
            std::list<std::shared_ptr<AScene>> _scenes;
            void removeDeadScene(void);
            std::queue<std::vector<std::string>> _commands;
    };
};

#endif /* !AGAME_HPP_ */