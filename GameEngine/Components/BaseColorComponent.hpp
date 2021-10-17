/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** BaseColorComponent
*/

#ifndef BASECOLORCOMPONENT_HPP_
#define BASECOLORCOMPONENT_HPP_

#include "Component.hpp"
#include "Color.hpp"

namespace gameEngine {

    class BaseColorComponent : public Component {
        public:
            Color _color = {255, 255, 255, 255};
    };

};

#endif /* !BASECOLORCOMPONENT_HPP_ */