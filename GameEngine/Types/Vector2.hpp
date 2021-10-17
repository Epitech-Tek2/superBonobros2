/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Vector2
*/

#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

#include <cmath>
#include <iostream>

namespace gameEngine {

    template <typename T>
    class Vector2 {
        public:

            inline Vector2() : x(0), y(0) {}

            inline Vector2(T X, T Y) : x(X), y(Y) {}


            template <typename U>
            inline Vector2(const Vector2<U>& vector) :
                x(static_cast<T>(vector.x)), y(static_cast<T>(vector.y)) {}

            template <typename U>
            inline Vector2(U X, U Y) :
                x(static_cast<T>(X)), y(static_cast<T>(Y)) {}

            inline Vector2<T> getNormal(void)
            {
                return Vector2<T>(y, -x);
            }

            inline double getMagnetude(void)
            {
                return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
            }

            Vector2<T> getNormalize(void)
            {
                double mag = getMagnetude();
                return (Vector2<T>(x, y) / (static_cast <float>(mag)));
            }

            T x;
            T y;
    };

    template <typename T>
    inline Vector2<T> operator -(const Vector2<T>& right)
    {
        return Vector2<T>(-right.x, -right.y);
    }

    template <typename T>
    inline Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right)
    {
        left.x += right.x;
        left.y += right.y;

        return left;
    }

    template <typename T>
    inline Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right)
    {
        left.x -= right.x;
        left.y -= right.y;

        return left;
    }

    template <typename T>
    inline Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right)
    {
        return Vector2<T>(left.x + right.x, left.y + right.y);
    }

    template <typename T>
    inline Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right)
    {
        return Vector2<T>(left.x - right.x, left.y - right.y);
    }

    template <typename T>
    inline Vector2<T> operator *(const Vector2<T>& left, T right)
    {
        return Vector2<T>(left.x * right, left.y * right);
    }

    template <typename T>
    inline Vector2<T> operator *(T left, const Vector2<T>& right)
    {
        return Vector2<T>(right.x * left, right.y * left);
    }

    template <typename T>
    inline Vector2<T> operator *(const Vector2<T>& left, const Vector2<T>& right)
    {
        return Vector2<T>(right.x * left.x, right.y * left.y);
    }

    template <typename T>
    inline Vector2<T>& operator *=(Vector2<T>& left, T right)
    {
        left.x *= right;
        left.y *= right;

        return left;
    }

    template <typename T>
    inline Vector2<T> operator /(const Vector2<T>& left, T right)
    {
        return Vector2<T>(left.x / right, left.y / right);
    }

    template <typename T>
    inline Vector2<T>& operator /=(Vector2<T>& left, T right)
    {
        left.x /= right;
        left.y /= right;

        return left;
    }

    template <typename T>
    inline bool operator ==(const Vector2<T>& left, const Vector2<T>& right)
    {
        return (left.x == right.x) && (left.y == right.y);
    }

    template <typename T>
    inline bool operator !=(const Vector2<T>& left, const Vector2<T>& right)
    {
        return (left.x != right.x) || (left.y != right.y);
    }

};

#endif /* !VECTOR2_HPP_ */
