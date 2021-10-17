/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** NetworkSystem
*/

#ifndef NETWORKSYSTEM_HPP_
#define NETWORKSYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "NetworkIdComponent.hpp"
#include "AScene.hpp"
#include "AGame.hpp"
#include "DefaultNetworkEntity.hpp"

namespace gameEngine {

    class ISceneCommandInterpreter;

    class NetworkSystem : virtual public ASystem {
        public:
            NetworkSystem(ECS *ecs);
            ~NetworkSystem(void);

            void init(ECS *ecs, ISceneCommandInterpreter *interpreter = nullptr);
            void init(ECS *ecs);

            std::shared_ptr<AEntity> getEntityById(size_t id) const;
            std::shared_ptr<AEntity> getEntityByControlleId(const std::string &id) const;

            template<typename T, typename ...Targs>
            T& getOrCreateEntityComponentById(size_t id, Targs ...args)
            {
                auto entity = getEntityById(id);

                if (entity == nullptr)
                    entity = _ecs->addEntity<gameEngine::DefaultNetworkEntity>(id);
                if (entity->getComponent(_ecs->getComponentIndex<T>()) == nullptr) {
                    T cmp(args...);
                    _ecs->addComponents(entity, cmp);
                }
                _ecs->getEntityComponent<NetworkIdComponent>(entity).lastUpdate = 0;
                return _ecs->getEntityComponent<T>(entity);
            }

        private:
            ISceneCommandInterpreter *_interpreter = nullptr;
            void action(std::shared_ptr<AEntity> entity, float deltaTime);
            void preAction(float deltaTime);
    };
};

#endif /* !NETWORKSYSTEM_HPP_ */
