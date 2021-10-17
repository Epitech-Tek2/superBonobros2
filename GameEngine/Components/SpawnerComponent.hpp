/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SpawnerComponent
*/

#ifndef SPAWNERCOMPONENT_HPP_
#define SPAWNERCOMPONENT_HPP_

#include <vector>

#include "Component.hpp"
#include "TFactory.hpp"
#include "ECS.hpp"

namespace gameEngine {

    class SpawnerComponent : public Component {
        public:
            std::vector<std::string> entityTagsList;
            TFactory<const std::string, std::shared_ptr<AEntity>, ECS *> entityFactory;
            bool spawnOnMe = true;
    };

};

#endif /* !SPAWNERCOMPONENT_HPP_ */

