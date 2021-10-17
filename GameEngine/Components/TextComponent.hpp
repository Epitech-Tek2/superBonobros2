/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** TextComponent
*/

#ifndef TEXTCOMPONENT_HPP_
#define TEXTCOMPONENT_HPP_

#include "Component.hpp"
#include "Color.hpp"

namespace gameEngine {
    class TextComponent : public Component {
        public:
            std::string _text;
            size_t _fontIndex = 0;
            Color _fillColor = {255, 255, 255, 255};
            Color _outlineColor = {255, 255, 255, 255};
            unsigned int _characterSize = 30;
    };

};

#endif /* !TEXTCOMPONENT_HPP_ */