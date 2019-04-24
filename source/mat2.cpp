#include "mat2.hpp"
#include "vec2.hpp"

Mat2& Mat2::operator*=(Mat2 const& m){
    float a = e_00;
    float b = e_01;
    float c = e_10;
    float d = e_11;

    e_00 = a*m.e_00 + b*m.e_10;
    e_01 = a*m.e_10 + b*m.e_11;
    e_10 = c*m.e_00 + d*m.e_01;
    e_11 = c*m.e_01 + d*m.e_11;
    return *this;
}
Mat2 operator*(Mat2 const & m1 , Mat2 const & m2){
    return Mat2(m1) *= m2;
}
Vec2 operator*(Mat2 const & m , Vec2 const & v){
    float a = m.e_00 * v.x + m.e_01*v.y;
    float b = m.e_10 * v.x + m.e_11*v.y;
    Vec2 c {a,b};
    return c;
}
Vec2 operator*(Vec2 const & v, Mat2 const & m){
    Vec2 a = m*v;
    return a;
}
