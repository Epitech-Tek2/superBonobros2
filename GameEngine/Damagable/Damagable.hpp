/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Damagable
*/

#ifndef DAMAGABLE_HPP_
#define DAMAGABLE_HPP_


#include <string>
#include <functional>
#include <map>

#include "Damage.hpp"

namespace gameEngine {

    class Damagable {
        public:
            Damagable(unsigned int point = 1, bool invincible = false, bool takeUnknowDamage = true, bool breakAbsorption = true);
            ~Damagable();

            void takeDamage(Damage &damage);
            void setTypeApplication(const std::string &type, std::function<unsigned int(unsigned int)> fonction);

            unsigned int _point;
            unsigned int _maxPoint;
            bool _invincible;
            bool _takeUnknowDamage;
            bool _breakAbsorption;
            bool _hit;

        protected:
        private:
            std::map<const std::string, std::function<unsigned int(unsigned int)>> _damageTypes;

    };
};

#endif /* !DAMAGABLE_HPP_ */
