#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <iostream>

class Rectangle{
    public:
    Rectangle();
    Rectangle(Vec2 min, Vec2 max, Color col);
    float circumference() const;
    void draw(Window const& w)const;
    void draw(Window const& w, float thickness) const;
    void draw(Window const& w, Color col) const;
    bool is_inside(Vec2 const& p) const;

    private:

    Vec2 min_;
    Vec2 max_;
    Color col_;

};

#endif
