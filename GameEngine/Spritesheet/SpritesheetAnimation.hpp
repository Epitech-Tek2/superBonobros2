/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SpritesheetAnimation
*/

#ifndef SpritesheetANIMATION_HPP_
#define SpritesheetANIMATION_HPP_

#include "Vector2.hpp"
#include "Rectangle.hpp"

namespace gameEngine {

    class SpritesheetAnimation {
        public:
            enum Runtype {
                AutoRealod = 0,
                SwapSens = 1,
                NoReload = 2,
            };

            SpritesheetAnimation(
                const Vector2<unsigned int> &startPos = {0, 0},
                const Vector2<unsigned int> &cellSize = {1, 1},
                const Vector2<unsigned int> &cellNbr = {0, 0},
                float frameRate = 0.5,
                Runtype runtype = SwapSens
            );

            SpritesheetAnimation(const SpritesheetAnimation &anim);

            ~SpritesheetAnimation();

            void update(float deltaTime);
            void nextCell(void);
            Rectangle<int> getRectangle(void) const;
            void reset(void);
            void setSens(bool reverseSens);

        protected:
        private:
            const Vector2<unsigned int> _startPos;
            const Vector2<unsigned int> _cellSize;
            const Vector2<unsigned int> _cellNbr;
            const float _frameRate;
            const Runtype _runtype;
            Vector2<unsigned int> _position;
            float _internTime;
            bool _reverseSens;
    };

};

#endif /* !SpritesheetANIMATION_HPP_ */
