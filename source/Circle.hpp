#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "color.hpp"

class Circle{
    public:
    Circle();
    Circle(float radius, float center, Color col);
    float circumference() const;
    /*void radius(float rad);
    void color (Color col);
    */
    private:
    float radius_;
    Color col_;
    float center_;
};


#endif