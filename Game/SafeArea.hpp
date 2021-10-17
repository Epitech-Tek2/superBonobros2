/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** SafeArea
*/

#ifndef SAFEAREA_HPP_
#define SAFEAREA_HPP_

#include "ECS.hpp"
#include "AScene.hpp"
#include "AEntity.hpp"

#include "Transform2DComponent.hpp"
#include "ShapeComponent.hpp"

#include "PhysicsComponent.hpp"
#include "CollisionComponent.hpp"

class SafeArea : virtual public gameEngine::AEntity {
    public:
        SafeArea(gameEngine::ECS *ecs) : AEntity(ecs, "SafeArea")
        {
        }

        ~SafeArea() = default;

        void init(gameEngine::ECS *ecs)
        {
            init(ecs, gameEngine::Vector2<float>(0, 0));
        }

        void init(gameEngine::ECS *ecs, const gameEngine::Vector2<float> &pos)
        {
            gameEngine::Transform2DComponent transform;
            transform._transform.setScale(1, 1);
            transform._transform.setPosition(pos);

            gameEngine::ShapeComponent shape;
            shape._type = gameEngine::ShapeType::RectangleShape;
            shape._baseOnTexture = true;


            gameEngine::PhysicsComponent physics;
            gameEngine::CollisionComponent collision;

            ecs->addComponents(this, transform, shape, physics, collision);
        }

    protected:
    private:
};

#endif /* !SAFEAREA_HPP_ */
