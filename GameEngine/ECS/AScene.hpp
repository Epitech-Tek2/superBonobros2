/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
#define ASCENE_HPP_

#include "ECS.hpp"
#include "IGraphic.hpp"

namespace gameEngine {

    class AGame;

    class AScene {
        public:
            AScene(AGame *game);
            virtual ~AScene();

            virtual void update(float deltaTime);
            AGame *getGame(void) const;
            IGraphic *getGraphic(void) const;
            ECS &getECS(void);

            void kill(void);
            bool isAlive(void);

        private:
            AGame *_game;
            ECS _ecs;
            bool _alive;
    };

};

#endif /* !ASCENE_HPP_ */
