/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** GravitySystem
*/

#ifndef GRAVITYSYSTEM_HPP_
#define GRAVITYSYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "PhysicsComponent.hpp"
#include "ForceComponent.hpp"
#include "GravityComponent.hpp"

namespace gameEngine {

    class GravitySystem : virtual public ASystem {
        public:
            GravitySystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<PhysicsComponent>(this);
                ecs->systemAddDependances<ForceComponent>(this);
                ecs->systemAddDependances<GravityComponent>(this);
            }

            ~GravitySystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float deltaTime)
            {
                auto &physics = _ecs->getEntityComponent<PhysicsComponent>(entity);
                auto &forces = _ecs->getEntityComponent<ForceComponent>(entity)._forceList;
                auto &gravity = _ecs->getEntityComponent<GravityComponent>(entity);
                auto &velocity = gravity.gravityVelocity;

                if (physics.affectedByGravity == true && gravity.onGround == false) {
                    forces.push_back(velocity.run(deltaTime));
                }
                else {
                    velocity.reset(velocity._baseSpeed, velocity._acceleration, velocity._maxSpeed);
                }
            }
    };
};

#endif /* !GRAVITYSYSTEM_HPP_ */
