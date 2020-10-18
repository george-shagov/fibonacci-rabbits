//!////////////////////////////////////////////////////
//!
//! @file           processors.h
//! @brief          Processors's declarations
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

/*! \namespace
 */
namespace fibra
{
    namespace processors
    {
        enum class ALGO { A, B };

        template <rabbits::Rabbit R>
        constexpr gens::rabbits_t generate(const rabbits::STATE state, const ALGO algo);
        //! \fn
        //! @brief          Processor function/algo to transfer the data from source
        //!                 r-seq file 00# to destination r-seq file 00#+1
        //! @param[in]      inFStream
        //!                 input File Stream with suurce Fibonacci Rabbit's sequence
        //! @param[in]      outFStream
        //!                 output File Stream to generate Fibonacci Rabbit's sequence
        void processor (ifstrm_ptr& inFStream
                            , ofstrm_ptr& outFStream
                            , const rabbits::STATE state
                            , const ALGO algo
                        );
    }
} // namespace fibra
