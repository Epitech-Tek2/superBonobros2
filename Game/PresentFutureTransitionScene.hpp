/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** PresentFutureTransitionScene
*/

#ifndef PRESENTFUTURETRANSITION_HPP_
#define PRESENTFUTURETRANSITION_HPP_

    #include "AScene.hpp"

    #include "FutureScene.hpp"

    #include "AutomaticResizeSystem.hpp"
    #include "DrawSystem.hpp"
    #include "ButtonSystem.hpp"
    #include "ClickableSystem.hpp"

    #include "ClickableEntity.hpp"
    #include "Image.hpp"

class PresentFutureTransitionScene : public gameEngine::AScene {
    public:
        PresentFutureTransitionScene(gameEngine::AGame *game) : gameEngine::AScene(game)
        {
            getECS().addSystem<gameEngine::ClickableSystem>();
            getECS().addSystem<gameEngine::ButtonSystem>();
            getECS().addSystem<gameEngine::AutomaticResizeSystem>();
            getECS().addSystem<gameEngine::DrawSystem>();
            getECS().addEntity<Image>(gameEngine::Vector2<float>(0.0f, 0.0f), gameEngine::Rectangle<int>(0, 0, 1920, 1080), "assets/Ui/Présent- Futur_Sans_Button.png", 0U);
            getECS().addEntity<ClickableEntity>(gameEngine::Vector2<float>(1520, 939), gameEngine::Rectangle<int>(1125, 914, 714, 120), gameEngine::Color(255, 255, 255, 255), "assets/Ui/Bouton_Menu.png",
                [this](){getGame()->addScene<FutureScene>(); kill();});
            getECS().addEntity<ClickableEntity>(gameEngine::Vector2<float>(393, 939), gameEngine::Rectangle<int>(60, 914, 715, 120), gameEngine::Color(255, 255, 255, 255), "assets/Ui/Bouton_Menu.png",
                [this](){kill();});
        }
        ~PresentFutureTransitionScene() = default;
};

#endif /* !PRESENTFUTURETRANSITION_HPP_ */
