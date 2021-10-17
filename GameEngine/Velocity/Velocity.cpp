/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Velocity
*/

#include "Velocity.hpp"

gameEngine::Velocity::Velocity(Vector2<float> speed, Vector2<float> acceleration, Vector2<float> maxSpeed)
    : _speed(speed), _baseSpeed(speed), _acceleration(acceleration), _maxSpeed(maxSpeed)
{
}

gameEngine::Velocity::~Velocity()
{
}

void gameEngine::Velocity::reset(Vector2<float> speed, Vector2<float> acceleration, Vector2<float> maxSpeed)
{
    _speed = speed;
    _baseSpeed = speed;
    _acceleration = acceleration;
    _maxSpeed = maxSpeed;
}

gameEngine::Vector2<float> gameEngine::Velocity::run(float deltaTime)
{
    Vector2<float> vec = _speed;
    float nvSpeedX = _speed.x + (_acceleration.x * deltaTime);
    float nvSpeedY = _speed.y + (_acceleration.y * deltaTime);

    if (nvSpeedX < _maxSpeed.x)
        _speed.x = nvSpeedX;
    else
        _speed.x = _maxSpeed.x;
    if (nvSpeedY < _maxSpeed.y)
        _speed.y = nvSpeedY;
    else
        _speed.y = _maxSpeed.y;
    return vec;
}