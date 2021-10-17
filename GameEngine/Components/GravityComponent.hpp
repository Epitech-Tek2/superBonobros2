/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** GravityComponent
*/

#ifndef GRAVITYCOMPONENT_HPP_
#define GRAVITYCOMPONENT_HPP_

#include "Component.hpp"
#include "Velocity.hpp"

namespace gameEngine {


    class GravityComponent : public Component {
        public:
            const Vector2<float> vec = {0, 0};
            const Vector2<float> force = {0, 9.8};
            const Vector2<float> maxSpeed = {0, 300};
            bool onGround = false;
            Velocity gravityVelocity {vec, force};
    };

};

#endif /* !GRAVITYCOMPONENT_HPP_ */

