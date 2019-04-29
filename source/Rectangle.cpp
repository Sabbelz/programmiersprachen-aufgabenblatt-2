#include "Rectangle.hpp"
#include <cmath>
#include "color.hpp"

Rectangle::Rectangle():
    min_{1,0},
    max_{2,0},
    col_{0.5,0.5,0.5}
{}
Rectangle::Rectangle(Vec2 min, Vec2 max, Color col):
    min_{min},
    max_{max},
    col_{col}
{}

float Rectangle::circumference() const{
    float a = max_.x - min_.x;
    float b = max_.y - min_.y;
    float u = 2*(a+b);
    return u;
}