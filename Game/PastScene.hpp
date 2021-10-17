/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** PastScene
*/

#ifndef PASTSCENE_HPP_
#define PASTSCENE_HPP_

    #include "AScene.hpp"

    #include "PastPresentTransitionScene.hpp"
    #include "GameOverScene.hpp"

    #include "AutomaticResizeSystem.hpp"
    #include "DrawSystem.hpp"
    #include "ButtonSystem.hpp"
    #include "ClickableSystem.hpp"
    #include "CollisionSystem.hpp"
    #include "WallForceSystem.hpp"
    #include "MainForceSystem.hpp"
    #include "ForceApplicationSystem.hpp"
    #include "MovementSystem.hpp"
    #include "SkeletonSystem.hpp"
    #include "ScriptSystem.hpp"

    #include "StudentCheaterPlayer.hpp"
    #include "CheatMarks.hpp"
    #include "SafeArea.hpp"
    #include "TeacherBot.hpp"
    #include "Image.hpp"
    #include "Wall.hpp"
    #include "StudentBot.hpp"


class PastScene : public gameEngine::AScene {
    public:
        PastScene(gameEngine::AGame *game)  : gameEngine::AScene(game)
        {
            getECS().addSystem<gameEngine::ClickableSystem>();
            getECS().addSystem<gameEngine::ButtonSystem>();

            getECS().addSystem<gameEngine::CollisionSystem>();
            getECS().addSystem<ScriptSystem>();
            getECS().addSystem<gameEngine::MainForceSystem>();
            getECS().addSystem<gameEngine::WallForceSystem>();
            getECS().addSystem<gameEngine::ForceApplicationSystem>();
            getECS().addSystem<gameEngine::MovementSystem>();
            getECS().addSystem<gameEngine::SkeletonSystem>();


            getECS().addSystem<gameEngine::AutomaticResizeSystem>();
            getECS().addSystem<gameEngine::DrawSystem>();



            getECS().addEntity<Image>(gameEngine::Vector2<float>(0, 0), gameEngine::Rectangle<int>(0, 0, 1920, 1080), "assets/Past/Epitech_Passe.png", 0);
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(850, 774), "assets/Past/Thibaut_Rond.png");
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(896, 432), "assets/Past/Matthias_Rond.png");
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(1384, 206), "assets/Past/Joan_Rond.png");
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(1254, 786), "assets/Past/Francois_Rond.png");

            getECS().addEntity<Wall>(gameEngine::Vector2<float>(0, 0), gameEngine::Vector2<float>(56, 1080));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(0, 0), gameEngine::Vector2<float>(1920, 56));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(0, 1024), gameEngine::Vector2<float>(1920, 56));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1864, 0), gameEngine::Vector2<float>(56, 1080));

            getECS().addEntity<Wall>(gameEngine::Vector2<float>(205, 50), gameEngine::Vector2<float>(80, 415));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(450, 50), gameEngine::Vector2<float>(80, 425));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(695, 50), gameEngine::Vector2<float>(80, 415));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(928, 50), gameEngine::Vector2<float>(80, 415));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1175, 50), gameEngine::Vector2<float>(80, 415));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1425, 50), gameEngine::Vector2<float>(80, 415));

            getECS().addEntity<Wall>(gameEngine::Vector2<float>(120, 775), gameEngine::Vector2<float>(155, 55));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(495, 660), gameEngine::Vector2<float>(31, 420));
            
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(680, 636), gameEngine::Vector2<float>(80, 400));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(886, 636), gameEngine::Vector2<float>(80, 400));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1081, 636), gameEngine::Vector2<float>(80, 400));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1282, 636), gameEngine::Vector2<float>(80, 400));

            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1690, 625), gameEngine::Vector2<float>(110, 80));
            _player = getECS().addEntity<StudentCheaterPlayer>(gameEngine::Vector2<float>(252, 870), "assets/Past/Kaben_Jeune.png");

            _cheatMarks = getECS().addEntity<CheatMarks>(gameEngine::Vector2<float>(1800, 188));

            _teacherBot = getECS().addEntity<TeacherBot>(gameEngine::Vector2<float>(1751, 830), "assets/Past/Prof_Passé.png", "Game/scripts/past/teacher.cfg");
        }
        ~PastScene() = default;

        void update(float deltaTime)
        {
            AScene::update(deltaTime);
            static float speed = 100;

            auto &force = getECS().getEntityComponent<gameEngine::MainForceComponent>(_player);
            force._mainForce = gameEngine::Vector2<float>(0, 0);
            const gameEngine::IEvent *events = getGraphic()->getEvent();
            if (events->keyState(gameEngine::up) == gameEngine::pressed)
                force._mainForce += gameEngine::Vector2<float>(0, -speed);
            if (events->keyState(gameEngine::down) == gameEngine::pressed)
                force._mainForce += gameEngine::Vector2<float>(0, speed);
            if (events->keyState(gameEngine::left) == gameEngine::pressed)
                force._mainForce += gameEngine::Vector2<float>(-speed, 0);
            if (events->keyState(gameEngine::right) == gameEngine::pressed)
                force._mainForce += gameEngine::Vector2<float>(speed, 0);
                
            
            auto &collisions = getECS().getEntityComponent<gameEngine::CollisionComponent>(_player);
            auto sons = getECS().getEntityComponent<gameEngine::SkeletonSonsComponent>(_teacherBot).getSon("FieldOfView");

            _player->setImmuneStatus(false);
            for (auto collision : collisions.collingEntitys) {
                if (collision->getType() == _cheatMarks->getType()) {
                    auto &texture = getECS().getEntityComponent<gameEngine::TextureComponent>(_player);
                    texture._color = {150, 150, 255, 255};
                    _player->setReadsMarksStatus(true);
                }
                if (collision->getType() == _player->_safeArea->getType()) {
                    _player->setImmuneStatus(true);
                    if (_player->getReadMarksStatus()) {
                        getGame()->addScene<PastPresentTransitionScene>();
                        kill();
                    }
                }
            }
            for (auto collision : collisions.collingEntitys) {
                if (!_player->getImmuneStatus() && collision->getType() == sons->getType()) {
                    getGame()->addScene<GameOverScene>();
                    kill();
                }
            }
        }

    protected:
    private:
        std::shared_ptr<StudentCheaterPlayer> _player;
        std::shared_ptr<CheatMarks> _cheatMarks;
        std::shared_ptr<TeacherBot> _teacherBot;
};

#endif /* !PASTSCENE_HPP_ */