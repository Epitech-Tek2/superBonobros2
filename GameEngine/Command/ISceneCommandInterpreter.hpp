/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ISceneCommandInterpreter
*/

#ifndef ISCENECOMMANDINTERPRETER_HPP_
#define ISCENECOMMANDINTERPRETER_HPP_

#include <string>
#include <vector>

namespace gameEngine {
    class NetworkSystem;

    class ISceneCommandInterpreter {
        public:
            virtual ~ISceneCommandInterpreter() = default;

        virtual bool execCommand(std::vector<std::string> const &) = 0;
        virtual void setSystem(NetworkSystem *sysetem) = 0;
    };
}

#endif /* !ISCENECOMMANDINTERPRETER_HPP_ */