#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "TransformChar.hpp"

#include <vector>

// test alphabetical characters

TEST_CASE("Testing alphabetical character transformation", "[alphabetical]") {
    std::vector<std::string> uppercase{"A", "B", "C", "D", "E", "F", "G", "H", "I",
                                       "J", "K", "L", "M", "N", "O", "P", "Q", "R",
                                       "S", "T", "U", "V", "W", "X", "Y", "Z"};
    std::vector<char> lowercase{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                                'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                                's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    for (size_t i = 0; i < lowercase.size(); i++) {
        REQUIRE( transformChar(lowercase[i]) ==  uppercase[i] );
    }
}

// test numerical characters

TEST_CASE("Testing numerical character transformation", "[numerical]") {
    REQUIRE(transformChar('0') == "ZERO");
    REQUIRE(transformChar('1') == "ONE");
    REQUIRE(transformChar('2') == "TWO");
    REQUIRE(transformChar('3') == "THREE");
    REQUIRE(transformChar('4') == "FOUR");
    REQUIRE(transformChar('5') == "FIVE");
    REQUIRE(transformChar('6') == "SIX");
    REQUIRE(transformChar('7') == "SEVEN");
    REQUIRE(transformChar('8') == "EIGHT");
    REQUIRE(transformChar('9') == "NINE");
}

// test other characters

TEST_CASE("Testing non-alpha character transformation", "[nonalpha]") {
    std::vector<char> nonalpha{'%', '$', '!', '/', '?', '=', '_', '-', '+'};
    
    for (size_t i = 0; i < nonalpha.size(); i++) {
        REQUIRE(transformChar(nonalpha[i]) ==  "");
    }
}

