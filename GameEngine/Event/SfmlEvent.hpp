/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SfmlEvent
*/

#ifndef SFMLEVENT_HPP_
#define SFMLEVENT_HPP_

#include "IEvent.hpp"

#include <unordered_map>

namespace gameEngine
{
class SfmlEvent : public gameEngine::IEvent {
    public:
        SfmlEvent();
        SfmlEvent(SfmlEvent const &) = default;
        ~SfmlEvent();

        SfmlEvent &operator=(SfmlEvent const &) = default;

        void updateReleased() final;
        void setKeyState(gameEngine::Key key, gameEngine::KeyState state) final;
        void setMouseState(gameEngine::KeyState state) final;
        void setMousePosition(int x, int y) final;
        void setRendererClosed(bool state) final;

        gameEngine::KeyState keyState(gameEngine::Key key) const final;
        gameEngine::KeyState mouseState() const final;
        std::pair<int, int> getMousePosition() const final;
        bool rendererClosed() const final;

    private:
        std::unordered_map<gameEngine::Key, gameEngine::KeyState> _keys;
        std::pair<int, int> _mousePos;
        gameEngine::KeyState _mouseState;
        bool _rendererClosed;
};
}

#endif /* !SFMLEVENT_HPP_ */