/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** DeathActionComponent
*/

#ifndef DEATHACTIONCOMPONENT_HPP_
#define DEATHACTIONCOMPONENT_HPP_

#include <vector>
#include <functional>
#include "Component.hpp"
#include "ECS.hpp"

namespace gameEngine {

    class DeathActionComponent : public Component {
        public:
            std::vector<std::function<void(ECS *ecs)>> _deathActionList;
    };

};

#endif /* !DEATHACTIONCOMPONENT_HPP_ */
