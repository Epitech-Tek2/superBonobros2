/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ShieldComponent
*/

#ifndef SHIELDCOMPONENT_HPP_
#define SHIELDCOMPONENT_HPP_

#include "Component.hpp"
#include "Damagable.hpp"

namespace gameEngine {

    class ShieldComponent : public Component {
        public:
            Damagable shield;
    };

};

#endif /* !SHIELDCOMPONENT_HPP_ */
