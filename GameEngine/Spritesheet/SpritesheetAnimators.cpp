/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SpritesheetAnimators
*/

#include "SpritesheetAnimators.hpp"

/* try cath std::out_of_range*/

gameEngine::SpritesheetAnimators::SpritesheetAnimators()
{
}

gameEngine::SpritesheetAnimators::~SpritesheetAnimators()
{
}

void gameEngine::SpritesheetAnimators::addAimation(const std::string &animationName, const SpritesheetAnimation &animation)
{
    if (animationName.empty())
        return;
    _animations.emplace(animationName, animation);
}

void gameEngine::SpritesheetAnimators::playAnimation(const std::string &animationName)
{
    if (animationName.empty()) {
        if (!_currentAnimation.empty()) {
            _animations.at(_currentAnimation).reset();
            _currentAnimation.clear();
        }
        return;
    }
    if (animationName != _currentAnimation && _animations.count(animationName)) {
        if (!_currentAnimation.empty())
            _animations.at(_currentAnimation).reset();
        _currentAnimation = animationName;
    }
}

void gameEngine::SpritesheetAnimators::update(float deltaTime)
{
    if (!_currentAnimation.empty())
        _animations.at(_currentAnimation).update(deltaTime);
}

void gameEngine::SpritesheetAnimators::appyOnTexture(Rectangle<int> &rect) const
{
    if (!_currentAnimation.empty())
        rect = _animations.at(_currentAnimation).getRectangle();
}

