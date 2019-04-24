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
float Mat2:: det () const{
    float result = e_00*e_11 - e_01*e_10;
    return result;
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
Mat2 inverse (Mat2 const & m){
    Mat2 temp;
    float adj = 1/(m.e_00*m.e_11-m.e_01*m.e_10);
    temp.e_00 = adj * m.e_00;
    temp.e_01 = adj * -(m.e_01);
    temp.e_10 = adj * -(m.e_10);
    temp.e_11 = adj * m.e_11;
    return temp;
}
Mat2 transpose (Mat2 const& m){
    Mat2 temp{m};
    temp.e_01 = m.e_10;
    temp.e_10 = m.e_01;
    return temp;
}