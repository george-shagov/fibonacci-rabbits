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

TEST_CASE( "TWO State Machine", "[main]" ) {

    SECTION("Algo A")
    {
        gens::rabbits_t rabbits = gens::st2::gen<rabbits::Junior>::generate();
        REQUIRE(get<0>(rabbits) == 1);
        REQUIRE(get<1>(rabbits)[0] == rabbits::Mature);
    }

}

