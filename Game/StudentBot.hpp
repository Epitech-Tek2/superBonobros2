/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** StudentBot
*/

#ifndef STUDENTBOT_HPP_
#define STUDENTBOT_HPP_

#include "ECS.hpp"
#include "AScene.hpp"
#include "AEntity.hpp"

#include "Transform2DComponent.hpp"
#include "ShapeComponent.hpp"
#include "LayerComponent.hpp"
#include "TextureComponent.hpp"

#include "PhysicsComponent.hpp"
#include "CollisionComponent.hpp"

class StudentBot : virtual public gameEngine::AEntity {
    public:
        StudentBot(gameEngine::ECS *ecs) : AEntity(ecs, "StudentBot")
        {
        }

        ~StudentBot() = default;

        void init(gameEngine::ECS *ecs)
        {
            init(ecs, gameEngine::Vector2<float>(0, 0), "");
        }

        void init(gameEngine::ECS *ecs, const gameEngine::Vector2<float> &pos, const std::string &texturePath)
        {
            gameEngine::Transform2DComponent transform;
            transform._transform.setScale(0.16, 0.16);
            transform._transform.setPosition(pos);

            gameEngine::ShapeComponent shape;
            shape._baseOnTexture = true;

            gameEngine::LayerComponent layerCmp;
            shape._type = gameEngine::ShapeType::RectangleShape;
            layerCmp.layer = 9;

            gameEngine::TextureComponent texture;
            texture._type = gameEngine::TextureType::FileTexture;
            texture._index = ecs->getScene()->getGraphic()->loadTexture(texturePath);
            texture._rect = {0, 0, 423, 423};
            shape._rectangle = {112, 112, 200, 200};

            gameEngine::PhysicsComponent physics;
            physics.isRigidBody = true;
            gameEngine::CollisionComponent collision;

            ecs->addComponents(this, transform, shape, layerCmp, texture, physics, collision);
        }
};

#endif /* !STUDENTBOT_HPP_ */
