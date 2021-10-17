/*
** EPITECH PROJECT, 2021
** Super-Bonobross-2
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "AGame.hpp"
#include "MenuScene.hpp"

class Game : public gameEngine::AGame {
    public:
        Game(gameEngine::INetwork *socket, gameEngine::IGraphic *graphicLib) : gameEngine::AGame(socket, graphicLib)
        {
            graphicLib->setGameSize(gameEngine::Vector2<unsigned int>(1920, 1080));
            addScene<MenuScene>();
        }
        ~Game() = default;

    protected:
    private:
};

#endif /* !GAME_HPP_ */
