/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SAT
*/

#ifndef SAT_HPP_
#define SAT_HPP_

#include <array>

#include "Transform2DComponent.hpp"
#include "ShapeComponent.hpp"

namespace gameEngine {

    class SAT {
        public:
            SAT(void);
            ~SAT(void);

            static bool collide(Transform2DComponent &transform1, const ShapeComponent &shape1,
                Transform2DComponent &transform2, const ShapeComponent &shape2);
            static bool collide(Transform2DComponent &transform, const ShapeComponent &shape, const Vector2<float> &point);

        protected:
        private:
            using Vec4 = std::array<Vector2<float>, 4>;

            static bool collide(Vec4 &bounce1, Vec4 &bounce2);
            static void projectOntoAxis(const Vector2<float> &axis, float &min, float &max, const Vec4 &points);
            static void projectOntoAxis(const Vector2<float> &axis, Vector2<float> &min, Vector2<float> &max, const Vec4 &points);
            static Vector2<float> projectOntoAxis(float x, float y, const Vec4 &points);
            static Vec4 getRectBounce(Transform2DComponent &transform, const ShapeComponent &shape);
            static Vec4 getComplexeRectBounce(Transform2DComponent &transform, const ShapeComponent &shape);
            static Vec4 getEdgeNormal(const Vec4 &rect);
            static int posCompare(const Vector2<float> &v1, const Vector2<float> &v2);

    };
};

#endif /* !SAT_HPP_ */
