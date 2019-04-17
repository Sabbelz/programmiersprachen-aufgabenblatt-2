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
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
