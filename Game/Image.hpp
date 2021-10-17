/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** Image
*/

#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include "ECS.hpp"
#include "AScene.hpp"
#include "AEntity.hpp"

#include "Transform2DComponent.hpp"
#include "ShapeComponent.hpp"
#include "LayerComponent.hpp"
#include "TextureComponent.hpp"

class Image : virtual public gameEngine::AEntity {
    public:
        Image(gameEngine::ECS *ecs) : AEntity(ecs, "Image")
        {
        }

        ~Image() = default;

        void init(gameEngine::ECS *ecs)
        {
            init(ecs, gameEngine::Vector2<float>(0, 0), gameEngine::Rectangle<int>(0, 0, 1920, 1080), "", 0);
        }

                void init(gameEngine::ECS *ecs, gameEngine::Vector2<float> position, gameEngine::Rectangle<int> const &rect, std::string const &texturePath, int lay)
                {
                    gameEngine::TextureComponent texture;
                    texture._rect = rect;
                    texture._type = gameEngine::TextureType::FileTexture;
                    texture._index = ecs->getScene()->getGraphic()->loadTexture(texturePath);

                    gameEngine::ShapeComponent shape;
                    shape._type = gameEngine::ShapeType::RectangleShape;
                    shape._baseOnTexture = true;

                    gameEngine::Transform2DComponent transform;
                    transform._transform.setScale(1, 1);
                    transform._transform.setPosition(position + (gameEngine::Vector2<float>(rect.width(), rect.height()) / 2.0f));
                    gameEngine::LayerComponent layer;
                    layer.layer = lay;
                    ecs->addComponents(this, texture, shape, transform, layer);
                }

    protected:
    private:
};

#endif /* !IMAGE_HPP_ */
