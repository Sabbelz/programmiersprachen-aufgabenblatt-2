#include "Circle.hpp"
#include <cmath>
#include "color.hpp"

Circle::Circle():
    radius_{100.0f},
    center_ {200,200},
    col_ {1.0f,0.0f,0.0f}
{}
Circle::Circle(float radius, Vec2 center, Color col):
    radius_{radius},
    center_{center},
    col_{col}
{}

float Circle::circumference() const{
    float u = 2*M_PI * radius_;
    return u;
}
void Circle::draw(Window const& w) const{
    Vec2 sp{center_.x, center_.y - radius_};         //startpunkt
    for(int i = 0; i < 200; ++i){
        float phi = ((2 * M_PI)/200);                //phi für rotation
        Mat2 rm = make_rotation_mat2(phi);           //Rotation
        Vec2 np = center_ + (rm * (sp - center_));   //neuer punkt
        w.draw_line(sp.x, sp.y, np.x, np.y, col_.r,col_.g,col_.b);
        sp = np;
    }
}
void Circle::draw(Window const& w, float thickness) const{
    Vec2 sp{center_.x, center_.y - radius_};
    if(thickness > 0){
        for(int i = 0; i < 200; ++i){
            float phi = ((2 * M_PI)/200);
            Mat2 rm = make_rotation_mat2(phi);
            Vec2 np = center_ + (rm * (sp - center_));
            w.draw_line(sp.x, sp.y, np.x, np.y, col_.r,col_.g,col_.b, thickness);
            sp = np;
        }
    }
}
bool Circle::is_inside(Vec2 const& p) const{
    Vec2 rv = p - center_;
    Vec2 sp{center_.x, center_.y - radius_};
    float norm_1 = sqrt(pow(rv.x,2) + pow(rv.y,2));
    float norm_2 = sqrt(pow(sp.x,2) + pow(sp.y,2));
    if(norm_1 > norm_2){
        std::cout << "Der angegebene Punkt liegt außerhalb des Objektes.\n";
        return false;
    }
    else{
        std::cout << "Der angegebene Punkt liegt innerhalb des Objektes.\n";
        return true;
    }
}