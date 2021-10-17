/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** StdClock
*/

#include "StdClock.hpp"

StdClock::StdClock() : _timePoint(std::chrono::system_clock::now())
{
}

float StdClock::elapsedTime() noexcept
{
    auto tmp = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = tmp - _timePoint;

    _timePoint = tmp;
    return diff.count();
}