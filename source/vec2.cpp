#include "vec2.hpp"
#include <iostream>
Vec2& Vec2::operator+=(Vec2 const&  v){
    x += v.x;
    y += v.y;
    return *this;
}
Vec2& Vec2::operator-=(Vec2 const&  v){
    x -= v.x;
    y -= v.y;
    return *this;
}
Vec2& Vec2::operator*=(float v){
    x *= v;
    y *= v;
    return *this;
}
Vec2& Vec2::operator/=(float v){
    if(v == 0){
        Vec2 result{0,0};
        std::cout << "Division mit 0 nicht möglich!\n";
        return result;
    }
    x /= v;
    y /= v;
    return *this;
}

Vec2 operator+(Vec2 const& u, Vec2 const& v){
    return Vec2(u) += v;
}
Vec2 operator-(Vec2 const& u, Vec2 const& v){
    return Vec2(u) -= v;
}
Vec2 operator*(Vec2 const& v, float s){
    return Vec2(v) *= s;
}
Vec2 operator/(Vec2 const& v, float s){
    return Vec2(v) /= s;
}
Vec2 operator*(float s, Vec2 const& v){
    return Vec2(v) *= s;
}
