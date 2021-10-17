/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** AEntity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <memory>
#include <vector>
#include "TypeIndexer.hpp"
#include "Component.hpp"

namespace gameEngine {

    class ECS;

    class AEntity {
        public:
            AEntity(ECS *ecs, const std::string &type);

            virtual ~AEntity();

            const Component::Bitset &getComponentBitset(void) const;

            //Warning Using addComponent or DelComponent is explicitly forbitten. Please use scene call.
            void addComponent(size_t index, std::shared_ptr<Component> &comp);
            void delComponent(size_t index);
            bool isAlive(void) const;
            void kill(void);
            virtual void init(ECS *ecs) = 0;
            const std::string &getType(void) const;

            std::shared_ptr<gameEngine::Component> getComponent(size_t index) const;
            ECS *getEcs(void) const;

        private:
            ECS *_ecs;
            std::string _type;
            bool _alive;
            Component::List _compList{};
            Component::Bitset _compBitset;
    };

};

#endif /* !ENTITY_HPP_ */
