/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** PresentScene
*/

#ifndef PRESENTSCENE_HPP_
#define PRESENTSCENE_HPP_

    #include "AScene.hpp"

    #include "PresentFutureTransitionScene.hpp"
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

    #include "StudentCheaterBot.hpp"
    #include "CheatMarks.hpp"
    #include "SafeArea.hpp"
    #include "TeacherPlayer.hpp"
    #include "Image.hpp"
    #include "Wall.hpp"
    #include "StudentBot.hpp"


class PresentScene : public gameEngine::AScene {
    public:
        PresentScene(gameEngine::AGame *game)  : gameEngine::AScene(game)
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



            getECS().addEntity<Image>(gameEngine::Vector2<float>(0, 0), gameEngine::Rectangle<int>(0, 0, 1920, 1080), "assets/Present/Epitech_Present.png", 0);

            getECS().addEntity<Wall>(gameEngine::Vector2<float>(0, 0), gameEngine::Vector2<float>(56, 1080));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(0, 0), gameEngine::Vector2<float>(1920, 56));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(0, 1024), gameEngine::Vector2<float>(1920, 56));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1864, 0), gameEngine::Vector2<float>(56, 1080));

            getECS().addEntity<Wall>(gameEngine::Vector2<float>(123, 129), gameEngine::Vector2<float>(183, 139));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(151, 412), gameEngine::Vector2<float>(138, 183));

            getECS().addEntity<Wall>(gameEngine::Vector2<float>(100, 825), gameEngine::Vector2<float>(170, 75));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(495, 660), gameEngine::Vector2<float>(50, 415));

            getECS().addEntity<Wall>(gameEngine::Vector2<float>(685, 660), gameEngine::Vector2<float>(75, 360));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(885, 660), gameEngine::Vector2<float>(75, 360));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1085, 660), gameEngine::Vector2<float>(75, 360));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1280, 660), gameEngine::Vector2<float>(75, 360));

            getECS().addEntity<Wall>(gameEngine::Vector2<float>(885, 50), gameEngine::Vector2<float>(75, 360));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1085, 50), gameEngine::Vector2<float>(75, 360));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1275, 50), gameEngine::Vector2<float>(75, 360));
            _player = getECS().addEntity<TeacherPlayer>(gameEngine::Vector2<float>(1646, 386), "assets/Present/Kaben_Present.png");
            _cheatMarks.push_back(getECS().addEntity<CheatMarks>(gameEngine::Vector2<float>(287, 86)));
            _cheatMarks.push_back(getECS().addEntity<CheatMarks>(gameEngine::Vector2<float>(641, 313)));
            _cheatMarks.push_back(getECS().addEntity<CheatMarks>(gameEngine::Vector2<float>(1030, 412)));

            _studentsBots.push_back(getECS().addEntity<StudentCheaterBot>(gameEngine::Vector2<float>(1244, 784), "assets/Present/Louis_rond.png", "Game/scripts/present/louis.cfg"));
            _studentsBots.push_back(getECS().addEntity<StudentCheaterBot>(gameEngine::Vector2<float>(206, 742), "assets/Present/Elia_Rond.png", "Game/scripts/present/elia.cfg"));
            _studentsBots.push_back(getECS().addEntity<StudentCheaterBot>(gameEngine::Vector2<float>(850, 434), "assets/Present/Clement_Rond.png", "Game/scripts/present/clement.cfg"));
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(1050, 120), "assets/Present/Matthieu_rond.png");
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(838, 982), "assets/Present/Léo_Rond.png");
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(172, 960), "assets/Present/Theo_Rond.png");
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(550, 90), "assets/Present/Romu_Rond.png");
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(1240, 116), "assets/Present/Rémy_Rond.png");
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(1254, 976), "assets/Present/Quentin_rond.png");
        }
        ~PresentScene() = default;

        void update(float deltaTime)
        {
            AScene::update(deltaTime);
            static float speed = 100;
            bool win = true;

            auto &force = getECS().getEntityComponent<gameEngine::MainForceComponent>(_player);
            auto sons = getECS().getEntityComponent<gameEngine::SkeletonSonsComponent>(_player).getSon("FieldOfView");
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
                
            if (events->keyState(gameEngine::j) == gameEngine::pressed) {
                auto &transformSon = getECS().getEntityComponent<gameEngine::SkeletonFatherComponent>(sons);
                transformSon._rotation += 60 * deltaTime;
            }
            if (events->keyState(gameEngine::k) == gameEngine::pressed) {
                auto &transformSon = getECS().getEntityComponent<gameEngine::SkeletonFatherComponent>(sons);
                transformSon._rotation -= 60 * deltaTime;
            }

            
            for (auto studentBot : _studentsBots) {
                auto &collisions = getECS().getEntityComponent<gameEngine::CollisionComponent>(studentBot);

                studentBot->setImmuneStatus(false);
                for (auto collision : collisions.collingEntitys) {
                    for (auto cheatMark : _cheatMarks) {
                        if (collision->getType() == cheatMark->getType()) {
                            auto &texture = getECS().getEntityComponent<gameEngine::TextureComponent>(studentBot);
                            texture._color = {150, 150, 255, 255};
                            studentBot->setReadsMarksStatus(true);
                        }
                    }
                    if (collision->getType() == studentBot->_safeArea->getType()) {
                        studentBot->setImmuneStatus(true);
                        if (studentBot->getReadMarksStatus()) {
                            getGame()->addScene<GameOverScene>();
                            kill();
                        }
                    }
                }
                for (auto collision : collisions.collingEntitys) {
                    if (!studentBot->getImmuneStatus() && collision->getType() == sons->getType()) {
                        studentBot->kill();
                        studentBot->setHasLooseStatus(true);
                    }
                }
                if (!studentBot->getHasLooseStatus())
                    win = false;
            }
            if (win) {
                getGame()->addScene<PresentFutureTransitionScene>();
                kill();
            }
        }

    protected:
    private:
        std::shared_ptr<TeacherPlayer> _player;
        std::vector<std::shared_ptr<StudentCheaterBot>> _studentsBots;
        std::vector<std::shared_ptr<CheatMarks>> _cheatMarks;
};

#endif /* !PRESENTSCENE_HPP_ */
