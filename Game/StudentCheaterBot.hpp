/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** StudentCheaterBot
*/

#ifndef STUDENTCHEATERBOT_HPP_
#define STUDENTCHEATERBOT_HPP_

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

#include "ScriptComponent.hpp"

#include "SafeArea.hpp"

class StudentCheaterBot : virtual public gameEngine::AEntity {
    public:
        StudentCheaterBot(gameEngine::ECS *ecs) : AEntity(ecs, "StudentCheaterBot")
        {
        }

        ~StudentCheaterBot() = default;

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
            //shape._rectangle = {112, 112, 200, 200};

            gameEngine::PhysicsComponent physics;
            gameEngine::CollisionComponent collision;

            gameEngine::GlobalMovementComponent move;
            gameEngine::ForceComponent force;
            gameEngine::MainForceComponent mainForce;

            ScriptComponent script;
            script._script = script.get_commands(scriptPath);

            ecs->addComponents(this, transform, shape, layerCmp, texture, physics, collision,
                move, force, mainForce, script);

            _safeArea = ecs->addEntity<SafeArea>(pos);
        }

        inline bool getImmuneStatus(void)
        {
            return _immune;
        }

        inline void setImmuneStatus(bool status)
        {
            _immune = status;
        }

        inline bool getReadMarksStatus(void)
        {
            return _hasReadMarks;
        }

        inline void setReadsMarksStatus(bool status)
        {
            _hasReadMarks = status;
        }

        inline bool getHasLooseStatus(void)
        {
            return _hasLoose;
        }

        inline void setHasLooseStatus(bool status)
        {
            _hasLoose = status;
        }

    protected:
    private:
        bool _hasReadMarks = false;
        bool _immune = false;
        bool _hasLoose = false;
    public:
        std::shared_ptr<SafeArea> _safeArea;
};
#endif /* !STUDENTCHEATERBOT_HPP_ */
