/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** CheatMarks
*/

#ifndef CHEATMARKS_HPP_
#define CHEATMARKS_HPP_

#include "ECS.hpp"
#include "AScene.hpp"
#include "AEntity.hpp"

#include "Transform2DComponent.hpp"
#include "ShapeComponent.hpp"
#include "LayerComponent.hpp"
#include "TextureComponent.hpp"

#include "PhysicsComponent.hpp"
#include "CollisionComponent.hpp"

class CheatMarks : virtual public gameEngine::AEntity {
    public:
        CheatMarks(gameEngine::ECS *ecs) : AEntity(ecs, "CheatMarks")
        {
        }

        ~CheatMarks() = default;

        void init(gameEngine::ECS *ecs)
        {
            init(ecs, gameEngine::Vector2<float>(0, 0));
        }

        void init(gameEngine::ECS *ecs, const gameEngine::Vector2<float> &pos)
        {
            gameEngine::Transform2DComponent transform;
            transform._transform.setScale(0.25, 0.25);
            transform._transform.setPosition(pos);

            gameEngine::ShapeComponent shape;
            shape._baseOnTexture = true;


            gameEngine::LayerComponent layerCmp;
            shape._type = gameEngine::ShapeType::RectangleShape;
            layerCmp.layer = 9;

            gameEngine::TextureComponent texture;
            texture._type = gameEngine::TextureType::FileTexture;
            texture._index = ecs->getScene()->getGraphic()->loadTexture("assets/Generic/past_collectible.png");
            texture._rect = {0, 0, 341, 416};

            gameEngine::PhysicsComponent physics;
            gameEngine::CollisionComponent collision;

            ecs->addComponents(this, transform, shape, layerCmp, texture, physics, collision);
        }
};

#endif /* !CHEATMARKS_HPP_ */
