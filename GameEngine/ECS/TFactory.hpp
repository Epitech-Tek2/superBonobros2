/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** TFactory
*/

#ifndef TFACTORY_HPP_
    #define TFACTORY_HPP_

    #include <map>
    #include <functional>
    #include <memory>
    #include <iostream>

    #include "Error.hpp"

template <class Key, class Object, class... Args>
class TFactory {
    public:
        TFactory(bool overload = true) : _overload(overload) {}
        ~TFactory() = default;

        void learn(Key const& key, std::function<Object(Args...)> const& creator) {
            if (_mapObject.count(key) == 1) {
                if (_overload == false)
                    throw Error("Trying to registre a know component.", "TFactory::registre");
                else
                    _mapObject.at(key) = creator;
            } else
                _mapObject.emplace(key, creator);
        }
        Object create(Key const& key, Args /*&&*/... args) {
            if (_mapObject.count(key) == 0)
                throw Error("Trying to create an unknow component.", "TFactory::create");
            return _mapObject[key](std::forward<Args>(args)...);
        }
    private:
        bool _overload;
        std::map<Key, std::function<Object(Args...)>> _mapObject;
};

#endif /* !TFACTORY_HPP_ */
