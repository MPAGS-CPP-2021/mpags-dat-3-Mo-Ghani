#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ProcessCommandLine.hpp"

#include <string>
#include <vector>

// Test settings are changed according to valid command line args

TEST_CASE("Testing obtaining settings from valid arguments", "[args]") {
    std::vector<std::string> test1 {"./mpags-cipher", "-i", "inputFile.txt",
                                    "-o", "outputFile.txt", "-k", "5"}; 
    std::vector<std::string> test2 {"./mpags-cipher", "-k", "5", "--encrypt"};
    std::vector<std::string> test3 {"./mpags-cipher", "-k", "5", "--decrypt"};
    std::vector<std::string> test4 {"./mpags-cipher", "--help"};
    std::vector<std::string> test5 {"./mpags-cipher", "--version"};

    ProgramSettings settings;

    bool processed = processCommandLine(test1, settings);
    REQUIRE(processed == true);
    REQUIRE(settings.inputFile == "inputFile.txt");
    REQUIRE(settings.outputFile == "outputFile.txt");
    REQUIRE(settings.cipherKey == "5");

    processed = processCommandLine(test2, settings);
    REQUIRE(processed == true);
    REQUIRE(settings.encrypt == true);

    processed = processCommandLine(test3, settings);
    REQUIRE(processed == true);
    REQUIRE(settings.encrypt == false);

    processed = processCommandLine(test4, settings);
    REQUIRE(processed == true);
    REQUIRE(settings.helpRequested == true);

    processed = processCommandLine(test5, settings);
    REQUIRE(processed == true);
    REQUIRE(settings.versionRequested == true);
}

// test program exits after receiving invalid command line arguments

TEST_CASE("Testing identification of invalid arguments", "[args]") {
    std::vector<std::string> test1 {"./mpags-cipher", "-i"}; 
    std::vector<std::string> test2 {"./mpags-cipher", "-k", "5", "encrypt"};
    std::vector<std::string> test3 {"./mpags-cipher", "-k"};

    ProgramSettings settings;

    bool processed = processCommandLine(test1, settings);
    REQUIRE(processed == false);

    processed = processCommandLine(test2, settings);
    REQUIRE(processed == false);

    processed = processCommandLine(test3, settings);
    REQUIRE(processed == false);
}
