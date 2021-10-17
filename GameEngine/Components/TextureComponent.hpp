/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** TextureComponent
*/

#ifndef TEXTURECOMPONENT_HPP_
#define TEXTURECOMPONENT_HPP_

#include "Component.hpp"
#include "Color.hpp"
#include "Rectangle.hpp"

namespace gameEngine {

    enum TextureType {
        ColorTexture = 0,
        FileTexture = 1
    };

    class TextureComponent : public Component {
        public:
            TextureType _type = ColorTexture;
            Color _color = {255, 255, 255, 255};
            size_t _index = 0;
            Rectangle<int> _rect = {0, 0, 0, 0};
    };

};

#endif /* !TEXTURECOMPONENT_HPP_ */
