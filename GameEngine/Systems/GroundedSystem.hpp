/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** GroundedSystem
*/

#ifndef GROUNDEDSYSTEM_HPP_
#define GROUNDEDSYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "PhysicsComponent.hpp"
#include "CollisionComponent.hpp"
#include "GravityComponent.hpp"


namespace gameEngine {

    class GroundedSystem : virtual public ASystem {
        public:
            GroundedSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<PhysicsComponent>(this);
                ecs->systemAddDependances<CollisionComponent>(this);
                ecs->systemAddDependances<GravityComponent>(this);
            }

            ~GroundedSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                auto &collisions = _ecs->getEntityComponent<CollisionComponent>(entity).collingEntitys;
                auto &gravity = _ecs->getEntityComponent<GravityComponent>(entity);

                gravity.onGround = false;
                for (auto &entity2 : collisions) {
                    auto &physics = _ecs->getEntityComponent<PhysicsComponent>(entity2);
                    if (physics.isGround == true) {
                        gravity.onGround = true;
                    }
                }
            }
    };
};

#endif /* !GROUNDEDSYSTEM_HPP_ */
