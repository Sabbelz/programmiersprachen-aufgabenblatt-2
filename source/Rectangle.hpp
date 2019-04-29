#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"

class Rectangle{
    public:
    Rectangle();
    Rectangle(Vec2 min, Vec2 max, Color col);
    float circumference() const;

    private:

    Vec2 min_;
    Vec2 max_;
    Color col_;

};

#endif
