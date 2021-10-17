/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SkeletonSystem
*/

#ifndef SKELETONSYSTEM_HPP_
#define SKELETONSYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "SkeletonFatherComponent.hpp"
#include "SkeletonSonsComponent.hpp"
#include "Transform2DComponent.hpp"

namespace gameEngine {

    class SkeletonSystem : virtual public ASystem {
        public:
            SkeletonSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<SkeletonFatherComponent>(this);
            }

            ~SkeletonSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                auto &father = _ecs->getEntityComponent<SkeletonFatherComponent>(entity);
                auto &sons = _ecs->getEntityComponent<SkeletonSonsComponent>(father._father);

                if (!father._father->isAlive())
                    entity->kill();
                if (!entity->isAlive())
                    sons.removeSon(entity);
                try {
                    auto &sonTransform = _ecs->getEntityComponent<Transform2DComponent>(entity);
                    auto &fatherTransform = _ecs->getEntityComponent<Transform2DComponent>(father._father);

                    sonTransform._transform.setPosition(fatherTransform._transform.transformPoint(father._jointPos));
                    sonTransform._transform.setRotation(father._rotation + fatherTransform._transform.getRotation());
                } catch (const char *e) {
                }

            }

    };
};

#endif /* !SKELETONSYSTEM_HPP_ */
