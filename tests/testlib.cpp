#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <iostream>

#include "deps.h"
#include "rabbits.hpp"
#include "generators.hpp"
#include "processor.hpp"

using namespace std;
using namespace fibra;

TEST_CASE( "TWO State Machine - Algo A", "[main]" )
{
    SECTION("Junior")
    {
        gens::rabbits_t rabbits = processors::generate(rabbits::STATE::ST2, processors::ALGO::A, rabbits::Junior);
        REQUIRE(rabbits.size() == 1);
        REQUIRE(rabbits[0] == rabbits::Mature);
    }
    SECTION("Mature")
    {
        gens::rabbits_t rabbits = processors::generate(rabbits::STATE::ST2, processors::ALGO::A, rabbits::Mature);
        REQUIRE(rabbits.size() == 2);
        REQUIRE(rabbits[0] == rabbits::Mature);
        REQUIRE(rabbits[1] == rabbits::Junior);
    }
}

TEST_CASE( "Three State Machine - Algo A", "[main]" )
{
    SECTION("Junior")
    {
        gens::rabbits_t rabbits = processors::generate(rabbits::STATE::ST3, processors::ALGO::A, rabbits::Junior);
        REQUIRE(rabbits.size() == 1);
        REQUIRE(rabbits[0] == rabbits::Mature);
    }
    SECTION("Mature")
    {
        gens::rabbits_t rabbits = processors::generate(rabbits::STATE::ST3, processors::ALGO::A, rabbits::Mature);
        REQUIRE(rabbits.size() == 3);
        REQUIRE(rabbits[0] == rabbits::Deceased);
        REQUIRE(rabbits[1] == rabbits::Mature);
        REQUIRE(rabbits[2] == rabbits::Junior);
    }
    SECTION("Deceased")
    {
        gens::rabbits_t rabbits = processors::generate(rabbits::STATE::ST3, processors::ALGO::A, rabbits::Deceased);
        REQUIRE(rabbits.size() == 0);
    }
}

TEST_CASE( "Three State Machine - Algo B", "[main]" )
{
    SECTION("Junior")
    {
        gens::rabbits_t rabbits = processors::generate(rabbits::STATE::ST3, processors::ALGO::B, rabbits::Junior);
        REQUIRE(rabbits.size() == 2);
        REQUIRE(rabbits[0] == rabbits::Mature);
        REQUIRE(rabbits[1] == rabbits::Junior);
    }
    SECTION("Mature")
    {
        gens::rabbits_t rabbits = processors::generate(rabbits::STATE::ST3, processors::ALGO::B, rabbits::Mature);
        REQUIRE(rabbits.size() == 2);
        REQUIRE(rabbits[0] == rabbits::Deceased);
        REQUIRE(rabbits[1] == rabbits::Junior);
    }
    SECTION("Deceased")
    {
        gens::rabbits_t rabbits = processors::generate(rabbits::STATE::ST3, processors::ALGO::B, rabbits::Deceased);
        REQUIRE(rabbits.size() == 0);
    }
}

