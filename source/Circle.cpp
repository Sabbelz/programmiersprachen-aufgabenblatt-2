#include "Circle.hpp"
#include <cmath>
#include "color.hpp"

Circle::Circle():
    radius_{1},
    center_ {1},
    col_ {0.5,0.5,0.5}
{}
Circle::Circle(float radius, float center, Color col):
    radius_{radius},
    center_{center},
    col_{col}
{}

float Circle::circumference() const{
    float u = 2*M_PI * radius_;
    return u;
}
void Circle::draw(Window const& w) const{

}