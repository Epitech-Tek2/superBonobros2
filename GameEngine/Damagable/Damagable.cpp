/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Damagable
*/

#include "Damagable.hpp"

gameEngine::Damagable::Damagable(unsigned int point, bool invincible, bool takeUnknowDamage, bool breakAbsorption)
    : _point(point), _maxPoint(point), _invincible(invincible), _takeUnknowDamage(takeUnknowDamage), _breakAbsorption(breakAbsorption), _hit(false)
{
}

gameEngine::Damagable::~Damagable()
{
}

void gameEngine::Damagable::takeDamage(Damage &damage)
{
    unsigned int dmg = 0;

    if (_invincible) {
        damage._damage = 0;
        return;
    }
    if (_damageTypes.count(damage._type)) {
        dmg = (_damageTypes.at(damage._type)(damage._damage));
    } else {
        if (_takeUnknowDamage)
            dmg = damage._damage;
        else {
            damage._damage = 0;
            return;
        }
    }
    _hit = true;
    if (_point >= dmg) {
        _point -= dmg;
        damage._damage = 0;
    } else {
        if (_breakAbsorption == true && damage._breakPass == false)
            damage._damage = 0;
        else
            damage._damage *= static_cast<float>(dmg - _point) / static_cast<float>(dmg);
        _point = 0;
    }
}

void gameEngine::Damagable::setTypeApplication(const std::string &type, std::function<unsigned int(unsigned int)> fonction)
{
    if (_damageTypes.count(type))
        _damageTypes.at(type) = fonction;
    else
        _damageTypes.emplace(type, fonction);
}
