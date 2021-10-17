/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Circle
*/

#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "Vector2.hpp"

namespace gameEngine {

    template <typename T>
    class Circle {
        public:

            inline Circle() : _pos(0, 0), _ray(0) {}

            inline Circle(T posX, T posY, T ray) : _pos(posX, posY), _ray(ray) {}

            template <typename U>
            inline Circle(const Circle<U>& circle) :
                _pos(static_cast<U>(circle.posX()), static_cast<U>(circle.posY()), static_cast<U>(circle.ray())) {}

            template <typename U>
            inline Circle(U posX, U posY, U ray) :
                _pos(static_cast<T>(posX), static_cast<T>(posY)), _ray(static_cast<T>(ray)) {}

            void setPosition(Vector2<T> const &pos) {
                _pos = pos;
            }

            void setRay(T ray) {
                _ray = ray;
            }

            Vector2<T> pos() const {
                return _pos;
            }

            T posX() const {
                return _pos.x;
            }

            T posY() const {
                return _pos.y;
            }

            T ray() const {
                return _ray;
            }

        private:
            Vector2<T> _pos;
            T _ray;
    };
}

#endif /* !CIRCLE_HPP_ */