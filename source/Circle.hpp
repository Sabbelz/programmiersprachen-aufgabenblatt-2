#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "color.hpp"
#include "window.hpp"

class Circle{
    public:
    Circle();
    Circle(float radius, float center, Color col);
    float circumference() const;
    void draw(Window const& w) const;

    private:
    float radius_;
    Color col_;
    float center_;
};


#endif