/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** ScriptSystem
*/

#ifndef SCRIPTSYSTEM_HPP_
#define SCRIPTSYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "ScriptComponent.hpp"
#include "Transform2DComponent.hpp"
#include "MainForceComponent.hpp"
#include "SkeletonSonsComponent.hpp"
#include "SkeletonFatherComponent.hpp"

class ScriptSystem : virtual public gameEngine::ASystem {
    public:
        ScriptSystem(gameEngine::ECS *ecs) : ASystem(ecs) {}
        ~ScriptSystem() = default;

        void init(gameEngine::ECS *ecs)
        {
            ecs->systemAddDependances<ScriptComponent>(this);
            ecs->systemAddDependances<gameEngine::Transform2DComponent>(this);
            ecs->systemAddDependances<gameEngine::MainForceComponent>(this);
        }

    protected:
    private:
        void readNext(std::shared_ptr<gameEngine::AEntity> entity, ScriptComponent &script, gameEngine::Transform2D &transform) {
            if (!script._script.size())
                return;
            if (script._scriptPos < 0 || script._scriptPos >= (int) script._script.size() - 1)
                script._scriptPos = 0;
            else
                ++script._scriptPos;
            auto it = script._script[script._scriptPos];
            if (it.first == "x")
                script.save = transform.getPosition().x;
            else if (it.first == "y")
                script.save = transform.getPosition().y;
            else if (it.first == "wait")
                script.save = it.second;
            else if (it.first == "rot")
                script.save = (int) (it.second) % 360;
            else
                std::cout << "Script Error" << std::endl;
        }
        void action(std::shared_ptr<gameEngine::AEntity> entity, float time)
        {
            static float speed = 100;
            auto &script = _ecs->getEntityComponent<ScriptComponent>(entity);
            auto &transform = _ecs->getEntityComponent<gameEngine::Transform2DComponent>(entity)._transform;
            auto &mainForce = _ecs->getEntityComponent<gameEngine::MainForceComponent>(entity);
            auto pos = transform.getPosition();

            mainForce._mainForce = {0, 0};
            if (script._scriptPos < 0)
                readNext(entity, script, transform);
            if (script._scriptPos < 0 || script._scriptPos >= (int) script._script.size())
                return;
            auto it = script._script[script._scriptPos];
            if (it.first == "x") {
                if (it.second > 0) {
                    if (it.second >= pos.x - script.save) {
                        mainForce._mainForce = {speed, 0};
                    }
                    else {
                        readNext(entity, script, transform);
                    }
                } else {
                    if (it.second <= pos.x - script.save) {
                        mainForce._mainForce = {-speed, 0};
                    }
                    else {
                        readNext(entity, script, transform);
                    }
                }
            } else if (it.first == "y") {
                if (it.second > 0) {
                    if (it.second >= pos.y - script.save) {
                        mainForce._mainForce = {0, speed};
                    }
                    else {
                        readNext(entity, script, transform);
                    }
                } else {
                    if (it.second <= pos.y - script.save) {
                        mainForce._mainForce = {0, -speed};
                    }
                    else {
                        readNext(entity, script, transform);
                    }
                }
            } else if (it.first == "wait") {
                script.save -= time;
                if (script.save <= 0)
                    readNext(entity, script, transform);
            } else if (it.first == "rot") {
                try {
                    auto &sons = _ecs->getEntityComponent<gameEngine::SkeletonSonsComponent>(entity);
                    auto son = sons.getSon("FieldOfView");
                    auto &father = _ecs->getEntityComponent<gameEngine::SkeletonFatherComponent>(son);
                    
                    float angle = (int) (it.second) % 360;
                    if (father._rotation < angle - 1)
                        father._rotation += time * 40;
                    else if (father._rotation > angle + 1)
                        father._rotation -= time * 40;
                    else
                        readNext(entity, script, transform);
                } catch (const char *str) {
                    readNext(entity, script, transform);
                }

                script.save -= time;
                if (script.save <= 0)
                    readNext(entity, script, transform);
            }

        }
};

#endif /* !SCRIPTSYSTEM_HPP_ */
