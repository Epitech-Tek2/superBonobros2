/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** PhysicsComponent
*/

#ifndef PHYSICSCOMPONENT_HPP_
#define PHYSICSCOMPONENT_HPP_

#include "Component.hpp"

namespace gameEngine {

    class PhysicsComponent : public Component {
        public:
            float weight = 0;
            bool isRigidBody = false;
            bool isGround = false;
            bool isWall = false;
            bool affectedByGravity = false;
    };

};

#endif /* !PHYSICSCOMPONENT_HPP_ */
