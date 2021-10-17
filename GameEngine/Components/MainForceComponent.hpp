/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** MainForceComponent
*/

#ifndef MAINFORCECOMPONENT_HPP_
#define MAINFORCECOMPONENT_HPP_

#include "Component.hpp"
#include "Vector2.hpp"

namespace gameEngine {

    class MainForceComponent : public Component {
        public:
            Vector2<float> _mainForce = {0, 0};
    };

};

#endif /* !MAINFORCECOMPONENT_HPP_ */
