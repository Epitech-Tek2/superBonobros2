/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** IClock
*/

#ifndef ICLOCK_HPP_
#define ICLOCK_HPP_

class IClock {
    public:
        virtual ~IClock() = default;

        virtual float elapsedTime() noexcept = 0;
};

#endif /* !ICLOCK_HPP_ */