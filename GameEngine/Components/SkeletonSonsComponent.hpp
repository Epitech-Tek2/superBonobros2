/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SkeletonSonsComponent
*/

#ifndef SKELETONSONSCONPONENT_HPP_
#define SKELETONSONSCONPONENT_HPP_

#include <map>
#include <string>
#include "Component.hpp"
#include "AEntity.hpp"
#include "ECS.hpp"
#include "SkeletonFatherComponent.hpp"

namespace gameEngine {

    class SkeletonSonsComponent : public Component {
        public:
            SkeletonSonsComponent();
            ~SkeletonSonsComponent();

            template<typename T, typename ...Targs>
            std::shared_ptr<AEntity> createSon(const std::string &sonName, const Vector2<float> &joinPos, ECS *ecs, Targs...args)
            {
                if (_sonsList.count(sonName))
                    _sonsList.at(sonName)->kill();
                auto son = ecs->addEntity<T>(args...);
                _sonsList[sonName] = son;
                SkeletonFatherComponent fatherComp(_entity, joinPos);
                ecs->addComponents(son, fatherComp);
                return son;
            }

            bool haveSon(const std::string &sonName);
            void removeSon(const std::string &sonName);
            void removeSon(std::shared_ptr<AEntity> son);
            std::shared_ptr<AEntity> getSon(const std::string &sonName);

        protected:
        private:
            std::map<const std::string, std::shared_ptr<AEntity>> _sonsList;
    };
};

#endif /* !SKELETONSONSCONPONENT_HPP_ */
