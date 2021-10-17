/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SpritesheetComponent
*/

#ifndef SpritesheetCOMPONENT_HPP_
#define SpritesheetCOMPONENT_HPP_

#include "Component.hpp"
#include "SpritesheetAnimators.hpp"

namespace gameEngine {

    class SpritesheetComponent : public Component {
        public:
            SpritesheetAnimators SpritesheetAnimator;
    };

};

#endif /* !SpritesheetCOMPONENT_HPP_ */
