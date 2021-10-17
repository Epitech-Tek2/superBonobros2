/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** DeathActionSystem
*/

#ifndef DEATHACTIONSYSTEM_HPP_
#define DEATHACTIONSYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "DeathActionComponent.hpp"

namespace gameEngine {

    class DeathActionSystem : virtual public ASystem {
        public:
            DeathActionSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<DeathActionComponent>(this);
            }

            ~DeathActionSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                auto &deathAction = _ecs->getEntityComponent<DeathActionComponent>(entity);

                if (entity->isAlive() == false) {
                    for (auto it : deathAction._deathActionList) {
                        it(_ecs);
                    }
                }
            }

    };
};

#endif /* !DEATHACTIONSYSTEM_HPP_ */

