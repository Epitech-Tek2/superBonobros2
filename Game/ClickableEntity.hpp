/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ClickableEntity
*/

#ifndef CLICKABLEENTITY_HPP_
    #define CLICKABLEENTITY_HPP_
    #include "AEntity.hpp"
    #include "AScene.hpp"
    #include "ECS.hpp"
    #include "ClickableComponent.hpp"
    #include "Transform2DComponent.hpp"
    #include "ShapeComponent.hpp"
    #include "LayerComponent.hpp"
    #include "TextureComponent.hpp"
    #include "BaseColorComponent.hpp"
    #include "ButtonActionComponent.hpp"

class ClickableEntity : public gameEngine::AEntity {
    public:
        ClickableEntity(gameEngine::ECS *ecs) : AEntity(ecs, "clickable") {}
        ~ClickableEntity() = default;

        void init(gameEngine::ECS *ecs)
        {
            gameEngine::ClickableComponent component;
            ecs->addComponents(this, component);
        }

        void init(gameEngine::ECS *ecs, gameEngine::Rectangle<float> rect, gameEngine::Color color, std::function<void(void)> function)
        {
            gameEngine::ShapeComponent shape;
            shape._type = gameEngine::ShapeType::RectangleShape;
            shape._rectangle.setPosition({0, 0});
            shape._rectangle.setWidth(rect.width());
            shape._rectangle.setHeight(rect.height());
            shape._baseOnTexture = true;

            gameEngine::Transform2DComponent transform;
            transform._transform.setScale(1, 1);
            transform._transform.setPosition(rect.posX(), rect.posY());

            gameEngine::TextureComponent texture;
            texture._type = gameEngine::TextureType::ColorTexture;
            texture._color = color;

            gameEngine::BaseColorComponent baseColor;
            baseColor._color = color;

            gameEngine::ClickableComponent clickable;

            gameEngine::LayerComponent layer;
            layer.layer = 100;

            gameEngine::ButtonActionComponent action;
            action._action = function;

            ecs->addComponents(this, clickable, transform, shape, texture, baseColor, layer, action);
        }

        void init(gameEngine::ECS *ecs, gameEngine::Vector2<float> pos, gameEngine::Rectangle<float> rect, gameEngine::Color color, const std::string &texturePath, std::function<void(void)> function)
        {
            gameEngine::ShapeComponent shape;
            shape._type = gameEngine::ShapeType::RectangleShape;

            shape._baseOnTexture = true;

            gameEngine::Transform2DComponent transform;
            transform._transform.setScale(1, 1);
            transform._transform.setPosition(pos);

            gameEngine::TextureComponent texture;
            texture._type = gameEngine::TextureType::FileTexture;
            texture._index = ecs->getScene()->getGraphic()->loadTexture(texturePath);
            texture._color = color;
            texture._rect = rect;

            gameEngine::BaseColorComponent baseColor;
            baseColor._color = color;

            gameEngine::ClickableComponent clickable;

            gameEngine::LayerComponent layer;
            layer.layer = 100;

            gameEngine::ButtonActionComponent action;
            action._action = function;

            ecs->addComponents(this, clickable, transform, shape, texture, baseColor, layer, action);
        }

    protected:
    private:
};

#endif /* !CLICKABLEENTITY_HPP_ */