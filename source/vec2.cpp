#include "vec2.hpp"

Vec2& Vec2::operator +=(Vec2 const&  v){
    x += v.x;
    y += v.y;
    return *this;
}
Vec2& Vec2::operator -=(Vec2 const&  v){
    x -= v.x;
    y -= v.y;
    return *this;
}
Vec2& Vec2::operator *=(float v){
    x *= v;
    y *= v;
    return *this;
}
Vec2& Vec2::operator /=(float v){
    x /= v;
    y /= v;
    return *this;
}