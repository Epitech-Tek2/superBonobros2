/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ASceneCommandInterpreter
*/

#ifndef ASCENECOMMANDINTERPRETER_HPP_
#define ASCENECOMMANDINTERPRETER_HPP_

#include "ISceneCommandInterpreter.hpp"

#include <unordered_map>
#include <functional>
#include <vector>

namespace gameEngine {
    class ASceneCommandInterpreter : public ISceneCommandInterpreter {
        public:
            ASceneCommandInterpreter() = default;
            virtual ~ASceneCommandInterpreter() = default;

            bool execCommand(std::vector<std::string> const &command) final;
            void setSystem(NetworkSystem *system) final;
        protected:
            std::unordered_map<std::string, std::function<bool(NetworkSystem *, std::vector<std::string> const &)>> _commands;
            NetworkSystem *_system = nullptr;
    };
}

#endif /* !ASCENECOMMANDINTERPRETER_HPP_ */