#pragma once

#include <functional>

struct IntVector2
{

    static const IntVector2 ZERO;
    static const IntVector2 LEFT;
    static const IntVector2 RIGHT;
    static const IntVector2 UP;
    static const IntVector2 DOWN;

    explicit IntVector2(int x = 0, int y = 0)
        : x(x), y(y)
    {
    }

    IntVector2 operator+(const IntVector2 &other) const
    {
        return IntVector2(x + other.x, y + other.y);
    }

    IntVector2 operator-(const IntVector2 &other) const
    {
        return IntVector2(x - other.x, y - other.y);
    }

    IntVector2 operator*(int scalar) const
    {
        return IntVector2(x * scalar, y * scalar);
    }

    IntVector2 operator/(int scalar) const
    {
        return IntVector2(x / scalar, y / scalar);
    }

    IntVector2 &operator+=(const IntVector2 &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    bool operator==(const IntVector2 &) const = default;

    int x;
    int y;
};

template <>
struct std::hash<IntVector2>
{
    std::size_t operator()(const IntVector2 &k) const
    {
        using std::hash;
        using std::size_t;

        // Compute has for 2d point vectors

        return ((hash<int>()(k.x) ^ (hash<int>()(k.y) << 1)) >> 1);
    }
};