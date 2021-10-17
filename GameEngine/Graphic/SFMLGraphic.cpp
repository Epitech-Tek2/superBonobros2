/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SFMLGraphic
*/

#include <SFML/Window/Mouse.hpp>
#include "SFMLGraphic.hpp"
#include "AEntity.hpp"
#include "Transform2DComponent.hpp"
#include "TextureComponent.hpp"
#include "ShapeComponent.hpp"
#include "TextComponent.hpp"
#include "ECS.hpp"
#include "SfmlEvent.hpp"

#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>

namespace {
    std::unordered_map<sf::Keyboard::Key, gameEngine::Key> SfmlKeys = {
        {sf::Keyboard::Key::A, gameEngine::Key::a},
        {sf::Keyboard::B, gameEngine::b},
        {sf::Keyboard::C, gameEngine::c},
        {sf::Keyboard::D, gameEngine::d},
        {sf::Keyboard::E, gameEngine::e},
        {sf::Keyboard::F, gameEngine::f},
        {sf::Keyboard::G, gameEngine::g},
        {sf::Keyboard::H, gameEngine::h},
        {sf::Keyboard::I, gameEngine::i},
        {sf::Keyboard::J, gameEngine::j},
        {sf::Keyboard::K, gameEngine::k},
        {sf::Keyboard::L, gameEngine::l},
        {sf::Keyboard::M, gameEngine::m},
        {sf::Keyboard::N, gameEngine::n},
        {sf::Keyboard::O, gameEngine::o},
        {sf::Keyboard::P, gameEngine::p},
        {sf::Keyboard::Q, gameEngine::q},
        {sf::Keyboard::R, gameEngine::r},
        {sf::Keyboard::S, gameEngine::s},
        {sf::Keyboard::T, gameEngine::t},
        {sf::Keyboard::U, gameEngine::u},
        {sf::Keyboard::V, gameEngine::v},
        {sf::Keyboard::W, gameEngine::w},
        {sf::Keyboard::X, gameEngine::x},
        {sf::Keyboard::Y, gameEngine::y},
        {sf::Keyboard::Z, gameEngine::z},
        {sf::Keyboard::Num0, gameEngine::key0},
        {sf::Keyboard::Num1, gameEngine::key1},
        {sf::Keyboard::Num2, gameEngine::key2},
        {sf::Keyboard::Num3, gameEngine::key3},
        {sf::Keyboard::Num4, gameEngine::key4},
        {sf::Keyboard::Num5, gameEngine::key5},
        {sf::Keyboard::Num6, gameEngine::key6},
        {sf::Keyboard::Num7, gameEngine::key7},
        {sf::Keyboard::Num8, gameEngine::key8},
        {sf::Keyboard::Num9, gameEngine::key9},
        {sf::Keyboard::Space, gameEngine::space},
        {sf::Keyboard::Escape, gameEngine::escape},
        {sf::Keyboard::Tab, gameEngine::tab},
        {sf::Keyboard::Up, gameEngine::up},
        {sf::Keyboard::Left, gameEngine::left},
        {sf::Keyboard::Down, gameEngine::down},
        {sf::Keyboard::Right, gameEngine::right}
    };
}

gameEngine::SFMLGraphic::SFMLGraphic(unsigned int width, unsigned int height) :
    _renderWindow(sf::VideoMode(width, height), "test", sf::Style::Fullscreen)
{
    _gameSize.x = width;
    _gameSize.y = height;
    _events = std::make_unique<SfmlEvent>();
}

gameEngine::SFMLGraphic::~SFMLGraphic(void)
{
}

size_t gameEngine::SFMLGraphic::loadTexture(std::string const &path)
{
    for (auto &it : _textureMap) {
        if (std::get<0>(it.second) == path)
            return it.first;
    }
    auto texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile(path))
        throw ("Texture " + path + "not found\n");
    _textureMap.emplace(_textureIndex, std::make_tuple(path, texture));
    return _textureIndex++;
}

void gameEngine::SFMLGraphic::playMusic(std::string const &path)
{
    (void)path;
    /*
    if (_music.openFromFile(path)) {
        _music.play();
        _music.setLoop(true);
    }*/
}

void gameEngine::SFMLGraphic::playSound(std::string const &path)
{
    (void)path;
    /*
    for (auto &it : _soundMap) {
        if (std::get<0>(it.second) == path) {
            std::get<2>(it.second)->play();
            return;
        }
    }
    try {
        auto soundBuffer = std::make_shared<sf::SoundBuffer>();
        auto sound = std::make_shared<sf::Sound>();
        if (!soundBuffer->loadFromFile(path))
            throw (std::string("Sound \"" + path + "\" not found\n"));
        sound->setBuffer(*soundBuffer.get());
        sound->play();
        _soundMap.emplace(_soundIndex++, std::make_tuple(path, soundBuffer, sound));
    } catch (std::string const &str) {
        std::cout << str << std::endl;
    }*/
}

void gameEngine::SFMLGraphic::stopMusic()
{
    /*
    if (_music.getStatus() == sf::SoundSource::Status::Playing)
        _music.stop();*/
}

size_t gameEngine::SFMLGraphic::loadFont(std::string const &path)
{
    for (auto &it : _fontMap) {
        if (std::get<0>(it.second) == path)
            return it.first;
    }
    auto font = std::make_shared<sf::Font>();
    if (!font->loadFromFile(path))
        throw ("Font " + path + "not found\n");
    _fontMap.emplace(_fontIndex, std::make_tuple(path, font));
    return _fontIndex++;
}

gameEngine::IEvent const *gameEngine::SFMLGraphic::getEvent() const
{
    return _events.get();
}

void gameEngine::SFMLGraphic::updateEvent(bool updateRealeasedButton)
{
    sf::Event sfEvent;

    if (updateRealeasedButton)
        _events->updateReleased();
    if (_events->mouseState() == gameEngine::KeyState::released)
        _events->setMouseState(gameEngine::KeyState::free);
    _events->setMousePosition(sf::Mouse::getPosition(_renderWindow).x * _gameSize.x / _renderWindow.getSize().x,
        sf::Mouse::getPosition(_renderWindow).y * _gameSize.y / _renderWindow.getSize().y);

    while (_renderWindow.pollEvent(sfEvent)) {
        switch (sfEvent.type) {
            default:
                break;
            case sf::Event::KeyPressed: {
                auto key = SfmlKeys.find(sfEvent.key.code);

                if (key != SfmlKeys.end())
                    _events->setKeyState(key->second, gameEngine::KeyState::pressed);
                break;
            }
            case sf::Event::KeyReleased: {
                auto key = SfmlKeys.find(sfEvent.key.code);

                if (key != SfmlKeys.end())
                    _events->setKeyState(key->second, gameEngine::KeyState::released);
                break;
            }
            case sf::Event::MouseButtonPressed:
                if (sfEvent.mouseButton.button == sf::Mouse::Button::Left)
                    _events->setMouseState(gameEngine::KeyState::pressed);
                break;
            case sf::Event::MouseButtonReleased:
                if (sfEvent.mouseButton.button == sf::Mouse::Button::Left)
                    _events->setMouseState(gameEngine::KeyState::released);
                break;
            case sf::Event::Closed:
                _renderWindow.close();
                _events->setRendererClosed(true);
                break;
        }
    }
}

void gameEngine::SFMLGraphic::draw(const std::shared_ptr<AEntity> entity)
{
    try {
        auto &transform = entity->getEcs()->getEntityComponent<Transform2DComponent>(entity)._transform;
        auto &texture = entity->getEcs()->getEntityComponent<TextureComponent>(entity);
        auto &shape = entity->getEcs()->getEntityComponent<ShapeComponent>(entity);

        if (shape._type == ShapeType::CircleShape) {
            _circle.setOrigin(vector2ToSfVector(transform.getOrigin()));
            _circle.setPosition(vector2ToSfVector(transform.getPosition()));
            _circle.setScale(vector2ToSfVector(transform.getScale()));
            _circle.setRotation(transform.getRotation());
            _circle.setRadius(shape._circle.ray());
            _circle.setFillColor(colorToSfColor(texture._color));
            if (texture._type == TextureType::ColorTexture) {
                _circle.setTexture(&_defaultTexture);
            } else if (texture._type == TextureType::FileTexture) {
                auto it = _textureMap.at(texture._index);
                _circle.setTexture(std::get<1>(it).get());
                _circle.setTextureRect(rectangleToSfRect(texture._rect));
            }
            _renderWindow.draw(_circle);
        } else if (shape._type == ShapeType::RectangleShape) {
            _rect.setOrigin(vector2ToSfVector(transform.getOrigin()));
            _rect.setScale(vector2ToSfVector(transform.getScale()));
            _rect.setPosition(vector2ToSfVector(transform.getPosition()));
            _rect.setSize(sf::Vector2f(shape._rectangle.width(), shape._rectangle.height()));
            _rect.setRotation(transform.getRotation());
            _rect.setFillColor(colorToSfColor(texture._color));
            if (texture._type == TextureType::ColorTexture) {
                _rect.setTexture(&_defaultTexture);
            } else if (texture._type == TextureType::FileTexture) {
                auto it = _textureMap.at(texture._index);
                _rect.setTexture(std::get<1>(it).get());
                _rect.setSize(sf::Vector2f(texture._rect.width(), texture._rect.height()));
                _rect.setTextureRect(rectangleToSfRect(texture._rect));
            }
            _renderWindow.draw(_rect);
        }

    } catch (const char *str) {
    }
    try {
        auto &transform = entity->getEcs()->getEntityComponent<Transform2DComponent>(entity)._transform;
        auto &text = entity->getEcs()->getEntityComponent<TextComponent>(entity);

        _text.setOrigin(vector2ToSfVector(transform.getOrigin()));
        _text.setPosition(vector2ToSfVector(transform.getPosition()));
        _text.setScale(vector2ToSfVector(transform.getScale()));
        _text.setRotation(transform.getRotation());

        _text.setFillColor(colorToSfColor(text._fillColor));
        _text.setOutlineColor(colorToSfColor(text._outlineColor));
        _text.setOutlineThickness(1.0f);

        auto it = _fontMap.at(text._fontIndex);
        _text.setFont(*std::get<1>(it).get());
        _text.setCharacterSize(text._characterSize);
        _text.setString(text._text);

        _renderWindow.draw(_text);

    } catch (const char *str) {
    }
}

void gameEngine::SFMLGraphic::updateScreen(void)
{
    _renderWindow.display();
    _renderWindow.clear();
}

sf::Color gameEngine::SFMLGraphic::colorToSfColor(const gameEngine::Color &color) const
{
    return sf::Color(color.red, color.green, color.blue, color.alpha);
}

const std::string &gameEngine::SFMLGraphic::getTextureName(size_t index)
{
    auto &tuple = _textureMap.at(index);
    return std::get<0>(tuple);
}

const std::string &gameEngine::SFMLGraphic::getFontName(size_t index)
{
    auto &tuple = _fontMap.at(index);
    return std::get<0>(tuple);
}

void gameEngine::SFMLGraphic::setGameSize(const Vector2<unsigned int> &size)
{
    _gameSize = size;
}