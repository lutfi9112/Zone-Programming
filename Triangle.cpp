#include "Triangle.h"

Triangle::Triangle(Vec2d first, Vec2d second, Vec2d third)
{
    points[0] = first;
    points[1] = second;
    points[2] = third;
}

int Triangle::isInside(Vec2d test)
{
    auto ab = points[1] - points[0];
    auto ac = points[2] - points[0];
    auto ap = test - points[0];
    if (ab.x == 0 && ac.y == 0) {
        return 2;
    }
    else if (ab.y == 0 || ab.x == 0) {
        ab = points[2] - points[1];
    }
    else if (ac.y == 0 || ac.x == 0) {
        ac = points[2] - points[1];
    }

    float w1 = (points[0].x * ac.y + ap.y * ac.x - test.x * ac.y) / (ab.y * ac.x - ab.x * ac.y);
    float w2 = (test.y - points[0].y - w1 * ab.y) / ac.y;
    if (w1 >= 0 && w2 >= 0 && w1 + w2 <= 1)
        return 1;
    else
        return 0;
}
