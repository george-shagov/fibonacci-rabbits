//!////////////////////////////////////////////////////
//!
//! @file           processors.hpp
//! @brief          Processors's definitions
//! @author         (c) George Shagov, 2020
//! @date           30th July, 2020
//!
//! License         GPLv3
//!
//!////////////////////////////////////////////////////
//!
//! Version: 1.0
//! Implemented:
//!    * Started
//!
//!////////////////////////////////////////////////////

#pragma once

#include "rabbits.h"
#include "generators.hpp"
#include "processor.h"

/*! \namespace Fibonacci Rabbits
 */
namespace fibra
{
    namespace processors
    {
        gens::rabbits_t generate(const rabbits::STATE state, const ALGO algo, const rabbits::Rabbit rabbit)
        {
            switch (state)
            {
                case rabbits::STATE::ST2:
                    switch (algo)
                    {
                        case ALGO::A:
                            switch (rabbit)
                            {
                                case rabbits::Junior: return gens::st2::gen<rabbits::Junior>::generate(); 
                                case rabbits::Mature: return gens::st2::gen<rabbits::Mature>::generate(); 
                                default: assert(0);
                            }
                        default: assert(0);
                    }
                case rabbits::STATE::ST3:
                    switch (algo)
                    {
                        case ALGO::A:
                            switch (rabbit)
                            {
                                case rabbits::Junior:   return gens::st3::gen_a<rabbits::Junior>::generate();
                                case rabbits::Mature:   return gens::st3::gen_a<rabbits::Mature>::generate();
                                case rabbits::Deceased: return gens::st3::gen_a<rabbits::Deceased>::generate();
                                default: assert(0);
                            }
                        case ALGO::B:
                            switch (rabbit)
                            {
                                case rabbits::Junior:   return gens::st3::gen_b<rabbits::Junior>::generate();
                                case rabbits::Mature:   return gens::st3::gen_b<rabbits::Mature>::generate();
                                case rabbits::Deceased: return gens::st3::gen_a<rabbits::Deceased>::generate();
                                default: assert(0);
                            }
                        default: assert(0);
                    }
                default:
                    assert(0);
            }
        }

        void processor (ifstrm_ptr& inFStream
                            , ofstrm_ptr& outFStream
                            , const rabbits::STATE state
                            , const ALGO algo
                        )
        {
            input_it in_begin(*inFStream);
            input_it in_end;
            output_it out_it(*outFStream);

            for_each (in_begin, in_end,
                    [&out_it, state, algo](const uint8_t ch)
                    {
                        rabbits::Rabbit rabbit = rabbits::translate(ch);
                        gens::rabbits_t rabbits = generate(state, algo, rabbit);

                        for (auto r : std::get<1>(rabbits))
                            *out_it = static_cast<uint8_t>(r);
                    });
        }
    } // namespace processors
} // namespace fibra
