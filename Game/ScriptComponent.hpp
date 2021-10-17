/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** ScriptComponent
*/

#ifndef SCRIPTCOMPONENT_HPP_
#define SCRIPTCOMPONENT_HPP_

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

#include "Component.hpp"

class ScriptComponent : public gameEngine::Component {
    public:
        ScriptComponent() = default;
        ~ScriptComponent() = default;

        static std::vector<std::pair<std::string, float>> get_commands(const std::string &path)
        {
            std::ifstream cfgfile(path);
            std::vector<std::pair<std::string, float>> commands;

            for (std::string line; std::getline(cfgfile, line);)
            {
                std::istringstream iss(line);
                std::string id, eq, val;
                bool error = false;

                if (!(iss >> id)) error = true;
                else if (id[0] == '#') continue;
                else if (!(iss >> eq >> val >> std::ws) || eq != "=" || iss.get() != EOF)
                    error = true;
                if (error);
                else
                    commands.push_back(std::pair<std::string, float>(id, std::atof(val.c_str())));
            }
            return (commands);
        }

        std::vector<std::pair<std::string, float>> _script;
        float save = 0;
        int _scriptPos = -1;

    protected:
    private:
};

#endif /* !SCRIPTCOMPONENT_HPP_ */
