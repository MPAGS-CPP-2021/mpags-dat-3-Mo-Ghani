#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Addition works", "[maths]") {
    REQUIRE(1 + 1 == 2);
}