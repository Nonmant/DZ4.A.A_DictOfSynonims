#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
    "3\n"
    "Hello Hi\n"
    "Bye Goodbye\n"
    "List Array\n"
    "Goodbye"
    ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();
    
    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    REQUIRE(buffer.str() ==
            "Bye"
    );
}

TEST_CASE("test 2", ""){
    std::stringstream input(
            "1\n"
            "beep Car\n"
            "Car"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
    "beep"
    );
}

TEST_CASE("test 3", ""){
    std::stringstream input(
            "2\n"
            "Ololo Ololo\n"
            "Numbers 1234567890\n"
            "Numbers"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
    "1234567890"
    );
}
