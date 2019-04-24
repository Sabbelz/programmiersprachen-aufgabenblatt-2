#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"


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
  Mat2 c = b * a;
  REQUIRE(c.e_00 == 2.0f);
  REQUIRE(c.e_01 == 3.0f);
  REQUIRE(c.e_10 == 1.0f);
  REQUIRE(c.e_11 == 1.0f);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
