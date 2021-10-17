/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ButtonActionComponent
*/

#ifndef BUTTONACTIONCOMPONENT_HPP_
#define BUTTONACTIONCOMPONENT_HPP_

#include "Component.hpp"

#include <functional>

namespace gameEngine{
class ButtonActionComponent : public Component {
    public:
        std::function<void(void)> _action;
};
}

#endif /* !BUTTONACTIONCOMPONENT_HPP_ */