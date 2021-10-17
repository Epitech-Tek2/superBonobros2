/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

namespace gameEngine {

    class Color {
        public:
            Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) :
                red(r), green(g), blue(b), alpha(a) {}
            ~Color() = default;

            unsigned char red;
            unsigned char green;
            unsigned char blue;
            unsigned char alpha;
    };

}

#endif /* !COLOR_HPP_ */