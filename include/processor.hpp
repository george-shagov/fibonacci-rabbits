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

#include "generators.h"
#include "processor.h"

/*! \namespace Fibonacci Rabbits
 */
namespace fibra
{
    template <typename TG>
    void processor (ifstrm_ptr& inFStream
                        , ofstrm_ptr& outFStream
                    )
    {
        input_it in_begin(*inFStream);
        input_it in_end;
        output_it out_it(*outFStream);

        for_each (in_begin, in_end,
                [&out_it](uint8_t ch)
                {
                    typename TG::arr vals;
                    TG gen;
                    std::size_t cnt = gen(ch, vals);
                    for (std::size_t i=0; i<cnt; ++i)
                        *out_it = static_cast<uint8_t>(vals[i]);
                });
    }
} // namespace fibra
