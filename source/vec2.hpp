#ifndef VEC2_HPP
#define VEC2_HPP

struct Vec2{
    float x = 0.0f;
    float y = 0.0f;

    Vec2& operator +=(Vec2 const&  v);
    Vec2& operator -=(Vec2 const&  v);
    Vec2& operator *=(float v);
    Vec2& operator /=(float v);
};

#endif