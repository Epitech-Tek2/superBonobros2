/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Transform2DComponent
*/

#ifndef TRANSFORM2DCOMPONENT_HPP_
#define TRANSFORM2DCOMPONENT_HPP_

#include "Transform2D.hpp"
#include "Component.hpp"

namespace gameEngine {

    class Transform2DComponent : public Component {
        public:
            Transform2D _transform;
    };

};

#endif /* !TRANSFORM2DCOMPONENT_HPP_ */
