#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

#include <string>

CaesarCipher testCipherDefault {""};

std::string testKey = "5";
CaesarCipher testCipher {testKey};

const std::string testShift = "ABCDE";
const std::string testWrap = "VWXYZ";

const std::string result1 = "FGHIJ";
const std::string result2 = "QRSTU";

TEST_CASE("Testing the Caesar Cipher encryption mode", "[encrypt]") {

    CipherMode mode{CipherMode::encrypt};

    SECTION("Testing the default Caesar Cipher behaviour") {

        std::string test1 = testCipherDefault.applyCipher(testShift, mode);
        std::string test2 = testCipherDefault.applyCipher(testWrap, mode);

        REQUIRE(test1 == testShift);
        REQUIRE(test2 == testWrap);

    }
    SECTION("Testing the Caesar Cipher Behaviour with key testKey") {

        std::string test1 = testCipher.applyCipher(testShift, mode);
        std::string test2 = testCipher.applyCipher(testWrap, mode);

        REQUIRE(test1 == result1);
        REQUIRE(test2 == testShift);

    }

}

TEST_CASE("Testing the Caesar Cipher decryption mode", "[decrypt]") {

    CipherMode mode{CipherMode::decrypt};

    SECTION("Testing the default Caesar Cipher behaviour") {

        std::string test1 = testCipherDefault.applyCipher(testShift, mode);
        std::string test2 = testCipherDefault.applyCipher(testWrap, mode);

        REQUIRE(test1 == testShift);
        REQUIRE(test2 == testWrap);

    }
    SECTION("Testing the Caesar Cipher Behaviour with key testKey") {

        std::string test1 = testCipher.applyCipher(testShift, mode);
        std::string test2 = testCipher.applyCipher(testWrap, mode);

        REQUIRE(test1 == testWrap);
        REQUIRE(test2 == result2);
        
    }

}
