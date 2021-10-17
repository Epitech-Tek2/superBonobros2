/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** AScene
*/

#include "AScene.hpp"
#include "IGraphic.hpp"
#include "AGame.hpp"

gameEngine::AScene::AScene(AGame *game) : _game(game), _ecs(this), _alive(1)
{
}

gameEngine::AScene::~AScene()
{
}

void gameEngine::AScene::update(float deltaTime)
{
    _ecs.update(deltaTime);
}

gameEngine::AGame *gameEngine::AScene::getGame(void) const
{
    return _game;
}

gameEngine::IGraphic *gameEngine::AScene::getGraphic(void) const
{
    return _game->_graphicLib;
}

gameEngine::ECS &gameEngine::AScene::getECS(void)
{
    return _ecs;
}

void gameEngine::AScene::kill(void)
{
    _alive = 0;
}

bool gameEngine::AScene::isAlive(void)
{
    return _alive;
}