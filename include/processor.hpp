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
        //! @brief      Helper class to call upon corresponded generator for two state machine
        template <template <rabbits::Rabbit R> class G>
        gens::rabbits_t gen2(rabbits::Rabbit rabbit)
        {
            switch(rabbit)
            {
                case rabbits::Junior: return G<rabbits::Junior>::generate();
                case rabbits::Mature: return G<rabbits::Mature>::generate();
                default: assert(0);
            }
        }
        //! @brief      Helper class to call upon corresponded generator for three state machine
        template <template <rabbits::Rabbit R> class G>
        gens::rabbits_t gen3(rabbits::Rabbit rabbit)
        {
            switch(rabbit)
            {
                case rabbits::Junior:   return G<rabbits::Junior>::generate();
                case rabbits::Mature:   return G<rabbits::Mature>::generate();
                case rabbits::Deceased: return G<rabbits::Deceased>::generate();
                default: assert(0);
            }
        }
        //! \fn
        //! brief   Helper Function to generate rabbits deneding of incoming parameters
        //!
        //! @param[in]      state
        //!                 this is either two or three state machine
        //! @param[in]      algo
        //!                 either A or B
        //! @param[in]      rabbit
        //!                 a rabbit
        gens::rabbits_t generate(const rabbits::STATE state, const ALGO algo, const rabbits::Rabbit rabbit)
        {
            switch (state)
            {
                case rabbits::STATE::ST2:
                    switch (algo)
                    {
                        case ALGO::A:
                            return gen2<gens::st2::a::gen>(rabbit);
                        default: assert(0);
                    }
                case rabbits::STATE::ST3:
                    switch (algo)
                    {
                        case ALGO::A:
                            return gen3<gens::st3::a::gen>(rabbit);
                        case ALGO::B:
                            return gen3<gens::st3::b::gen>(rabbit);
                        case ALGO::C:
                            return gen3<gens::st3::c::gen>(rabbit);
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

                        for (auto i=0; i<rabbits.size(); ++i)
                            *out_it = static_cast<uint8_t>(rabbits[i]);
                    });
        }
    } // namespace processors
} // namespace fibra
