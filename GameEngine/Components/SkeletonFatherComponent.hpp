/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SkeletonFatherComponent
*/

#ifndef SKELETONFATHERCOMPONENT_HPP_
#define SKELETONFATHERCOMPONENT_HPP_

#include "Component.hpp"
#include "AEntity.hpp"
#include "Vector2.hpp"

namespace gameEngine {

    class SkeletonFatherComponent : public Component {
        public:
            SkeletonFatherComponent(std::shared_ptr<AEntity> father, const Vector2<float> &joinPos) : _father(father), _jointPos(joinPos), _rotation(0) {}
            const std::shared_ptr<AEntity> _father;
            Vector2<float> _jointPos;
            float _rotation;
    };

};

#endif /* !SKELETONFATHERCOMPONENT_HPP_ */
