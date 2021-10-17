/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** MainForceSystem
*/

#ifndef MAINFORCESYSTEM_HPP_
#define MAINFORCESYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "ForceComponent.hpp"
#include "MainForceComponent.hpp"

namespace gameEngine {

    class MainForceSystem : virtual public ASystem {
        public:
            MainForceSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<ForceComponent>(this);
                ecs->systemAddDependances<MainForceComponent>(this);
            }

            ~MainForceSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                auto &force = _ecs->getEntityComponent<ForceComponent>(entity)._forceList;
                auto &mainforce = _ecs->getEntityComponent<MainForceComponent>(entity)._mainForce;
                force.push_back(mainforce);
            }
    };
};

#endif /* !MAINFORCESYSTEM_HPP_ */
