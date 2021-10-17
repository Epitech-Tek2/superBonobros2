/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ClickableComponent
*/

#ifndef CLICKABLECOMPONENT_HPP_
#define CLICKABLECOMPONENT_HPP_

#include "Component.hpp"

namespace gameEngine {

    class ClickableComponent : public Component {
        public:
            enum MouseState {
                BaseState = 0,
                OnButton,
                HoldClick,
                Released
            };
            MouseState state = BaseState;
    };

};

#endif /* !CLICKABLECOMPONENT_HPP_ */