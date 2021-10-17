/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SpritesheetUpdateSystem
*/

#ifndef SpritesheetUPDATESYSTEM_HPP_
#define SpritesheetUPDATESYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS.hpp"
#include "TextureComponent.hpp"
#include "SpritesheetComponent.hpp"

namespace gameEngine {

    class SpritesheetUpdateSystem : virtual public ASystem {
        public:
            SpritesheetUpdateSystem(ECS *ecs) : ASystem(ecs) {}

            void init(ECS *ecs)
            {
                ecs->systemAddDependances<TextureComponent>(this);
                ecs->systemAddDependances<SpritesheetComponent>(this);
            }

            ~SpritesheetUpdateSystem(void) = default;

        protected:
        private:
            void action(std::shared_ptr<AEntity> entity, float deltaTime)
            {
                auto &texture = _ecs->getEntityComponent<TextureComponent>(entity)._rect;
                auto &Spritesheet = _ecs->getEntityComponent<SpritesheetComponent>(entity).SpritesheetAnimator;

                Spritesheet.update(deltaTime);
                Spritesheet.appyOnTexture(texture);
            }
    };
};

#endif /* !SpritesheetUPDATESYSTEM_HPP_ */
