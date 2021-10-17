/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** PastPresentTransitionScene
*/

#ifndef PASTPRESENTTRANSITIONSCENE_HPP_
#define PASTPRESENTTRANSITIONSCENE_HPP_

    #include "AScene.hpp"

    #include "PresentScene.hpp"

    #include "AutomaticResizeSystem.hpp"
    #include "DrawSystem.hpp"
    #include "ButtonSystem.hpp"
    #include "ClickableSystem.hpp"

    #include "ClickableEntity.hpp"
    #include "Image.hpp"

class PastPresentTransitionScene : public gameEngine::AScene {
    public:
        PastPresentTransitionScene(gameEngine::AGame *game) : gameEngine::AScene(game)
        {
            getECS().addSystem<gameEngine::ClickableSystem>();
            getECS().addSystem<gameEngine::ButtonSystem>();
            getECS().addSystem<gameEngine::AutomaticResizeSystem>();
            getECS().addSystem<gameEngine::DrawSystem>();
            getECS().addEntity<Image>(gameEngine::Vector2<float>(0.0f, 0.0f), gameEngine::Rectangle<int>(0, 0, 1920, 1080), "assets/Ui/Passe-Present.png", 0U);
            getECS().addEntity<ClickableEntity>(gameEngine::Vector2<float>(1520, 939), gameEngine::Rectangle<int>(1125, 914, 714, 120), gameEngine::Color(255, 255, 255, 255), "assets/Ui/Bouton_Menu.png",
                [this](){getGame()->addScene<PresentScene>(); kill();});
            getECS().addEntity<ClickableEntity>(gameEngine::Vector2<float>(393, 939), gameEngine::Rectangle<int>(60, 914, 715, 120), gameEngine::Color(255, 255, 255, 255), "assets/Ui/Bouton_Menu.png",
                [this](){kill();});
        }
        ~PastPresentTransitionScene() = default;
};

#endif /* !PASTPRESENTTRANSITIONSCENE_HPP_ */
