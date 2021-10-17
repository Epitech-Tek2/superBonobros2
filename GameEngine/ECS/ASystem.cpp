/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ASystem
*/

#include <algorithm>
#include "ASystem.hpp"
#include "AEntity.hpp"

#include <iostream>

gameEngine::ASystem::ASystem(ECS *ecs, float reafreshCycle) : _ecs(ecs), _reafreshCycle(reafreshCycle)
{
    if (_reafreshCycle < 0)
        _reafreshCycle = 0;
}

gameEngine::ASystem::~ASystem()
{
}

void gameEngine::ASystem::update(float deltaTime)
{
    if (_reafreshCycle == 0) {
        preAction(deltaTime);
        for (auto it : _entitys)
            action(it, deltaTime);
        postAction(deltaTime);
    } else {
        _leftover += deltaTime;
        for (; _leftover >= _reafreshCycle; _leftover -= _reafreshCycle) {
            preAction(deltaTime);
            for (auto it : _entitys)
                action(it, _reafreshCycle);
            postAction(deltaTime);
        }
    }
}

void gameEngine::ASystem::mayAddEntity(const std::shared_ptr<AEntity> &entity)
{
    if (bitsetMatch(entity->getComponentBitset(), _compBitset)
        && std::find(_entitys.begin(), _entitys.end(), entity) == _entitys.end())
        _entitys.push_back(entity);
}

void gameEngine::ASystem::mayDelEntity(const std::shared_ptr<AEntity> &entity)
{
    auto it = std::find(_entitys.begin(), _entitys.end(), entity);

    if (!bitsetMatch(entity->getComponentBitset(), _compBitset)
        && it != _entitys.end())
        _entitys.erase(it);
}

void gameEngine::ASystem::signatureSetBit(std::size_t index, bool state)
{
    _compBitset[index] = state;
}

void gameEngine::ASystem::removeEntity(const std::shared_ptr<AEntity> &entity)
{
    auto it = std::find(_entitys.begin(), _entitys.end(), entity);

    if (it != _entitys.end())
        _entitys.erase(it);
}

void gameEngine::ASystem::preAction(float deltaTime)
{
    (void) deltaTime;
}

void gameEngine::ASystem::postAction(float deltaTime)
{
    (void) deltaTime;
}

gameEngine::ECS *gameEngine::ASystem::getECS(void) const
{
    return _ecs;
}