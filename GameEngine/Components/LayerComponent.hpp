/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** LayerComponent
*/

#ifndef LAYERCOMPONENT_HPP_
#define LAYERCOMPONENT_HPP_

#include "Component.hpp"
#include "Color.hpp"
#include "Rectangle.hpp"

namespace gameEngine {

    class LayerComponent : public Component {
        public:
            unsigned int layer = 0;
    };

};

#endif /* !LAYERCOMPONENT_HPP_ */
