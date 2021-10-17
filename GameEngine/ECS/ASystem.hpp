/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ASystem
*/

#ifndef ASYSTEM_HPP_
#define ASYSTEM_HPP_

#include <vector>
#include "Component.hpp"

namespace gameEngine {

    class AEntity;
    class ECS;

    class ASystem {
        public:

            ASystem(ECS *ecs, float reafreshCycle = 0);
            virtual ~ASystem();
            void update(float deltaTime);
            void mayAddEntity(const std::shared_ptr<AEntity> &entity);
            void mayDelEntity(const std::shared_ptr<AEntity> &entity);
            void removeEntity(const std::shared_ptr<AEntity> &entity);
            void signatureSetBit(std::size_t index, bool state);
            ECS *getECS(void) const;
            virtual void init(ECS *ecs) = 0;

        protected:
            ECS *_ecs;
            virtual void preAction(float deltaTime);
            virtual void postAction(float deltaTime);
        private:
            float _reafreshCycle = 0;
            float _leftover = 0;

        protected:
            Component::Bitset _compBitset;
            std::vector<std::shared_ptr<AEntity>> _entitys;

            virtual void action(std::shared_ptr<AEntity>, float deltaTime) = 0;
    };

};

#endif /* !ASYSTEM_HPP_ */
