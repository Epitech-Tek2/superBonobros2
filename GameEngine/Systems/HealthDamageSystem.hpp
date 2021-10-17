/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** HealthDamageSystem
*/

#ifndef HEALTHDAMAGESYSTEM_HPP_
#define HEALTHDAMAGESYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "HealthComponent.hpp"
#include "DamagableComponent.hpp"

namespace gameEngine {

    class HealthDamageSystem : virtual public ASystem {
        public:
            HealthDamageSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<HealthComponent>(this);
                ecs->systemAddDependances<DamagableComponent>(this);
            }

            ~HealthDamageSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                auto &health = _ecs->getEntityComponent<HealthComponent>(entity);
                auto &damages = _ecs->getEntityComponent<DamagableComponent>(entity).damageList;
                
                health.health._hit = 0;

                for (auto &damage : damages) {
                    health.health.takeDamage(damage);
                    if (health.health._point == 0 && health.autoKillEntity == true)
                        entity->kill();
                }
            }

    };
};

#endif /* !HEALTHDAMAGESYSTEM_HPP_ */
