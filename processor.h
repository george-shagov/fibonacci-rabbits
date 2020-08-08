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

/*! \namespace
 */
namespace fibra
{
    //! \fn
    //! @brief          Processor function/algo to transfer the data from source
    //!                 r-seq file 00# to destination r-seq file 00#+1
    //! @param[in]      inFStream
    //!                 input File Stream with suurce Fibonacci Rabbit's sequence
    //! @param[in]      outFStream
    //!                 output File Stream to generate Fibonacci Rabbit's sequence
    template <class TG>
    void processor (ifstrm_ptr& inFStream
                        , ofstrm_ptr& outFStream
                    );
} // namespace fibra
