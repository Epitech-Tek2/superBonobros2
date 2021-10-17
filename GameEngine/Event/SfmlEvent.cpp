/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SfmlEvent
*/

#include "SfmlEvent.hpp"

gameEngine::SfmlEvent::SfmlEvent()
{
    _keys[gameEngine::a] = gameEngine::KeyState::free;
    _keys[gameEngine::b] = gameEngine::KeyState::free;
    _keys[gameEngine::c] = gameEngine::KeyState::free;
    _keys[gameEngine::d] = gameEngine::KeyState::free;
    _keys[gameEngine::e] = gameEngine::KeyState::free;
    _keys[gameEngine::f] = gameEngine::KeyState::free;
    _keys[gameEngine::g] = gameEngine::KeyState::free;
    _keys[gameEngine::h] = gameEngine::KeyState::free;
    _keys[gameEngine::i] = gameEngine::KeyState::free;
    _keys[gameEngine::j] = gameEngine::KeyState::free;
    _keys[gameEngine::k] = gameEngine::KeyState::free;
    _keys[gameEngine::l] = gameEngine::KeyState::free;
    _keys[gameEngine::m] = gameEngine::KeyState::free;
    _keys[gameEngine::n] = gameEngine::KeyState::free;
    _keys[gameEngine::o] = gameEngine::KeyState::free;
    _keys[gameEngine::p] = gameEngine::KeyState::free;
    _keys[gameEngine::q] = gameEngine::KeyState::free;
    _keys[gameEngine::r] = gameEngine::KeyState::free;
    _keys[gameEngine::s] = gameEngine::KeyState::free;
    _keys[gameEngine::t] = gameEngine::KeyState::free;
    _keys[gameEngine::u] = gameEngine::KeyState::free;
    _keys[gameEngine::v] = gameEngine::KeyState::free;
    _keys[gameEngine::w] = gameEngine::KeyState::free;
    _keys[gameEngine::x] = gameEngine::KeyState::free;
    _keys[gameEngine::y] = gameEngine::KeyState::free;
    _keys[gameEngine::z] = gameEngine::KeyState::free;
    _keys[gameEngine::key0] = gameEngine::KeyState::free;
    _keys[gameEngine::key1] = gameEngine::KeyState::free;
    _keys[gameEngine::key2] = gameEngine::KeyState::free;
    _keys[gameEngine::key3] = gameEngine::KeyState::free;
    _keys[gameEngine::key4] = gameEngine::KeyState::free;
    _keys[gameEngine::key5] = gameEngine::KeyState::free;
    _keys[gameEngine::key6] = gameEngine::KeyState::free;
    _keys[gameEngine::key7] = gameEngine::KeyState::free;
    _keys[gameEngine::key8] = gameEngine::KeyState::free;
    _keys[gameEngine::key9] = gameEngine::KeyState::free;
    _keys[gameEngine::space] = gameEngine::KeyState::free;
    _keys[gameEngine::escape] = gameEngine::KeyState::free;
    _keys[gameEngine::tab] = gameEngine::KeyState::free;
    _keys[gameEngine::caps] = gameEngine::KeyState::free;
    _keys[gameEngine::up] = gameEngine::KeyState::free;
    _keys[gameEngine::left] = gameEngine::KeyState::free;
    _keys[gameEngine::down] = gameEngine::KeyState::free;
    _keys[gameEngine::right] = gameEngine::KeyState::free;

    _rendererClosed = false;
    _mouseState = KeyState::free;
}

gameEngine::SfmlEvent::~SfmlEvent()
{
}

void gameEngine::SfmlEvent::updateReleased()
{
    for (auto i = _keys.begin(); i != _keys.end(); ++i) {
        if (i->second == gameEngine::KeyState::released)
            i->second = gameEngine::KeyState::free;
    }
    if (_mouseState == gameEngine::released)
        _mouseState = gameEngine::free;
}

void gameEngine::SfmlEvent::setKeyState(gameEngine::Key key, gameEngine::KeyState state)
{
    _keys[key] = state;
}

void gameEngine::SfmlEvent::setMouseState(gameEngine::KeyState state)
{
    _mouseState = state;
}

void gameEngine::SfmlEvent::setMousePosition(int x, int y)
{
    _mousePos = std::pair<int,int>(x, y);
}

void gameEngine::SfmlEvent::setRendererClosed(bool state)
{
    _rendererClosed = state;
}

gameEngine::KeyState gameEngine::SfmlEvent::keyState(gameEngine::Key key) const
{
    return _keys.find(key)->second;
}

gameEngine::KeyState gameEngine::SfmlEvent::mouseState() const
{
    return _mouseState;
}

std::pair<int, int> gameEngine::SfmlEvent::getMousePosition() const
{
    return _mousePos;
}

bool gameEngine::SfmlEvent::rendererClosed() const
{
    return _rendererClosed;
}