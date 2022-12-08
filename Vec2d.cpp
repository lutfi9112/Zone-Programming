#include "Vec2d.h"

Vec2d Vec2d::operator+(const Vec2d& another)
{
   return Vec2d{ x + another.x,y + another.y };
}

Vec2d Vec2d::operator-(const Vec2d& another)
{
    return Vec2d{ x - another.x,y - another.y };
}

auto Vec2d::operator+=(const Vec2d& another)
{
    x += another.x;
    y += another.y;
}

auto Vec2d::operator-=(const Vec2d& another)
{
    x -= another.x;
    y -= another.y;
}

auto Vec2d::gradient(const Vec2d& another)
{
    return (y - another.y) / (x - another.x);
}

auto Vec2d::yIntercept(const Vec2d& another)
{
    return y - gradient(another) * x;
}

