/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** SAT
*/

#include "SAT.hpp"

gameEngine::SAT::SAT()
{
}

gameEngine::SAT::~SAT()
{
}

bool gameEngine::SAT::collide(
    Transform2DComponent &transform1, const ShapeComponent &shape1,
    Transform2DComponent &transform2, const ShapeComponent &shape2
)
{
    Vec4 bounce1;
    Vec4 bounce2;

    if (shape1._type == ShapeType::RectangleShape) {
        if (shape1._isComplex)
            bounce1 = getComplexeRectBounce(transform1, shape1);
        else
            bounce1 = getRectBounce(transform1, shape1);
    } else
        return false;
    if (shape2._type == ShapeType::RectangleShape) {
        if (shape2._isComplex)
            bounce2 = getComplexeRectBounce(transform2, shape2);
        else
            bounce2 = getRectBounce(transform2, shape2);
    }
    else
        return false;
    return collide(bounce1, bounce2);
}

bool gameEngine::SAT::collide(
    Transform2DComponent &transform, const ShapeComponent &shape,
    const Vector2<float> &point
)
{
    Vec4 bounce1;
    Vec4 bounce2;

    if (shape._type == ShapeType::RectangleShape) {
        if (shape._isComplex)
            bounce1 = getComplexeRectBounce(transform, shape);
        else
            bounce1 = getRectBounce(transform, shape);
    } else
        return false;
    bounce2 = {point, point + Vector2<float>(0.01, 0), point + Vector2<float>(0.01, 0.01), point + Vector2<float>(0, 0.01)};
    return collide(bounce1, bounce2);
}

void gameEngine::SAT::projectOntoAxis(const Vector2<float> &axis, Vector2<float> &min, Vector2<float> &max, const Vec4 &points)
{
    Vector2<float> projection;
    min = points[0] * axis;
    max = min;

    for (int i = 1; i < 4; ++i) {
        projection = points[i] * axis;
        if (posCompare(projection, min) == -1)
            min = projection;
        if (posCompare(projection, max) == 1)
            max = projection;
    }
}

gameEngine::Vector2<float> gameEngine::SAT::projectOntoAxis(float x, float y, const Vec4 &points)
{
    float min = 10000000000;
    float max = -10000000000;
    for (int i = 0; i < 4; i++) {
        float px = points[i].x;
        float py = points[i].y;
        float projection = (px * x + py * y) / (std::sqrt(x * x + y * y));
        if (projection > max) {
            max = projection;
        }
        if (projection < min) {
            min = projection;
        }
    }
    return { min, max };
}

gameEngine::SAT::Vec4 gameEngine::SAT::getRectBounce(Transform2DComponent &transform, const ShapeComponent &shape)
{
    float xMin = shape._rectangle.posX();
    float yMin = shape._rectangle.posY();
    float xMax = xMin + shape._rectangle.width();
    float yMax = yMin + shape._rectangle.height();
    Vec4 points = {
        transform._transform.transformPoint(xMin, yMin),
        transform._transform.transformPoint(xMax, yMin),
        transform._transform.transformPoint(xMax, yMax),
        transform._transform.transformPoint(xMin, yMax)
    };

    return points;
}

gameEngine::SAT::Vec4 gameEngine::SAT::getComplexeRectBounce(Transform2DComponent &transform, const ShapeComponent &shape)
{
    Vec4 points = {
        transform._transform.transformPoint(shape._complexBounce[0]),
        transform._transform.transformPoint(shape._complexBounce[1]),
        transform._transform.transformPoint(shape._complexBounce[2]),
        transform._transform.transformPoint(shape._complexBounce[3])
    };

    return points;
}

gameEngine::SAT::Vec4 gameEngine::SAT::getEdgeNormal(const Vec4 &rect)
{
    Vec4 normal;
    Vector2<float> p1;
    Vector2<float> p2;
    Vector2<float> edge;

    for (int i = 0; i < 4; i++) {
        if (i + 1 != 4) {
            p1 = rect[i];
            p2 = rect[i + 1];
        } else {
            p1 = rect[i];
            p2 = rect[0];
        }
        edge = p1 - p2;
        normal[i] = edge.getNormal();
        normal[i] = normal[i].getNormalize();
    }
    return normal;
}

int gameEngine::SAT::posCompare(const Vector2<float> &v1, const Vector2<float> &v2)
{
    if (v1.y < v2.y || (v1.y == v2.y && v1.x < v2.x))
        return -1;
    if (v1.y > v2.y || (v1.y == v2.y && v1.x > v2.x))
        return 1;
    return 0;
}

float intervalDistance(float minA, float maxA, float minB, float maxB) {
    if (minA < minB) {
        return (minB - maxA);
    }
    return (minA - maxB);
}

bool gameEngine::SAT::collide(Vec4 &bounce1, Vec4 &bounce2)
{
    Vec4 normal1 = getEdgeNormal(bounce1);
    Vec4 normal2 = getEdgeNormal(bounce2);

    std::array<Vector2<float>, 8> normals;
    int it = 0;

    for (int i = 0; i < 4; ++i)
        normals[it++] = normal1[i];
    for (int i = 0; i < 4; ++i)
        normals[it++] = normal2[i];

    Vector2<float> Rect1;
    Vector2<float> Rect2;

    for (int i = 0; i < 8; ++i) {
        Rect1 = projectOntoAxis(normals[i].x, normals[i].y, bounce1);
        Rect2 = projectOntoAxis(normals[i].x, normals[i].y, bounce2);
        if (intervalDistance(Rect1.x, Rect1.y, Rect2.x, Rect2.y) > 0) {
            return false;
        }
    }

    return true;
}