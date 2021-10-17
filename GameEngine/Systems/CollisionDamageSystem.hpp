/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** CollisionDamageSystem
*/

#ifndef COLLISIONDAMAGESYSTEM_HPP_
#define COLLISIONDAMAGESYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "DamagableComponent.hpp"
#include "CollisionComponent.hpp"
#include "ContactDamageComponent.hpp"

namespace gameEngine {

    class CollisionDamageSystem : virtual public ASystem {
        public:
            CollisionDamageSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<DamagableComponent>(this);
                ecs->systemAddDependances<CollisionComponent>(this);
            }

            ~CollisionDamageSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                auto &damageList = _ecs->getEntityComponent<DamagableComponent>(entity).damageList;
                auto &collisions = _ecs->getEntityComponent<CollisionComponent>(entity).collingEntitys;

                for (auto &entity2 : collisions) {
                    try {
                        auto &damages = _ecs->getEntityComponent<ContactDamageComponent>(entity2).damages;
                        for (auto &damage : damages)
                            damageList.emplace_back(damage);
                    } catch (const char *) {
                    }
                }
            }

    };
};

#endif /* !COLLISIONDAMAGESYSTEM_HPP_ */
