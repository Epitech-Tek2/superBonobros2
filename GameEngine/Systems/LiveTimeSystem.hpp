/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** LiveTimeSystem
*/

#ifndef LIVETIMESYSTEM_HPP_
#define LIVETIMESYSTEM_HPP_


#include "ASystem.hpp"
#include "ECS.hpp"
#include "LiveTimeComponent.hpp"

namespace gameEngine {

    class LiveTimeSystem : virtual public ASystem {
        public:
            LiveTimeSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<LiveTimeComponent>(this);
            }

            ~LiveTimeSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float deltaTime)
            {
                auto &liveTime = _ecs->getEntityComponent<LiveTimeComponent>(entity).liveTime;

                liveTime -= deltaTime;
                if (liveTime <= 0)
                    entity->kill();
            }
    };
};

#endif /* !LIVETIMESYSTEM_HPP_ */
