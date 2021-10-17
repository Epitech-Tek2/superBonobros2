/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** TextSystem
*/

#ifndef TEXTSYSTEM_HPP_
#define TEXTSYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "TextComponent.hpp"
#include "Transform2DComponent.hpp"
#include "AScene.hpp"


namespace gameEngine {

    class TextSystem : virtual public ASystem {
        public:
            TextSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<Transform2DComponent>(this);
                ecs->systemAddDependances<TextComponent>(this);
            }

            ~TextSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                _ecs->getScene()->getGraphic()->drawText(entity);
            }
    };
};

#endif /* !TEXTSYSTEM_HPP_ */

