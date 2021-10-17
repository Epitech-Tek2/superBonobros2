/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** GlobalMovementComponent
*/

#ifndef GLOBALMOVEMENTCOMPONENT_HPP_
#define GLOBALMOVEMENTCOMPONENT_HPP_

#include "Vector2.hpp"
#include "Component.hpp"

namespace gameEngine {


    class GlobalMovementComponent : public Component {
        public:
            Vector2<float> _movement = {0.f, 0.f};
    };

};

#endif /* !GLOBALMOVEMENTCOMPONENT_HPP_ */
