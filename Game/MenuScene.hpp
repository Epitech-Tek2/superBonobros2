/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** MenuScene
*/

#ifndef MENUSCENE_HPP_
    #define MENUSCENE_HPP_
    #include "AScene.hpp"

    #include "PastScene.hpp"

    #include "AutomaticResizeSystem.hpp"
    #include "DrawSystem.hpp"
    #include "ButtonSystem.hpp"
    #include "ClickableSystem.hpp"

    #include "ClickableEntity.hpp"
    #include "Image.hpp"

class MenuScene : public gameEngine::AScene {
    public:
        MenuScene(gameEngine::AGame *game) : gameEngine::AScene(game)
        {
            getECS().addSystem<gameEngine::ClickableSystem>();
            getECS().addSystem<gameEngine::ButtonSystem>();
            getECS().addSystem<gameEngine::AutomaticResizeSystem>();
            getECS().addSystem<gameEngine::DrawSystem>();
            getECS().addEntity<Image>(gameEngine::Vector2<float>(0.0f, 0.0f), gameEngine::Rectangle<int>(0, 0, 1920, 1080), "assets/Ui/MainMenu.png", 0U);
            getECS().addEntity<ClickableEntity>(gameEngine::Vector2<float>(970, 491), gameEngine::Rectangle<int>(547, 164, 714, 120), gameEngine::Color(255, 255, 255, 255), "assets/Ui/Bouton_Menu.png",
                [this](){getGame()->addScene<PastScene>();});
            getECS().addEntity<ClickableEntity>(gameEngine::Vector2<float>(970, 660), gameEngine::Rectangle<int>(570, 526, 715, 120), gameEngine::Color(255, 255, 255, 255), "assets/Ui/Bouton_Menu.png",
                [this](){getGame()->kill();});
        }
        ~MenuScene() = default;
};

#endif /* !MENUSCENE_HPP_ */