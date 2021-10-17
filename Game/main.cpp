/*
** EPITECH PROJECT, 2021
** Super-Bonobross-2
** File description:
** main
*/

#include <StdClock.hpp>
#include "Game.hpp"
#include "SfmlUdpSocket.hpp"
#include "SFMLGraphic.hpp"
#include "UdpNetwork.hpp"

int main(void)
{
    auto socket = std::make_unique<server::SfmlUdpSocket>();
    auto network = std::make_unique<gameEngine::UdpNetwork>(socket.get());
    auto graphic = std::make_unique<gameEngine::SFMLGraphic>(1920, 1080);
    auto clock = std::make_unique<StdClock>();
    auto game = std::make_unique<Game>(network.get(), graphic.get());

    while (true) {
        graphic->updateEvent();
        auto evt = graphic->getEvent();

        if (evt->rendererClosed() || !game->isOpen())
            break;

        game->update(clock->elapsedTime());
    }
    return 0;
}