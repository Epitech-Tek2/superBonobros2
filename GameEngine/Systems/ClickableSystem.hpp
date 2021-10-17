/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ButtonSystem
*/

#ifndef CLICKABLESYSTEM_HPP_
#define CLICKABLESYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "AScene.hpp"
#include "AGame.hpp"
#include "ASystem.hpp"
#include "ClickableComponent.hpp"
#include "ShapeComponent.hpp"
#include "Transform2DComponent.hpp"
#include "SAT.hpp"
#include "IEvent.hpp"

namespace gameEngine {
    class ClickableSystem : public gameEngine::ASystem {
        public:
            ClickableSystem(gameEngine::ECS *ecs) : gameEngine::ASystem(ecs) {}

            void init(gameEngine::ECS *ecs)
            {
                ecs->systemAddDependances<gameEngine::ClickableComponent>(this);
                ecs->systemAddDependances<gameEngine::ShapeComponent>(this);
                ecs->systemAddDependances<gameEngine::Transform2DComponent>(this);
            }
            ~ClickableSystem(void) = default;

        private:
            void action(std::shared_ptr<gameEngine::AEntity> entity, float)
            {
                IEvent const *event = _ecs->getScene()->getGraphic()->getEvent();
                Transform2DComponent &hitBox = _ecs->getEntityComponent<gameEngine::Transform2DComponent>(entity);
                ShapeComponent &shape = _ecs->getEntityComponent<gameEngine::ShapeComponent>(entity);
                ClickableComponent &clickable = _ecs->getEntityComponent<gameEngine::ClickableComponent>(entity);

                if (SAT::collide(hitBox, shape, Vector2<float>({event->getMousePosition().first, event->getMousePosition().second}))) {
                    if (event->mouseState() == KeyState::pressed) {
                        clickable.state = ClickableComponent::MouseState::HoldClick;
                    } else if (event->mouseState() == KeyState::released) {
                        clickable.state = ClickableComponent::MouseState::Released;
                    } else
                        clickable.state = ClickableComponent::MouseState::OnButton;
                } else
                    clickable.state = ClickableComponent::MouseState::BaseState;
            }
    };
}

#endif /* !CLICKABLESYSTEM_HPP_ */