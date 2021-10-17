/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Velocity
*/

#ifndef VELOCITY_HPP_
#define VELOCITY_HPP_

#include "Vector2.hpp"

namespace gameEngine {

    class Velocity {
        public:
            Velocity(Vector2<float> speed = {0.f, 0.f}, Vector2<float> acceleration = {0, 0}, Vector2<float> maxSpeed = {1000, 1000});
            ~Velocity();

            Vector2<float> _speed;
            Vector2<float> _baseSpeed;
            Vector2<float> _acceleration;
            Vector2<float> _maxSpeed;

            void reset(Vector2<float> speed, Vector2<float> acceleration, Vector2<float> maxSpeed);
            Vector2<float> run(float deltaTime);

        protected:
        private:
    };
};

#endif /* !VELOCITY_HPP_ */
