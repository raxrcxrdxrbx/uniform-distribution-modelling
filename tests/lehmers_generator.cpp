#include <catch2/catch.hpp>
#include <iostream>
#include <stdexcept>

#include "lehmers_generator.h"

TEST_CASE( "Generator must be initialized" ) {

    SECTION( "No parameters & no size given for generator" ) {

        LehmersGenerator::Generate();

        REQUIRE(LehmersGenerator::GetSize() == 0 );
        REQUIRE(LehmersGenerator::GetMaxNumber() == LehmersGenerator::GENERATOR_FAIL);
        REQUIRE(LehmersGenerator::GetMinNumber() == LehmersGenerator::GENERATOR_FAIL);
    }

    SECTION( "No size given for generator" ) {

        LehmersGenerator::SetParams(3, 5, 1);
        LehmersGenerator::Generate();

        REQUIRE(LehmersGenerator::GetSize() == 0 );
        REQUIRE(LehmersGenerator::GetMaxNumber() == LehmersGenerator::GENERATOR_FAIL);
        REQUIRE(LehmersGenerator::GetMinNumber() == LehmersGenerator::GENERATOR_FAIL);
    }

    SECTION( "Initialized generator" ) {

        LehmersGenerator::SetSize(10);
        LehmersGenerator::Generate();

        REQUIRE(LehmersGenerator::GetSize() == 10 );
        REQUIRE(LehmersGenerator::GetMaxNumber() != LehmersGenerator::GENERATOR_FAIL);
        REQUIRE(LehmersGenerator::GetMinNumber() != LehmersGenerator::GENERATOR_FAIL);

    }
}
