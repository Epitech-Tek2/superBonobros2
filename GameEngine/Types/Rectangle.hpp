/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "Vector2.hpp"

namespace gameEngine {

    template <typename T>
    class Rectangle {
        public:

            inline Rectangle() : _pos(0, 0), _width(0), _height(0) {}

            inline Rectangle(T posX, T posY, T width, T height) : _pos(posX, posY), _width(width), _height(height) {}

            template <typename U>
            inline Rectangle(const Rectangle<U>& rect) :
                _pos(static_cast<T>(rect.posX()), static_cast<T>(rect.posY())), _width(static_cast<T>(rect.width())), _height(static_cast<T>(rect.height())) {}

            template <typename U>
            inline Rectangle(U posX, U posY, U width, U height) :
                _pos(static_cast<T>(posX), static_cast<T>(posY)), _width(static_cast<T>(width)), _height(static_cast<T>(height)) {}

            void setPosition(Vector2<T> const &pos) {
                _pos = pos;
            }

            void setHeight(T height) {
                _height = height;
            }

            void setWidth(T width) {
                _width = width;
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

            T height() const {
                return _height;
            }

            T width() const {
                return _width;
            }

        private:
            Vector2<T> _pos;
            T _width;
            T _height;
    };
}

#endif /* !RECTANGLE_HPP_ */