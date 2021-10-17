/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** DisplayTransformSystem
*/

#ifndef DISPLAYTRANSFORMSYSTEM_HPP_
#define DISPLAYTRANSFORMSYSTEM_HPP_

#include <iostream>

#include "ASystem.hpp"
#include "ECS.hpp"
#include "Transform2DComponent.hpp"

namespace gameEngine {

    class DisplayTransformSystem : virtual public ASystem {
        public:
            DisplayTransformSystem(ECS *ecs) : ASystem(ecs, 0.2) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<Transform2DComponent>(this);
            }

            ~DisplayTransformSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float)
            {
                auto &transform = _ecs->getEntityComponent<Transform2DComponent>(entity)._transform;
                transform.move(3, 3);
                transform.rotate(15);
                auto scale = transform.getScale();
                auto center = transform.getOrigin();
                auto angle = transform.getRotation();
                auto pos = transform.getPosition();
                std::cout <<
                    "postion: " << pos.x << "x " << pos.y << "y" << std::endl <<
                    "origine: " << center.x << "x " << center.y << "y" << std::endl <<
                    "scale: " << scale.x << "x " << scale.y << "y" << std::endl <<
                    "rotation: " << angle << " degrees" << std::endl;
            }
    };
};

#endif /* !DISPLAYTRANSFORMSYSTEM_HPP_ */
