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
#include <tuple>

/*! \namespace
 *! @brief      Fibonacci Rabbits
 */
namespace fibra
{
    //! \namespace
    //! @brief      Generators
    namespace gens
    {
        //! @brief      generated rabbits
        //! @todo       1. make tuple, after Rabbit becomes a class
        //!             2. make variadic template
        using rabbits_t = std::tuple<size_t, std::array<rabbits::Rabbit, 3>>;

        //! \namespace
        //! @brief          two state machine
        namespace st2
        {
            //! \namespace
            //! @brief          algo A
            namespace a
            {
                //! \class
                //! @brief          generator class for two state
                //!                 Fibonacci Rabbit's machine
                template <rabbits::Rabbit R>
                struct gen
                {
                    //! @brief      A functor to generate new pairs or Rabbits
                    //! @param[in]  incoming pair of Rabbits
                    static rabbits_t generate();
                };
            }
        } // namespace st3

        //! \namespace
        //! @brief          three state machine
        namespace st3
        {
            //! \namespace
            //! @brief          algo A
            namespace a
            {
                //! \class
                //! @brief          Generator for three state machine algorithm A
                template <rabbits::Rabbit R>
                struct gen
                {
                    //! @brief      A functor to generate new pairs or Rabbits
                    //! @param[in]  incoming pair of Rabbits
                    static rabbits_t generate();
                };
            }
            //! \namespace
            //! @brief          algo A
            namespace b
            {
                //! \class
                //! @brief          Generator for three state machine algorithm B
                template <rabbits::Rabbit R>
                struct gen
                {
                    //! @brief      A functor to generate new pairs or Rabbits
                    //! @param[in]  incoming pair of Rabbits
                    static rabbits_t generate();
                };
            }
        } // namespace st3
    } // namespace gens
} // namespace fibra
