/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Damage
*/

#include "Damage.hpp"

gameEngine::Damage::Damage(unsigned int damage, const std::string &type, bool affectedByShield, bool breakPass)
    : _damage(damage), _type(type), _affectedByShield(affectedByShield), _breakPass(breakPass)
{
}

gameEngine::Damage::~Damage()
{
}

