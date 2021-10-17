/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Transform2D
*/

#include <cmath>
#include "Transform2D.hpp"

gameEngine::Transform2D::Transform2D(
    gameEngine::Vector2<float> origin,
    gameEngine::Vector2<float> position,
    gameEngine::Vector2<float> scale,
    float rotation)
    : _origin(origin), _position(position), _scale(scale), _rotation(rotation), _matrixNeedUpdate(true)
{
}

gameEngine::Transform2D::~Transform2D()
{
}

void gameEngine::Transform2D::updadeMatrix(void)
{
    float angle  = -_rotation * 3.141592654f / 180.f;
    float cosine = static_cast<float>(std::cos(angle));
    float sine   = static_cast<float>(std::sin(angle));
    float sxc    = _scale.x * cosine;
    float syc    = _scale.y * cosine;
    float sxs    = _scale.x * sine;
    float sys    = _scale.y * sine;
    float tx     = -_origin.x * sxc - _origin.y * sys + _position.x;
    float ty     =  _origin.x * sxs - _origin.y * syc + _position.y;

    _matrix[0] = sxc;
    _matrix[1] = -sxs;
    _matrix[2] = 0.f;
    _matrix[3] = 0.f;

    _matrix[4] = sys;
    _matrix[5] = syc;
    _matrix[6] = 0.f;
    _matrix[7] = 0.f;

    _matrix[8] = 0.f;
    _matrix[9] = 0.f;
    _matrix[10] = 1.f;
    _matrix[11] = 0.f;

    _matrix[12] = tx;
    _matrix[13] = ty;
    _matrix[14] = 0.0;
    _matrix[15] = 1.0;

    /*_matrix = Transform( sxc, sys, tx,
                            -sxs, syc, ty,
                             0.f, 0.f, 1.f);*/
                            
}

void gameEngine::Transform2D::UpdateMatrixIfNeeded(void)
{
    if (_matrixNeedUpdate)
        updadeMatrix();
}

void gameEngine::Transform2D::setPosition(float x, float y)
{
    _position.x = x;
    _position.y = y;
    _matrixNeedUpdate = true;
}

void gameEngine::Transform2D::setPosition(const gameEngine::Vector2<float> &position)
{
    setPosition(position.x, position.y);
}

void gameEngine::Transform2D::setRotation(float angle)
{
    _rotation = static_cast<float>(fmod(angle, 360));
    if (_rotation < 0)
        _rotation += 360.f;

    _matrixNeedUpdate = true;
}

void gameEngine::Transform2D::setScale(float factorX, float factorY)
{
    _scale.x = factorX;
    _scale.y = factorY;
    _matrixNeedUpdate = true;
}

void gameEngine::Transform2D::setScale(const gameEngine::Vector2<float> &factors)
{
    setScale(factors.x, factors.y);
}

void gameEngine::Transform2D::setOrigin(float x, float y)
{
    _origin.x = x;
    _origin.y = y;
    _matrixNeedUpdate = true;
}

void gameEngine::Transform2D::setOrigin(const gameEngine::Vector2<float> &origin)
{
    setOrigin(origin.x, origin.y);
}

const  gameEngine::Vector2<float> &gameEngine::Transform2D::getPosition() const
{
    return _position;
}

float gameEngine::Transform2D::getRotation() const
{
    return _rotation;
}

const  gameEngine::Vector2<float> &gameEngine::Transform2D::getScale() const
{
    return _scale;
}

const  gameEngine::Vector2<float> &gameEngine::Transform2D::getOrigin() const
{
    return _origin;
}

void gameEngine::Transform2D::move(float offsetX, float offsetY)
{
    setPosition(_position.x + offsetX, _position.y + offsetY);
}

void gameEngine::Transform2D::move(const gameEngine::Vector2<float> &offset)
{
    setPosition(_position.x + offset.x, _position.y + offset.y);
}

void gameEngine::Transform2D::rotate(float angle)
{
    setRotation(_rotation + angle);
}

void gameEngine::Transform2D::scale(float factorX, float factorY)
{
    setScale(_scale.x * factorX, _scale.y * factorY);
}

void gameEngine::Transform2D::scale(const gameEngine::Vector2<float> &factor)
{
    setScale(_scale.x * factor.x, _scale.y * factor.y);
}

gameEngine::Vector2<float> gameEngine::Transform2D::transformPoint(float x, float y)
{
    UpdateMatrixIfNeeded();
    return Vector2<float>(
        _matrix[0] * x + _matrix[4] * y + _matrix[12],
        _matrix[1] * x + _matrix[5] * y + _matrix[13]
    );
}

gameEngine::Vector2<float> gameEngine::Transform2D::transformPoint(const gameEngine::Vector2<float> &point)
{
    return transformPoint(point.x, point.y);
}

