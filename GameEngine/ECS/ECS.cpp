/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ECS
*/

#include "ECS.hpp"
#include "AScene.hpp"

gameEngine::ECS::ECS(AScene *scene) : _scene(scene)
{
}

gameEngine::ECS::~ECS()
{
}

void gameEngine::ECS::delEntity(const std::shared_ptr<AEntity> entity)
{
    auto bitset = entity->getComponentBitset();
    auto nbComponents = bitset.size();

    for (std::size_t it = 0; it < nbComponents; ++it) {
        auto comp = entity->getComponent(it);
        if (comp)
            delSharedPtr(_components, comp);
    }
    for (auto system : _systems)
        system.get()->removeEntity(entity);
    delSharedPtr(_entitys, entity);
}

void gameEngine::ECS::removeDeadEntitys(void)
{
    for (auto it = _entitys.begin(); it != _entitys.end(); ++it) {
        if (!(*it)->isAlive()) {
            delEntity(*it--);
        }
    }
}

void gameEngine::ECS::update(float deltaTime)
{
    for (auto system : _systems)
        system.get()->update(deltaTime);
    removeDeadEntitys();
}

gameEngine::AScene *gameEngine::ECS::getScene(void) const
{
    return _scene;
}