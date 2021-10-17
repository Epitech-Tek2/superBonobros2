/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** Drone
*/

#ifndef DRONE_HPP_
#define DRONE_HPP_


#include "ECS.hpp"
#include "AScene.hpp"
#include "AEntity.hpp"

#include "Transform2DComponent.hpp"
#include "ShapeComponent.hpp"
#include "LayerComponent.hpp"
#include "TextureComponent.hpp"

#include "PhysicsComponent.hpp"
#include "CollisionComponent.hpp"

#include "GlobalMovementComponent.hpp"
#include "ForceComponent.hpp"
#include "MainForceComponent.hpp"

#include "ClickableEntity.hpp"
#include "SkeletonSonsComponent.hpp"

#include "FieldOfView.hpp"

class Drone : virtual public gameEngine::AEntity {
    public:
        Drone(gameEngine::ECS *ecs) : AEntity(ecs, "Drone")
        {
        }

        ~Drone() = default;

        void init(gameEngine::ECS *ecs)
        {
            init(ecs, gameEngine::Vector2<float>(0, 0));
        }

        void init(gameEngine::ECS *ecs, const gameEngine::Vector2<float> &pos)
        {
            gameEngine::Transform2DComponent transform;
            transform._transform.setScale(0.4, 0.4);
            transform._transform.setPosition(pos);

            gameEngine::ShapeComponent shape;


            gameEngine::LayerComponent layerCmp;
            shape._type = gameEngine::ShapeType::RectangleShape;
            layerCmp.layer = 12;

            gameEngine::TextureComponent texture;
            texture._type = gameEngine::TextureType::FileTexture;
            texture._index = ecs->getScene()->getGraphic()->loadTexture("assets/Future/Drone_Rond_Gris.png");
            texture._rect = {0, 0, 423, 423};
            shape._rectangle = {112, 112, 200, 200};

            gameEngine::PhysicsComponent physics;
            physics.isRigidBody = true;
            gameEngine::CollisionComponent collision;

            gameEngine::GlobalMovementComponent move;
            gameEngine::ForceComponent force;
            gameEngine::MainForceComponent mainForce;

            gameEngine::SkeletonSonsComponent sons;

            gameEngine::ClickableComponent clickable;

            ecs->addComponents(this, transform, shape, layerCmp, texture, physics, collision,
                move, force, mainForce, sons, clickable);

            auto &sksons = ecs->getEntityComponent<gameEngine::SkeletonSonsComponent>(this);
            sksons.createSon<FieldOfView>("FieldOfView",
                gameEngine::Vector2<float>((float) (texture._rect.width() - texture._rect.posX()) / 2.f,
                (float) (texture._rect.height() - texture._rect.posY()) / 2.f),
                ecs, gameEngine::Vector2<float>(0, 0), gameEngine::Vector2<float>(1.2, 1.2));
        }
};
#endif /* !DRONE_HPP_ */
