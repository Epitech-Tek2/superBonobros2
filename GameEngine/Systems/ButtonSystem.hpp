/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ButtonSystem
*/

#ifndef BUTTONSYSTEM_HPP_
#define BUTTONSYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "AScene.hpp"
#include "AGame.hpp"
#include "ASystem.hpp"
#include "ClickableComponent.hpp"
#include "ShapeComponent.hpp"
#include "Transform2DComponent.hpp"
#include "BaseColorComponent.hpp"
#include "TextureComponent.hpp"
#include "ButtonActionComponent.hpp"

namespace gameEngine {
    class ButtonSystem : public gameEngine::ASystem {
        public:
            ButtonSystem(gameEngine::ECS *ecs) : gameEngine::ASystem(ecs) {}

            void init(gameEngine::ECS *ecs)
            {
                ecs->systemAddDependances<gameEngine::ClickableComponent>(this);
                ecs->systemAddDependances<gameEngine::TextureComponent>(this);
                ecs->systemAddDependances<gameEngine::ShapeComponent>(this);
                ecs->systemAddDependances<gameEngine::Transform2DComponent>(this);
                ecs->systemAddDependances<gameEngine::BaseColorComponent>(this);
                ecs->systemAddDependances<gameEngine::ButtonActionComponent>(this);
            }
            ~ButtonSystem(void) = default;

        private:
            void action(std::shared_ptr<gameEngine::AEntity> entity, float)
            {
                Color const &baseColor = _ecs->getEntityComponent<gameEngine::BaseColorComponent>(entity)._color;
                Color &color = _ecs->getEntityComponent<gameEngine::TextureComponent>(entity)._color;
                ClickableComponent::MouseState const state = _ecs->getEntityComponent<gameEngine::ClickableComponent>(entity).state;
                ButtonActionComponent &action = _ecs->getEntityComponent<gameEngine::ButtonActionComponent>(entity);

                short red = 0;
                short green = 0;
                short blue = 0;

                switch (state) {
                    case ClickableComponent::MouseState::OnButton:
                        red = baseColor.red - 30;
                        green = baseColor.green - 30;
                        blue = baseColor.blue - 30;
                        color.red = (red < 0 ? 0:red);
                        color.green = (green < 0 ? 0:green);
                        color.blue = (blue < 0 ? 0:blue);
                        break;
                    case ClickableComponent::MouseState::HoldClick:
                        red = baseColor.red - 60;
                        green = baseColor.green - 60;
                        blue = baseColor.blue - 60;
                        color.red = (red < 0 ? 0:red);
                        color.green = (green < 0 ? 0:green);
                        color.blue = (blue < 0 ? 0:blue);
                        break;
                    case ClickableComponent::MouseState::Released:
                        action._action();
                        break;
                    default:
                        color = baseColor;
                        break;
                }
            }
    };
}

#endif /* !BUTTONSYSTEM_HPP_ */