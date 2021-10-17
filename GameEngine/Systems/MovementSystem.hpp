/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** MovementSystem
*/

#ifndef MOVEMENTSYSTEM_HPP_
#define MOVEMENTSYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "Transform2DComponent.hpp"
#include "GlobalMovementComponent.hpp"

namespace gameEngine {

    class MovementSystem : virtual public ASystem {
        public:
            MovementSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<Transform2DComponent>(this);
                ecs->systemAddDependances<GlobalMovementComponent>(this);
            }

            ~MovementSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float deltaTime)
            {
                auto &transform = _ecs->getEntityComponent<Transform2DComponent>(entity)._transform;
                auto &movement = _ecs->getEntityComponent<GlobalMovementComponent>(entity)._movement;
                transform.move(movement * deltaTime);
            }
    };
};

#endif /* !MOVEMENTSYSTEM_HPP_ */
