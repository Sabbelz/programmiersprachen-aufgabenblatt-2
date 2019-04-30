#include "Rectangle.hpp"
#include <cmath>
#include "color.hpp"

Rectangle::Rectangle():
    min_{500.0f,300.0f},
    max_{400.0f,200.0f},
    col_{0.0f,0.0f,1.0f}
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
/*float startX, float startY,
                float endX, float endY,
                float r, float g, float b,
                float thickness = 1.0*/

void Rectangle::draw(Window const& w)const{
    w.draw_line(min_.x, min_.y, max_.x, min_.y, col_.r, col_.g, col_.b);
    w.draw_line(min_.x, max_.y, max_.x, max_.y, col_.r, col_.g, col_.b);
    w.draw_line(min_.x, min_.y, min_.x, max_.y, col_.r, col_.g, col_.b);
    w.draw_line(max_.x, min_.y, max_.x, max_.y, col_.r, col_.g, col_.b);
}
void Rectangle::draw(Window const& w, float thickness)const{
    if (thickness > 0){
        w.draw_line(min_.x, min_.y, max_.x, min_.y, col_.r, col_.g, col_.b, thickness);
        w.draw_line(min_.x, max_.y, max_.x, max_.y, col_.r, col_.g, col_.b, thickness);
        w.draw_line(min_.x, min_.y, min_.x, max_.y, col_.r, col_.g, col_.b, thickness);
        w.draw_line(max_.x, min_.y, max_.x, max_.y, col_.r, col_.g, col_.b, thickness);
    }
}
//bool Rectangle::is_inside(Vec2 const& p) const{

//}