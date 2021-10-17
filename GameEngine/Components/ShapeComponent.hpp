/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ShapeComponent
*/

#ifndef SHAPECOMPONENT_HPP_
#define SHAPECOMPONENT_HPP_

#include "Component.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"

namespace gameEngine {

    enum ShapeType {
        RectangleShape = 0,
        CircleShape = 1
    };

    class ShapeComponent : public Component {
        public:
            ShapeType _type = RectangleShape;
            Rectangle<float> _rectangle = {0, 0, 1, 1};
            Circle<float> _circle = {0, 0, 1};
            bool _baseOnTexture = false;
            Vector2<float> _textureCenterRatio = {0.5, 0.5};
            bool _isComplex = false;
            std::array<Vector2<float>, 4> _complexBounce;
    };

};

#endif /* !SHAPECOMPONENT_HPP_ */
