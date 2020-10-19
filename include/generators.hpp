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
    namespace gens
    {
        namespace st2
        {
            namespace a
            {
                template <> rabbits_t gen<rabbits::Junior>::generate()
                {
                    return Rabbits(std::make_tuple(1, rabbits_arr_t{rabbits::Mature}));
                }
                template <> rabbits_t gen<rabbits::Mature>::generate()
                {
                    return Rabbits(std::make_tuple(2, rabbits_arr_t{rabbits::Mature, rabbits::Junior}));
                }
            }
        }
        namespace st3
        {
            namespace a
            {
                template <> rabbits_t gen<rabbits::Junior>::generate()
                {
                    return Rabbits(std::make_tuple(1, rabbits_arr_t{rabbits::Mature}));
                }
                template <> rabbits_t gen<rabbits::Mature>::generate()
                {
                    return Rabbits(std::make_tuple(3, rabbits_arr_t{rabbits::Deceased, rabbits::Mature, rabbits::Junior}));
                }
                template <> rabbits_t gen<rabbits::Deceased>::generate()
                {
                    return Rabbits(std::make_tuple(0, rabbits_arr_t{}));
                }
            }
            namespace b
            {
                template <> rabbits_t gen<rabbits::Junior>::generate()
                {
                    return Rabbits(std::make_tuple(2, rabbits_arr_t{rabbits::Mature, rabbits::Junior}));
                }
                template <> rabbits_t gen<rabbits::Mature>::generate()
                {
                    return Rabbits(std::make_tuple(2, rabbits_arr_t{rabbits::Deceased, rabbits::Junior}));
                }
                template <> rabbits_t gen<rabbits::Deceased>::generate()
                {
                    return Rabbits(std::make_tuple(0, rabbits_arr_t{}));
                }
            }
        } // namespace st3
    } // namespace gens
} // namespace fibra
