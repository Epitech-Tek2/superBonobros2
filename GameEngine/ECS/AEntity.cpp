/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** AEntity
*/

#include "AEntity.hpp"

gameEngine::AEntity::AEntity(ECS *ecs, const std::string &type) : _ecs(ecs), _type(type), _alive(true)
{
}

gameEngine::AEntity::~AEntity()
{
}

const gameEngine::Component::Bitset &gameEngine::AEntity::getComponentBitset(void) const
{
    return _compBitset;
}

void gameEngine::AEntity::addComponent(size_t index, std::shared_ptr<Component> &comp)
{
    _compList[index] = comp;
    _compBitset[index] = true;
}

void gameEngine::AEntity::delComponent(size_t index)
{
    _compList[index] = nullptr;
    _compBitset[index] = false;
}

std::shared_ptr<gameEngine::Component> gameEngine::AEntity::getComponent(size_t index) const
{
    return _compList[index];
}

gameEngine::ECS *gameEngine::AEntity::getEcs(void) const
{
    return _ecs;
}

bool gameEngine::AEntity::isAlive(void) const
{
    return _alive;
}

void gameEngine::AEntity::kill(void)
{
    _alive = false;
}

const std::string &gameEngine::AEntity::getType(void) const
{
    return _type;
}
