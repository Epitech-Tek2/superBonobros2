/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** Transform
*/

#ifndef TRANSFORM_HPP_

#include "Vector2.hpp"

namespace gameEngine {

    class Transform2D {
        public:
            Transform2D(
                Vector2<float> origin = {0.f, 0.f},
                Vector2<float> position = {0.f, 0.f},
                Vector2<float> scale = {1.f, 1.f},
                float rotation = 0.f
            );
            ~Transform2D();


        void setPosition(float x, float y);
        void setPosition(const Vector2<float> &position);

        void setRotation(float angle);

        void setScale(float factorX, float factorY);
        void setScale(const Vector2<float> &factors);

        void setOrigin(float x, float y);
        void setOrigin(const Vector2<float> &origin);


        const Vector2<float> &getPosition() const;

        float getRotation() const;

        const Vector2<float> &getScale() const;

        const Vector2<float> &getOrigin() const;


        void move(float offsetX, float offsetY);
        void move(const Vector2<float> &offset);

        void rotate(float angle);

        void scale(float factorX, float factorY);
        void scale(const Vector2<float> &factor);


        Vector2<float> transformPoint(float x, float y);
        Vector2<float> transformPoint(const Vector2<float> &point);

        private:
            Vector2<float> _origin;
            Vector2<float> _position;
            Vector2<float> _scale;
            float _rotation;
            bool _matrixNeedUpdate;
            float _matrix[16];

            void updadeMatrix(void);
            void UpdateMatrixIfNeeded(void);
    };

};

#endif /* !TRANSFORM_HPP_ */
