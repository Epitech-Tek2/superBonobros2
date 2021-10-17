/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SpritesheetAnimation
*/

#include "SpritesheetAnimation.hpp"

gameEngine::SpritesheetAnimation::SpritesheetAnimation(
    const Vector2<unsigned int> &startPos,
    const Vector2<unsigned int> &cellSize,
    const Vector2<unsigned int> &cellNbr,
    float frameRate, Runtype runtype)
        : _startPos(startPos), _cellSize(cellSize), _cellNbr(cellNbr),
        _frameRate(frameRate), _runtype(runtype), _position({0, 0}), _internTime(0), _reverseSens(false)
{    
}

gameEngine::SpritesheetAnimation::SpritesheetAnimation(const SpritesheetAnimation &anim)
    : _startPos(anim._startPos), _cellSize(anim._cellSize), _cellNbr(anim._cellNbr),
        _frameRate(anim._frameRate), _runtype(anim._runtype), _position({0, 0}), _internTime(0), _reverseSens(false)
{
}

gameEngine::SpritesheetAnimation::~SpritesheetAnimation()
{
}

void gameEngine::SpritesheetAnimation::nextCell(void)
{
    Vector2<unsigned int> maxPos = _cellNbr;
    int incrementer = 1;
    if (_reverseSens == true) {
        maxPos = {0, 0};
        incrementer = -1;
    }

    if (_position.x == maxPos.x) {
        if (_position.y == maxPos.y) {
            if (_runtype == Runtype::AutoRealod)
                reset();
            if (_runtype == Runtype::SwapSens) {
                _reverseSens = !_reverseSens;
                if (_cellNbr != Vector2<unsigned int> {0, 0})
                    nextCell();
            }
        } else {
            _position.y += incrementer;
        }
    } else
        _position.x += incrementer;
}

void gameEngine::SpritesheetAnimation::update(float deltaTime)
{
    _internTime += deltaTime;

    for (; _internTime >= _frameRate; _internTime -= _frameRate)
        nextCell();
}

void gameEngine::SpritesheetAnimation::reset(void)
{
    if (_reverseSens == false)
        _position = {0, 0};
    else
        _position = _cellNbr;
}

void gameEngine::SpritesheetAnimation::setSens(bool reverseSens)
{
    _reverseSens = reverseSens;
}

gameEngine::Rectangle<int> gameEngine::SpritesheetAnimation::getRectangle(void) const
{
    float x = _startPos.x + (_position.x * _cellSize.x);
    float y = _startPos.y + (_position.y * _cellSize.y);
    return Rectangle<int>(x, y, _cellSize.x, _cellSize.y);
}