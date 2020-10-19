//!////////////////////////////////////////////////////
//!
//! @file           generators.hpp
//! @brief          Generator's definitions
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

/*! \namespace Fibonacci Rabbits
 */
namespace fibra
{
    //! \namespace Generators
    namespace gens
    {
        namespace st2
        {
            namespace a
            {
                template <> rabbits_t gen<rabbits::Junior>::generate()
                {
                    return std::make_tuple(1, std::array<rabbits::Rabbit,3>{rabbits::Mature});
                }
                template <> rabbits_t gen<rabbits::Mature>::generate()
                {
                    return std::make_tuple(2, std::array<rabbits::Rabbit,3>{rabbits::Mature, rabbits::Junior});
                }
            }
        }
        namespace st3
        {
            namespace a
            {
                template <> rabbits_t gen<rabbits::Junior>::generate()
                {
                    return std::make_tuple(1, std::array<rabbits::Rabbit,3>{rabbits::Mature});
                }
                template <> rabbits_t gen<rabbits::Mature>::generate()
                {
                    return std::make_tuple(3, std::array<rabbits::Rabbit,3>{rabbits::Deceased, rabbits::Mature, rabbits::Junior});
                }
                template <> rabbits_t gen<rabbits::Deceased>::generate()
                {
                    return std::make_tuple(0, std::array<rabbits::Rabbit,3>{});
                }
            }
            namespace b
            {
                template <> rabbits_t gen<rabbits::Junior>::generate()
                {
                    return std::make_tuple(2, std::array<rabbits::Rabbit,3>{rabbits::Mature, rabbits::Junior});
                }
                template <> rabbits_t gen<rabbits::Mature>::generate()
                {
                    return std::make_tuple(2, std::array<rabbits::Rabbit,3>{rabbits::Deceased, rabbits::Junior});
                }
                template <> rabbits_t gen<rabbits::Deceased>::generate()
                {
                    return std::make_tuple(0, std::array<rabbits::Rabbit,3>{});
                }
            }
        } // namespace st3
    } // namespace gens
} // namespace fibra
