#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include <cmath>


TEST_CASE("niy", "[niy]"){
  Vec2 a;
  Vec2 b{5.1f,-9.3f};
  REQUIRE(a.x == 0.0f);
  REQUIRE(a.y == 0.0f);
  REQUIRE(b.x == 5.1f);
  REQUIRE(b.y == -9.3f);
}

TEST_CASE("operator+=", "[+=]"){
  Vec2 a;
  Vec2 b{5.1f, -9.3f};
  a += b;
  REQUIRE(a.x == b.x);
  REQUIRE(a.y == b.y);
}
TEST_CASE("operator-=", "[-=]"){
  Vec2 a;
  Vec2 b{5.1f, -9.3f};
  a -= b;
  REQUIRE(a.x == -(b.x));
  REQUIRE(a.y == -(b.y));
}
TEST_CASE("operator*=", "[*=]"){
  float a = 2.0f;
  Vec2 b{5.0f, -9.0f};
  b *= a;
  REQUIRE(b.x == 10.0f);
  REQUIRE(b.y == -18.0f);
}
TEST_CASE("operator/=", "[/=]"){
  float a = 3.0f;
  Vec2 b{9.0f, 6.0f};
  b /= a;
  REQUIRE(b.x == 3.0f);
  REQUIRE(b.y == 2.0f);
}
TEST_CASE("operator+", "[+]"){
  Vec2 a{3.0f, 5.0f};
  Vec2 b{9.0f, 6.0f};
  Vec2 c = a + b; 
  REQUIRE(c.x == 12.0f);
  REQUIRE(c.y == 11.0f);
}
TEST_CASE("operator-", "[-]"){
  Vec2 a{3.0f, 5.0f};
  Vec2 b{9.0f, 6.0f};
  Vec2 c = a - b;
  REQUIRE(c.x == -6.0f);
  REQUIRE(c.y == -1.0f);
}
TEST_CASE("operator*", "[*]"){
  float a = 3.0f;
  Vec2 b{9.0f, 6.0f};
  Vec2 c = b * a;
  Vec2 d = a * b;
  REQUIRE(c.x == 27.0f);
  REQUIRE(c.y == 18.0f);
  REQUIRE(d.x == 27.0f);
  REQUIRE(d.y == 18.0f);
}
TEST_CASE("operator/", "[/]"){
  float a = 3.0f;
  Vec2 b{9.0f, 6.0f};
  Vec2 c = b/a;
  REQUIRE(c.x == 3.0f);
  REQUIRE(c.y == 2.0f);
}
TEST_CASE("M_operator*=", "[M_*=]"){
  Mat2 a{1.0f,0.0f,0.0f,1.0f};
  Mat2 b{2.0f,3.0f,1.0f,1.0f};
  b*=a;
  REQUIRE(b.e_00 == 2.0f);
  REQUIRE(b.e_01 == 3.0f);
  REQUIRE(b.e_10 == 1.0f);
  REQUIRE(b.e_11 == 1.0f);
}
TEST_CASE("M_operator*", "[M_*]"){
  Mat2 a{1.0f,0.0f,0.0f,1.0f};
  Mat2 b{2.0f,3.0f,1.0f,1.0f};
  Mat2 c = b*a;
  REQUIRE(c.e_00 == 2.0f);
  REQUIRE(c.e_01 == 3.0f);
  REQUIRE(c.e_10 == 1.0f);
  REQUIRE(c.e_11 == 1.0f);
}
TEST_CASE("VM_operator*", "[VM_*]"){
  Mat2 a{1.0f,0.0f,0.0f,1.0f};
  Vec2 b{2.0f, 3.0f};
  Vec2 c = a * b;
  REQUIRE(c.x == 2.0f);
  REQUIRE(c.y == 3.0f);
}
TEST_CASE("MV_operator*", "[MV_*]"){
  Mat2 a{1.0f,0.0f,0.0f,1.0f};
  Vec2 b{2.0f, 3.0f};
  Vec2 c = b * a;
  REQUIRE(c.x == 2.0f);
  REQUIRE(c.y == 3.0f);
}
TEST_CASE("inverse", "[inv]"){
  Mat2 a{1.0f,2.0f,-2.0f,1.0f};
  REQUIRE(inverse(a).e_00 == 0.2f);
  REQUIRE(inverse(a).e_01 == -0.4f);
  REQUIRE(inverse(a).e_10 == 0.4f);
  REQUIRE(inverse(a).e_11 == 0.2f);
}
TEST_CASE("M_det", "[det]"){
  Mat2 a{1.0f,0.0f,0.0f,1.0f};
  REQUIRE(a.det() == 1.0f);
}
TEST_CASE("M_transpose", "[trp]"){
  Mat2 a{1.0f,2.0f,-2.0f,1.0f};
  REQUIRE(transpose(a).e_01 == -2.0f);
  REQUIRE(transpose(a).e_10 == 2.0f);
}
TEST_CASE("rotate", "[rt]"){
  Vec2 a{0.0f,0.0f};
  Mat2 t = make_rotation_mat2(M_PI/2);
  Vec2 rr = a * t;
  REQUIRE(rr.x == Approx(0.0f));
  REQUIRE(rr.y == Approx(0.0f));
}
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
