#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <iostream>

#include "deps.h"
#include "rabbits.hpp"
#include "generators.hpp"
#include "processor.hpp"
#include "ctx.h"

using namespace std;
using namespace fibra;

TEST_CASE( "TWO State Machine", "[main]" )
{
    SECTION("Algo A - Junior")
    {
        gens::rabbits_t rabbits = processors::generate(rabbits::STATE::ST2, processors::ALGO::A, rabbits::Junior);
        REQUIRE(get<0>(rabbits) == 1);
        REQUIRE(get<1>(rabbits)[0] == rabbits::Mature);
    }
    SECTION("Algo A - Mature")
    {
        gens::rabbits_t rabbits = processors::generate(rabbits::STATE::ST2, processors::ALGO::A, rabbits::Mature);
        REQUIRE(get<0>(rabbits) == 2);
        REQUIRE(get<1>(rabbits)[0] == rabbits::Mature);
        REQUIRE(get<1>(rabbits)[1] == rabbits::Junior);
    }
}

TEST_CASE( "Three State Machine", "[main]" )
{
    SECTION("Algo A - Junior")
    {
        gens::rabbits_t rabbits = processors::generate(rabbits::STATE::ST3, processors::ALGO::A, rabbits::Junior);
        REQUIRE(get<0>(rabbits) == 1);
        REQUIRE(get<1>(rabbits)[0] == rabbits::Mature);
    }
    SECTION("Algo A - Mature")
    {
        gens::rabbits_t rabbits = processors::generate(rabbits::STATE::ST3, processors::ALGO::A, rabbits::Mature);
        REQUIRE(get<0>(rabbits) == 3);
        REQUIRE(get<1>(rabbits)[0] == rabbits::Deceased);
        REQUIRE(get<1>(rabbits)[1] == rabbits::Mature);
        REQUIRE(get<1>(rabbits)[2] == rabbits::Junior);
    }
}

