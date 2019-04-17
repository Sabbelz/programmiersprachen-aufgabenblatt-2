#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"


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
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
