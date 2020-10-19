//!////////////////////////////////////////////////////
//!
//! @file           generators.h
//! @brief          Generator's declarations
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
 *! @brief      Fibonacci Rabbits
 */
namespace fibra
{
    namespace rabbits
    {
        Rabbit translate(const uint8_t c)
        {
            switch (c)
            {
                case '0': return Junior;
                case '1': return Mature;
                case '2': return Deceased;
                default:  return RABBIT::INVALID;
            }
        }
    } // namespace rabbits
} // namespace fibra
