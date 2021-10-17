/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SpritesheetAnimators
*/

#ifndef SpritesheetANIMATORS_HPP_
#define SpritesheetANIMATORS_HPP_

#include <map>
#include <string>
#include "SpritesheetAnimation.hpp"
#include "Rectangle.hpp"

namespace gameEngine {

    class SpritesheetAnimators {
        public:
            SpritesheetAnimators();
            ~SpritesheetAnimators();

            void addAimation(const std::string &animationName, const SpritesheetAnimation &animation);
            void playAnimation(const std::string &animationName);
            void update(float deltaTime);
            void appyOnTexture(Rectangle<int> &rect) const;

        protected:
        private:
            std::string _currentAnimation;
            std::map<const std::string, SpritesheetAnimation> _animations;
    };

};

#endif /* !SpritesheetANIMATORS_HPP_ */
