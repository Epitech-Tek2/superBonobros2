/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** DefaultNetworkEntity
*/

#ifndef DEFAULTNETWORKENTITY_HPP_
#define DEFAULTNETWORKENTITY_HPP_

#include "AEntity.hpp"
#include "AScene.hpp"
#include "ECS.hpp"
#include "NetworkIdComponent.hpp"

namespace gameEngine {

    class DefaultNetworkEntity : virtual public AEntity {
        public:
            DefaultNetworkEntity(ECS *ecs) : AEntity(ecs, "DefaultNetwork") {}

            void init(ECS *ecs)
            {
                NetworkIdComponent network;
                ecs->addComponents(this, network);
            }

            void init(ECS *ecs, int id)
            {
                NetworkIdComponent network;
                network.id = id;
                ecs->addComponents(this, network);
            }

            ~DefaultNetworkEntity() = default;

        protected:
        private:
    };

};

#endif /* !DEFAULTNETWORKENTITY_HPP_ */
