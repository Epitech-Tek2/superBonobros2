/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ForceApplicationSystem
*/

#ifndef FORCEAPPLICATIONSYSTEM_HPP_
#define FORCEAPPLICATIONSYSTEM_HPP_

#include <iostream>

#include "ASystem.hpp"
#include "ECS.hpp"
#include "GlobalMovementComponent.hpp"
#include "ForceComponent.hpp"
#include "SAT.hpp"

namespace gameEngine {

    class ForceApplicationSystem : virtual public ASystem {
        public:
            ForceApplicationSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<ForceComponent>(this);
                ecs->systemAddDependances<GlobalMovementComponent>(this);
            }

            ~ForceApplicationSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                auto &movement = _ecs->getEntityComponent<GlobalMovementComponent>(entity)._movement;
                auto &forces = _ecs->getEntityComponent<ForceComponent>(entity)._forceList;

                movement = {0.f, 0.f};
                for (auto force : forces)
                    movement += force;
                forces.clear();
            }
    };
};

#endif /* !FORCEAPPLICATIONSYSTEM_HPP_ */
