/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <bitset>
#include <array>
#include <memory>

#define MAX_COMPONENTS 32

namespace gameEngine {

    class AEntity;

    class Component {
        public:
            using Bitset = std::bitset<MAX_COMPONENTS>;
            using List = std::array<std::shared_ptr<Component>, MAX_COMPONENTS>;
            std::shared_ptr<AEntity> _entity;

    };
    static inline bool bitsetMatch(const Component::Bitset &bitset, const Component::Bitset &key) {
        return key == (bitset & key);
    }
};

#endif /* !COMPONENT_HPP_ */
