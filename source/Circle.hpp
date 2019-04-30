#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "color.hpp"
#include "window.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include <iostream>

class Circle{
    public:
    Circle();
    Circle(float radius, Vec2 center, Color col);
    float circumference() const;
    void draw(Window const& w) const;
    void draw(Window const& w, float thickness) const;
    bool is_inside(Vec2 const& p) const;

    private:
    Color col_;
    Vec2 center_;
    float radius_;

};

#endif