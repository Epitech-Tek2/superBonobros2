/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** AutomaticResizeSystem
*/

#ifndef AUTOMATICRESIZESYSTEM_HPP_
#define AUTOMATICRESIZESYSTEM_HPP_

#include <algorithm>
#include "ASystem.hpp"
#include "ECS.hpp"
#include "ShapeComponent.hpp"
#include "TextureComponent.hpp"
#include "Transform2DComponent.hpp"

namespace gameEngine {

    class AutomaticResizeSystem : virtual public ASystem {
        public:
            AutomaticResizeSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<ShapeComponent>(this);
                ecs->systemAddDependances<TextureComponent>(this);
                ecs->systemAddDependances<Transform2DComponent>(this);
            }

            ~AutomaticResizeSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                auto &shape = _ecs->getEntityComponent<ShapeComponent>(entity);
                TextureComponent texture = _ecs->getEntityComponent<TextureComponent>(entity);
                auto &transform = _ecs->getEntityComponent<Transform2DComponent>(entity);

                if (shape._baseOnTexture && texture._type == TextureType::FileTexture) {
                    if (shape._type == ShapeType::RectangleShape)
                        shape._rectangle = Rectangle<float>(0, 0, texture._rect.width(), texture._rect.height());
                    if (shape._type == ShapeType::CircleShape)
                        shape._circle.setRay(texture._rect.width() / 2);
                }
                transform._transform.setOrigin(shape._textureCenterRatio * Vector2<float> (texture._rect.width(), texture._rect.height()));
            }

    };
};

#endif /* !AUTOMATICRESIZESYSTEM_HPP_ */
