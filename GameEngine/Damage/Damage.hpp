/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Damage
*/

#ifndef DAMAGE_HPP_
#define DAMAGE_HPP_

#include <string>

namespace gameEngine {

    class Damage {
        public:
            Damage(unsigned int damage = 1, const std::string &type = "", bool affectedByShield = true, bool breakPass = false);
            ~Damage();

            unsigned int _damage;
            std::string _type;
            bool _affectedByShield;
            bool _breakPass;
    };
};

#endif /* !DAMAGE_HPP_ */
