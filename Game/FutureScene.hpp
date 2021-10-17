/*
** EPITECH PROJECT, 2021
** G-JAM-001-STG-0-1-jam-louis.kleiver
** File description:
** FutureScene
*/

#ifndef FUTURESCENE_HPP_
#define FUTURESCENE_HPP_

    #include "AScene.hpp"

    #include "WinScene.hpp"
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
    #include "Drone.hpp"
    #include "StudentBot.hpp"


class FutureScene : public gameEngine::AScene {
    public:
        FutureScene(gameEngine::AGame *game)  : gameEngine::AScene(game)
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



            getECS().addEntity<Image>(gameEngine::Vector2<float>(0, 0), gameEngine::Rectangle<int>(0, 0, 1920, 1080), "assets/Future/Epitech_futur.png", 0);

            getECS().addEntity<Wall>(gameEngine::Vector2<float>(0, 0), gameEngine::Vector2<float>(56, 1080));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(0, 0), gameEngine::Vector2<float>(1920, 56));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(0, 1024), gameEngine::Vector2<float>(1920, 56));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1864, 0), gameEngine::Vector2<float>(56, 1080));

            getECS().addEntity<Wall>(gameEngine::Vector2<float>(46, 46), gameEngine::Vector2<float>(332, 89));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(46, 150), gameEngine::Vector2<float>(94, 220));

            getECS().addEntity<Wall>(gameEngine::Vector2<float>(154, 469), gameEngine::Vector2<float>(156, 369));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(154, 835), gameEngine::Vector2<float>(68, 179));

            getECS().addEntity<Wall>(gameEngine::Vector2<float>(835, 304), gameEngine::Vector2<float>(413, 420));
            
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(950, 230), gameEngine::Vector2<float>(182, 76));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(750, 440), gameEngine::Vector2<float>(65, 190));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1276, 436), gameEngine::Vector2<float>(65, 190));
            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1000, 750), gameEngine::Vector2<float>(182, 76));

            getECS().addEntity<Wall>(gameEngine::Vector2<float>(1575, 343), gameEngine::Vector2<float>(25, 80));
            _player = nullptr;
            _cheatMarks.push_back(getECS().addEntity<CheatMarks>(gameEngine::Vector2<float>(240, 991)));
            _cheatMarks.push_back(getECS().addEntity<CheatMarks>(gameEngine::Vector2<float>(1669, 371)));
            _cheatMarks.push_back(getECS().addEntity<CheatMarks>(gameEngine::Vector2<float>(792, 288)));
            _cheatMarks.push_back(getECS().addEntity<CheatMarks>(gameEngine::Vector2<float>(279, 206)));
            _cheatMarks.push_back(getECS().addEntity<CheatMarks>(gameEngine::Vector2<float>(437, 979)));

            _studentsBots.push_back(getECS().addEntity<StudentCheaterBot>(gameEngine::Vector2<float>(1388, 522), "assets/Future/Quentin_rond.png", "Game/scripts/futur/quentin.cfg"));
            _studentsBots.push_back(getECS().addEntity<StudentCheaterBot>(gameEngine::Vector2<float>(812, 760), "assets/Future/Romu_Rond.png", "Game/scripts/futur/romu.cfg"));
            _studentsBots.push_back(getECS().addEntity<StudentCheaterBot>(gameEngine::Vector2<float>(1312, 758), "assets/Future/Matthieu_rond.png", "Game/scripts/futur/matthieu.cfg"));
            _studentsBots.push_back(getECS().addEntity<StudentCheaterBot>(gameEngine::Vector2<float>(700, 542), "assets/Future/Léo_Rond.png", "Game/scripts/futur/leo.cfg"));
            _studentsBots.push_back(getECS().addEntity<StudentCheaterBot>(gameEngine::Vector2<float>(352, 550), "assets/Future/Theo_Rond.png", "Game/scripts/futur/theo.cfg"));

            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(344, 738), "assets/Future/Clement_Rond.png");
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(100, 744), "assets/Future/Elia_Rond.png");
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(1288, 290), "assets/Future/Etudiant_Lambda.png");
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(1040, 190), "assets/Future/Etudiant_Lambda2.png");
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(98, 928), "assets/Future/Gorrille.png");
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(104, 562), "assets/Future/Louis_rond.png");
            getECS().addEntity<StudentBot>(gameEngine::Vector2<float>(166, 248), "assets/Future/Kaben_Vieux.png");

            _drones.push_back(getECS().addEntity<Drone>(gameEngine::Vector2<float>(226, 330)));
            _drones.push_back(getECS().addEntity<Drone>(gameEngine::Vector2<float>(492, 206)));
        }
        ~FutureScene() = default;

        void update(float deltaTime)
        {
            AScene::update(deltaTime);
            static float speed = 100;
            bool win = true;

            const gameEngine::IEvent *events = getGraphic()->getEvent();
            if (_player != nullptr) {
                auto &force = getECS().getEntityComponent<gameEngine::MainForceComponent>(_player);
                auto sons = getECS().getEntityComponent<gameEngine::SkeletonSonsComponent>(_player).getSon("FieldOfView");
                force._mainForce = gameEngine::Vector2<float>(0, 0);
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
            }

            for (auto drone : _drones) {
                auto &clic = getECS().getEntityComponent<gameEngine::ClickableComponent>(drone);
                if (clic.state == gameEngine::ClickableComponent::MouseState::Released) {
                    if (_player) {
                        auto &force = getECS().getEntityComponent<gameEngine::MainForceComponent>(_player);
                        auto &texture = getECS().getEntityComponent<gameEngine::TextureComponent>(_player);
                        force._mainForce = {0, 0};
                        texture._index = getGraphic()->loadTexture("assets/Future/Drone_Rond_Gris.png");
                    }
                    auto &texture = getECS().getEntityComponent<gameEngine::TextureComponent>(drone);
                    texture._index = getGraphic()->loadTexture("assets/Future/Drone_selected.png");
                    _player = drone;
                }
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
                    if (!studentBot->getImmuneStatus() && collision->getType() == "FieldOfView") {
                        studentBot->kill();
                        studentBot->setHasLooseStatus(true);
                    }
                }
                if (!studentBot->getHasLooseStatus())
                    win = false;
            }
            if (win) {
                getGame()->addScene<WinScene>();
                kill();
            } 
        }

    protected:
    private:
        std::shared_ptr<Drone> _player;
        std::vector<std::shared_ptr<StudentCheaterBot>> _studentsBots;
        std::vector<std::shared_ptr<Drone>> _drones;
        std::vector<std::shared_ptr<CheatMarks>> _cheatMarks;
};

#endif /* !FUTURESCENE_HPP_ */
