/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** TeacherBot
*/

#ifndef TEACHERBOT_HPP_
#define TEACHERBOT_HPP_

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

#include "SkeletonSonsComponent.hpp"

#include "FieldOfView.hpp"

#include "ScriptComponent.hpp"

class TeacherBot : virtual public gameEngine::AEntity {
    public:
        TeacherBot(gameEngine::ECS *ecs) : AEntity(ecs, "TeacherBot")
        {
        }

        ~TeacherBot() = default;

        void init(gameEngine::ECS *ecs)
        {
            init(ecs, gameEngine::Vector2<float>(0, 0), "", "");
        }

        void init(gameEngine::ECS *ecs, const gameEngine::Vector2<float> &pos, const std::string &texturePath, const std::string &scriptPath)
        {
            gameEngine::Transform2DComponent transform;
            transform._transform.setScale(0.16, 0.16);
            transform._transform.setPosition(pos);

            gameEngine::ShapeComponent shape;
            shape._baseOnTexture = true;


            gameEngine::LayerComponent layerCmp;
            shape._type = gameEngine::ShapeType::RectangleShape;
            layerCmp.layer = 12;

            gameEngine::TextureComponent texture;
            texture._type = gameEngine::TextureType::FileTexture;
            texture._index = ecs->getScene()->getGraphic()->loadTexture(texturePath);
            texture._rect = {0, 0, 423, 423};

            gameEngine::PhysicsComponent physics;
            gameEngine::CollisionComponent collision;

            gameEngine::GlobalMovementComponent move;
            gameEngine::ForceComponent force;
            gameEngine::MainForceComponent mainForce;

            gameEngine::SkeletonSonsComponent sons;

            ScriptComponent script;
            script._script = script.get_commands(scriptPath);

            ecs->addComponents(this, transform, shape, layerCmp, texture, physics, collision,
                move, force, mainForce, sons, script);

            auto &sksons = ecs->getEntityComponent<gameEngine::SkeletonSonsComponent>(this);
            sksons.createSon<FieldOfView>("FieldOfView",
                gameEngine::Vector2<float>((float) (texture._rect.width() - texture._rect.posX()) / 2.f,
                (float) (texture._rect.height() - texture._rect.posY()) / 2.f),
                ecs);
        }
};

#endif /* !TEACHERBOT_HPP_ */
