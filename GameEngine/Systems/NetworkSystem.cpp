/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** NetworkSystem
*/

#include "NetworkSystem.hpp"
#include "ISceneCommandInterpreter.hpp"
#include "NetworkControlledIdComponent.hpp"

gameEngine::NetworkSystem::NetworkSystem(ECS *ecs)
    : ASystem(ecs)
{
}

gameEngine::NetworkSystem::~NetworkSystem(void)
{
}


void gameEngine::NetworkSystem::init(ECS *)
{
    throw (std::string("Invalid usage of NetworkSystem"));
}

void gameEngine::NetworkSystem::init(ECS *ecs, ISceneCommandInterpreter *interpreter)
{
    _interpreter = interpreter;
    _interpreter->setSystem(this);
    ecs->systemAddDependances<NetworkIdComponent>(this);
}

void gameEngine::NetworkSystem::action(std::shared_ptr<AEntity> entity, float deltaTime)
{
    (void) entity;
    (void) deltaTime;
}

void gameEngine::NetworkSystem::preAction(float deltaTime)
{
    (void) deltaTime;
    std::vector<std::string> vec;

    while (_ecs->getScene()->getGame()->popCommand(vec) && _interpreter->execCommand(vec));
}

std::shared_ptr<gameEngine::AEntity> gameEngine::NetworkSystem::getEntityById(size_t id) const
{
    auto it = std::find_if(_entitys.begin(), _entitys.end(), [&](std::shared_ptr<AEntity> entity)
    {
        return _ecs->getEntityComponent<NetworkIdComponent>(entity).id == id;
    });
    if (it != _entitys.end())
        return *it;
    return nullptr;
}

std::shared_ptr<gameEngine::AEntity> gameEngine::NetworkSystem::getEntityByControlleId(const std::string &id) const
{
    auto it = std::find_if(_entitys.begin(), _entitys.end(), [&](std::shared_ptr<AEntity> entity)
    {
        try {
            return _ecs->getEntityComponent<NetworkControlledIdComponent>(entity).id == id;
        } catch (const char *e) {
        }
        return false;
    });
    if (it != _entitys.end())
        return *it;
    return nullptr;
}