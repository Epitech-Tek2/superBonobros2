/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** DamagableResetSystem
*/

#ifndef DAMAGABLERESETSYSTEM_HPP_
#define DAMAGABLERESETSYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "DamagableComponent.hpp"

namespace gameEngine {

    class DamagableResetSystem : virtual public ASystem {
        public:
            DamagableResetSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<DamagableComponent>(this);
            }

            ~DamagableResetSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                auto &damages = _ecs->getEntityComponent<DamagableComponent>(entity);

                if (damages.autoKillEntity) {
                    for (auto &damage : damages.damageList) {
                        if (damage._damage != 0)
                            entity->kill();
                    }
                }
                damages.damageList.clear();
            }

    };
};

#endif /* !DAMAGABLERESETSYSTEM_HPP_ */
