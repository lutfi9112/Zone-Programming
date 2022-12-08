#pragma once
#include"Vec2d.h"
class Triangle {
public:
    Vec2d points[3];
    Triangle() {}
    Triangle(Vec2d first, Vec2d second, Vec2d third);
    int isInside(Vec2d test);

};

