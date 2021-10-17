/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** WallForceSystem
*/

#ifndef WALLFORCESYSTEM_HPP_
#define WALLFORCESYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "PhysicsComponent.hpp"
#include "ForceComponent.hpp"
#include "CollisionComponent.hpp"
#include "Transform2DComponent.hpp"

namespace gameEngine {

    class WallForceSystem : virtual public ASystem {
        public:
            WallForceSystem(ECS *ecs, float wallpushForce = 10) : ASystem(ecs), _wallPushForce(wallpushForce) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<PhysicsComponent>(this);
                ecs->systemAddDependances<ForceComponent>(this);
                ecs->systemAddDependances<CollisionComponent>(this);
                ecs->systemAddDependances<Transform2DComponent>(this);
            }

            ~WallForceSystem(void) = default;

        protected:
        private:
            const float _wallPushForce;
            void action(std::shared_ptr<AEntity> entity, float)
            {
                auto &physics = _ecs->getEntityComponent<PhysicsComponent>(entity);
                auto &forces = _ecs->getEntityComponent<ForceComponent>(entity)._forceList;
                auto &collision = _ecs->getEntityComponent<CollisionComponent>(entity);
                auto pos1 = _ecs->getEntityComponent<Transform2DComponent>(entity)._transform.getPosition();

                if (!physics.isRigidBody)
                    return;
                for (auto &entity2 : collision.collingEntitys) {
                    auto &physics2 = _ecs->getEntityComponent<PhysicsComponent>(entity2);
                    auto pos2 = _ecs->getEntityComponent<Transform2DComponent>(entity2)._transform.getPosition();
                    if (!physics2.isRigidBody)
                        continue;
                    for (auto &force : forces) {
                        if (pos2.x > pos1.x) {
                            force.x = -_wallPushForce;
                        }
                        if (pos2.x < pos1.x) {
                            force.x = _wallPushForce;
                        }
                        if (pos2.y > pos1.y) {
                            force.y = -_wallPushForce;
                        }
                        if (pos2.y < pos1.y) {
                            force.y = _wallPushForce;
                        }
                    }
                }
            }
    };
};

#endif /* !WALLFORCESYSTEM_HPP_ */
