/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SpawnerSystem
*/

#ifndef SPAWNERSYSTEM_HPP_
#define SPAWNERSYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "Transform2DComponent.hpp"
#include "SpawnerComponent.hpp"

#include "Error.hpp"

namespace gameEngine {

    class SpawnerSystem : virtual public ASystem {
        public:
            SpawnerSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<Transform2DComponent>(this);
                ecs->systemAddDependances<SpawnerComponent>(this);
            }

            ~SpawnerSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                auto &transform = _ecs->getEntityComponent<Transform2DComponent>(entity);
                auto &spawner = _ecs->getEntityComponent<SpawnerComponent>(entity);

                for (auto &tag : spawner.entityTagsList) {
                    try {
                        std::shared_ptr<AEntity> entity2 = spawner.entityFactory.create(tag, _ecs);
                        if (spawner.spawnOnMe) {
                            auto &transform2 = _ecs->getEntityComponent<Transform2DComponent>(entity2);
                            transform2._transform.setPosition(transform._transform.getPosition());
                        }
                    } catch (const Error &e) {
                        continue;
                    } catch (const char *e) {
                        continue;
                    }
                }
                spawner.entityTagsList.clear();
            }

    };
};

#endif /* !SPAWNERSYSTEM_HPP_ */
