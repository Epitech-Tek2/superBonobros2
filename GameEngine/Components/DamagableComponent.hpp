/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** DamagableComponent
*/

#ifndef DAMAGABLECOMPONENT_HPP_
#define DAMAGABLECOMPONENT_HPP_

#include "Component.hpp"
#include "Damage.hpp"

#include <vector>

namespace gameEngine {

    class DamagableComponent : public Component {
        public:
            std::vector<Damage> damageList;
            bool autoKillEntity = true;
    };

};

#endif /* !DAMAGABLECOMPONENT_HPP_ */
