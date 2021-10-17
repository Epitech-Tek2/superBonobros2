/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** LiveTimeComponent
*/

#ifndef LIVETIMECOMPONENT_HPP_
#define LIVETIMECOMPONENT_HPP_

#include "Component.hpp"

namespace gameEngine {

    class LiveTimeComponent : public Component {
        public:
            float liveTime = 1.f;
    };

};

#endif /* !LIVETIMECOMPONENT_HPP_ */
