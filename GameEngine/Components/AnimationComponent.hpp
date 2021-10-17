/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** AnimationComponent
*/

#ifndef ANIMATIONCOMPONENT_HPP_
#define ANIMATIONCOMPONENT_HPP_

#include "Component.hpp"

namespace gameEngine {

    class AnimationComponent : public Component {
        public:
            std::string animationName;
    };

};

#endif /* !ANIMATIONCOMPONENT_HPP_ */
