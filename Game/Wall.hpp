/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Wall
*/

#ifndef WALL_HPP_
#define WALL_HPP_

#include "AEntity.hpp"
#include "AScene.hpp"
#include "ECS.hpp"

#include "Transform2DComponent.hpp"
#include "ShapeComponent.hpp"

#include "PhysicsComponent.hpp"
#include "CollisionComponent.hpp"


class Wall : virtual public gameEngine::AEntity {
    public:
        Wall(gameEngine::ECS *ecs) : AEntity(ecs, "Wall")
        {
        }

        ~Wall() = default;

        void init(gameEngine::ECS *ecs)
        {
            init(ecs, gameEngine::Vector2<float>(0, 0), gameEngine::Vector2<float>(1, 1));
        }

        void init(gameEngine::ECS *ecs, const gameEngine::Vector2<float> &pos, const gameEngine::Vector2<float> &size)
        {
            gameEngine::Transform2DComponent transform;
            gameEngine::ShapeComponent shape;
            transform._transform.setScale(1, 1);
            transform._transform.setPosition(pos);

            shape._type = gameEngine::ShapeType::RectangleShape;
            shape._rectangle = {0, 0, size.x, size.y};

            gameEngine::PhysicsComponent physics;
            physics.isRigidBody = true;
            
            gameEngine::CollisionComponent collision;

            ecs->addComponents(this, transform, shape, physics, collision);
        }

        protected:
        private:
    };

#endif /* !WALL_HPP_ */
