/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ContactDamageComponent
*/

#ifndef CONTACTDAMAGECOMPONENT_HPP_
#define CONTACTDAMAGECOMPONENT_HPP_

#include <vector>

#include "Component.hpp"
#include "Damage.hpp"

namespace gameEngine {

    class ContactDamageComponent : public Component {
        public:
            std::vector<Damage> damages;
    };

};

#endif /* !CONTACTDAMAGECOMPONENT_HPP_ */
