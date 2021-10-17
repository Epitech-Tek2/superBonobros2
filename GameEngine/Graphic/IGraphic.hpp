/*
** EPITECH PROJECT, 2020
** R-Type
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

#include <string>
#include <cstddef>
#include <memory>

#include "Vector2.hpp"

namespace gameEngine {

    class IEvent;

    class AEntity;

    class IGraphic {
        public:
            virtual ~IGraphic() = default;

            virtual size_t loadTexture(std::string const &) = 0;
            virtual void playMusic(std::string const &) = 0;
            virtual void playSound(std::string const &) = 0;
            virtual void stopMusic() = 0;
            virtual size_t loadFont(std::string const &) = 0;

            virtual const std::string &getTextureName(size_t index) = 0;
            virtual const std::string &getFontName(size_t index) = 0;

            virtual void draw(const std::shared_ptr<AEntity> entity) = 0;

            virtual void updateScreen(void) = 0;

            virtual void updateEvent(bool updateRealeasedButton = true) = 0;
            virtual IEvent const *getEvent() const = 0;

            virtual void setGameSize(const Vector2<unsigned int> &size) = 0;
    };
}

#endif /* !IGRAPHIC_HPP_ */