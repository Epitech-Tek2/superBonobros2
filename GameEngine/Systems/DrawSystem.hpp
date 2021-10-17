/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** DrawSystem
*/

#ifndef DRAWSYSTEM_HPP_
#define DRAWSYSTEM_HPP_

#include <iostream>
#include <memory>

#include "ASystem.hpp"
#include "ECS.hpp"
#include "Transform2DComponent.hpp"
#include "LayerComponent.hpp"
#include "AScene.hpp"

namespace gameEngine {

    class DrawSystem : virtual public ASystem {
        public:
            DrawSystem(ECS *ecs) : ASystem(ecs, 0.05) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<Transform2DComponent, LayerComponent>(this);
            }

            ~DrawSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                _ecs->getScene()->getGraphic()->draw(entity);
            }

            void postAction(float)
            {
                _ecs->getScene()->getGraphic()->updateScreen();
            }

            void preAction(float)
            {
                try {
                    std::sort(_entitys.begin(), _entitys.end(), [this]
                        (std::shared_ptr<AEntity> entity1, std::shared_ptr<AEntity> entity2)
                        {
                            auto layer1 = _ecs->getEntityComponent<LayerComponent>(entity1).layer;
                            auto layer2 = _ecs->getEntityComponent<LayerComponent>(entity2).layer;

                            return layer1 < layer2;
                        });
                } catch (const char *e) {
                }
            }
    };
};

#endif /* !DRAWSYSTEM_HPP_ */
