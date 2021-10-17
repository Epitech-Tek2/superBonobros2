/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** IEvent
*/

#ifndef IEVENT_HPP_
#define IEVENT_HPP_

#include <utility>

namespace gameEngine {
enum Key {
    a = 0,
    b,
    c,
    d,
    e,
    f,
    g,
    h,
    i,
    j,
    k,
    l,
    m,
    n,
    o,
    p,
    q,
    r,
    s,
    t,
    u,
    v,
    w,
    x,
    y,
    z,
    key0,
    key1,
    key2,
    key3,
    key4,
    key5,
    key6,
    key7,
    key8,
    key9,
    space,
    escape,
    tab,
    caps,
    up,
    left,
    down,
    right
};

enum KeyState {
    free = 1,
    pressed,
    released
};

class IEvent {
    public:
        virtual ~IEvent() = default;

        virtual void updateReleased() = 0;
        virtual void setKeyState(Key key, KeyState state) = 0;
        virtual void setMouseState(KeyState state) = 0;
        virtual void setMousePosition(int x, int y) = 0;
        virtual void setRendererClosed(bool state) = 0;

        virtual KeyState keyState(Key key) const = 0;
        virtual KeyState mouseState() const = 0;
        virtual std::pair<int, int> getMousePosition() const = 0;
        virtual bool rendererClosed() const = 0;
};
}

#endif /* !IEVENT_HPP_ */