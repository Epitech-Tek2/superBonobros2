/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SkeletonSonsComponent
*/

#include "SkeletonSonsComponent.hpp"

gameEngine::SkeletonSonsComponent::SkeletonSonsComponent()
{
}

gameEngine::SkeletonSonsComponent::~SkeletonSonsComponent()
{
}

bool gameEngine::SkeletonSonsComponent::haveSon(const std::string &sonName)
{
    return _sonsList.count(sonName);
}

void gameEngine::SkeletonSonsComponent::removeSon(const std::string &sonName)
{
    if (_sonsList.count(sonName))
        _sonsList.erase(sonName);
}

void gameEngine::SkeletonSonsComponent::removeSon(std::shared_ptr<AEntity> son)
{
    for (auto it : _sonsList) {
        if (it.second == son) {
            _sonsList.erase(it.first);
            return;
        }
    }
}

std::shared_ptr<gameEngine::AEntity> gameEngine::SkeletonSonsComponent::getSon(const std::string &sonName)
{
    if (_sonsList.count(sonName))
        return _sonsList.at(sonName);
    return nullptr;
}

