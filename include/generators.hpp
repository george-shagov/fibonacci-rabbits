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
            template <> rabbits_t gen<rabbits::Junior>::generate()
            {
                return {rabbits::Mature};
            }
            template <> rabbits_t gen<rabbits::Mature>::generate()
            {
                return {rabbits::Mature, rabbits::Junior};
            }
        }
        namespace st3
        {
            template <> rabbits_t gen_a<rabbits::Junior>::generate()
            {
                return {rabbits::Mature};
            }
            template <> rabbits_t gen_a<rabbits::Mature>::generate()
            {
                return {rabbits::Deceased, rabbits::Mature, rabbits::Junior};
            }
            template <> rabbits_t gen_a<rabbits::Deceased>::generate()
            {
                return {};
            }
            template <> rabbits_t gen_b<rabbits::Junior>::generate()
            {
                return {rabbits::Mature, rabbits::Junior};
            }
            template <> rabbits_t gen_b<rabbits::Mature>::generate()
            {
                return {rabbits::Deceased, rabbits::Junior};
            }
            template <> rabbits_t gen_b<rabbits::Deceased>::generate()
            {
                return {};
            }
        } // namespace st3
    } // namespace gens
} // namespace fibra
