/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** StdClock
*/

#ifndef STDCLOCK_HPP_
#define STDCLOCK_HPP_

#include "IClock.hpp"

#include <chrono>

class StdClock : public IClock {
    public:
        StdClock();
        StdClock(StdClock const &) = delete;
        ~StdClock() = default;

        StdClock &operator=(StdClock const &) = delete;

        float elapsedTime() noexcept final;
    private:
        std::chrono::system_clock::time_point _timePoint;
};

#endif /* !STDCLOCK_HPP_ */