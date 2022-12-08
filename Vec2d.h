#pragma once
class Vec2d {
public:
    double x = 0.0f;
    double y = 0.0f;
    Vec2d() {}
    Vec2d(double x, double y) :x(x), y(y) {}
    Vec2d operator+(const Vec2d& another);
    Vec2d operator-(const Vec2d& another);
    auto operator+=(const Vec2d& another);
    auto operator-=(const Vec2d& another);
    auto gradient(const Vec2d& another);
    auto yIntercept(const Vec2d& another);
};

