/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** HealthComponent
*/

#ifndef HEALTHCOMPONENT_HPP_
#define HEALTHCOMPONENT_HPP_

#include "Component.hpp"
#include "Damagable.hpp"

namespace gameEngine {

    class HealthComponent : public Component {
        public:
            Damagable health;
            bool autoKillEntity = false;
    };

};

#endif /* !HEALTHCOMPONENT_HPP_ */
