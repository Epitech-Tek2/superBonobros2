/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SFMLGraphic
*/

#ifndef SFMLGRAPHIC_HPP_
#define SFMLGRAPHIC_HPP_

#include <map>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include "IGraphic.hpp"
#include "Vector2.hpp"
#include "Color.hpp"
#include "Rectangle.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace gameEngine {

    class SFMLGraphic : virtual public IGraphic {
        public:
            SFMLGraphic(unsigned int width = 800, unsigned int height = 600);
            ~SFMLGraphic(void);

            size_t loadTexture(std::string const &);
            void playMusic(std::string const &);
            void playSound(std::string const &);
            void stopMusic();
            size_t loadFont(std::string const &);

            const std::string &getTextureName(size_t index);
            const std::string &getFontName(size_t index);

            IEvent const *getEvent() const final;
            void updateEvent(bool updateRealeasedButton = true) final;

            void draw(const std::shared_ptr<AEntity> entity);

            void setGameSize(const Vector2<unsigned int> &size);

            void updateScreen(void);

        private:
            sf::RenderWindow _renderWindow;
            Vector2<unsigned int> _gameSize;
            std::map<std::size_t, std::tuple<std::string const, std::shared_ptr<sf::Texture>>> _textureMap;
            //std::map<std::size_t, std::tuple<std::string const, std::shared_ptr<sf::SoundBuffer>, std::shared_ptr<sf::Sound>>> _soundMap;
            std::map<std::size_t, std::tuple<std::string const, std::shared_ptr<sf::Font>>> _fontMap;
            std::unique_ptr<IEvent> _events;
            std::size_t _textureIndex = 1;
            std::size_t _musicIndex = 1;
            std::size_t _soundIndex = 1;
            std::size_t _fontIndex = 1;
            sf::RectangleShape _rect;
            sf::CircleShape _circle;
            sf::Text _text;
            sf::Texture _defaultTexture;
            //sf::Music _music;

            template <typename T>
            inline sf::Vector2<T> vector2ToSfVector(const gameEngine::Vector2<T> &vec) const
            {
                return sf::Vector2<T>(vec.x, vec.y);
            }

            template <typename T>
            inline sf::Rect<T> rectangleToSfRect(const gameEngine::Rectangle<T> &rect) const
            {
                return sf::Rect<T>(rect.posX(), rect.posY(), rect.width(), rect.height());
            }

            inline sf::Color colorToSfColor(const gameEngine::Color &color) const;
    };
}

#endif /* !SFMLGRAPHIC_HPP_ */
