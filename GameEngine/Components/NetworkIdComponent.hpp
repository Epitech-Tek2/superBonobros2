/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** NetworkIdComponent
*/

#ifndef NETWORKIDCOMPONENT_HPP_
#define NETWORKIDCOMPONENT_HPP_

#include "Component.hpp"

namespace gameEngine {

    class NetworkIdComponent : public Component {
        public:
            size_t id = static_cast<size_t>(std::rand());
            float lastUpdate = 0;
    };

};

#endif /* !NETWORKIDCOMPONENT_HPP_ */
