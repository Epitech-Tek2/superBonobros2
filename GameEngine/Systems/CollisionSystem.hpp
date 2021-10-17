/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** CollisionSystem
*/

#ifndef COLLISIONSYSTEM_HPP_
#define COLLISIONSYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "Transform2DComponent.hpp"
#include "ShapeComponent.hpp"
#include "PhysicsComponent.hpp"
#include "CollisionComponent.hpp"
#include "SAT.hpp"

namespace gameEngine {

    class CollisionSystem : virtual public ASystem {
        public:
            CollisionSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<Transform2DComponent>(this);
                ecs->systemAddDependances<ShapeComponent>(this);
                ecs->systemAddDependances<PhysicsComponent>(this);
                ecs->systemAddDependances<CollisionComponent>(this);
            }

            ~CollisionSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                auto &transform1 = _ecs->getEntityComponent<Transform2DComponent>(entity);
                auto &shape1 = _ecs->getEntityComponent<ShapeComponent>(entity);
                auto &collision = _ecs->getEntityComponent<CollisionComponent>(entity);

                collision.collingEntitys.clear();

                for (auto entity2 : _entitys) {
                    if (entity2 == entity)
                        continue;
                    auto transform2 = _ecs->getEntityComponent<Transform2DComponent>(entity2);
                    auto shape2 = _ecs->getEntityComponent<ShapeComponent>(entity2);
                    if (SAT::collide(transform1, shape1, transform2, shape2)) {
                        collision.collingEntitys.push_back(entity2);
                    }
                }
            }
    };
};

#endif /* !COLLISIONSYSTEM_HPP_ */
