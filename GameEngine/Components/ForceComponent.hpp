/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** ForceComponent
*/

#ifndef FORCECOMPONENT_HPP_
#define FORCECOMPONENT_HPP_

#include <list>
#include "Component.hpp"
#include "Vector2.hpp"

namespace gameEngine {

    class ForceComponent : public Component {
        public:
            std::list<Vector2<float>> _forceList;
    };

};

#endif /* !FORCECOMPONENT_HPP_ */
