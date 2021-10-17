/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ShieldDamageSystem
*/

#ifndef SHIELDDAMAGESYSTEM_HPP_
#define SHIELDDAMAGESYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "ShieldComponent.hpp"
#include "DamagableComponent.hpp"

namespace gameEngine {

    class ShieldDamageSystem : virtual public ASystem {
        public:
            ShieldDamageSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<ShieldComponent>(this);
                ecs->systemAddDependances<DamagableComponent>(this);
            }

            ~ShieldDamageSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                auto &shield = _ecs->getEntityComponent<ShieldComponent>(entity);
                auto &damages = _ecs->getEntityComponent<DamagableComponent>(entity).damageList;

                shield.shield._hit = 0;

                for (auto &damage : damages) {
                    if (damage._affectedByShield == true)
                        shield.shield.takeDamage(damage);
                }
            }

    };
};

#endif /* !SHIELDDAMAGESYSTEM_HPP_ */
