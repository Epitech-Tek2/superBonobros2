/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** CollisionComponent
*/

#ifndef COLLISIONCOMPONENT_HPP_
#define COLLISIONCOMPONENT_HPP_

#include <vector>

#include "Component.hpp"
#include "AEntity.hpp"

namespace gameEngine {

    class CollisionComponent : public Component {
        public:
            std::vector<std::shared_ptr<AEntity>> collingEntitys;
    };

};

#endif /* !COLLISIONCOMPONENT_HPP_ */
