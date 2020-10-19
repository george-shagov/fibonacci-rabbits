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
    //! \namespace
    //! @brief      Generators
    namespace gens
    {
        //! @brief  Helper type, array of rabbits
        using rabbits_arr_t = std::array<rabbits::Rabbit, 3>;

        //! @brief      generated rabbits
        //! @todo       1. make tuple, after Rabbit becomes a class
        //!             2. make variadic template
        using rabbits_tpl_t = std::tuple<size_t, rabbits_arr_t>;

        //! @brief      Helper class container for generated Rabbits
        class Rabbits
        {
        public:
            Rabbits(rabbits_tpl_t&& t) : m_tpl(t) {}
            size_t size() const { return std::get<0>(m_tpl); }
            rabbits::Rabbit operator [] (size_t idx) const { assert(idx<size()); return std::get<1>(m_tpl)[idx]; }
        private:
            const rabbits_tpl_t m_tpl;
        };

        //! @biref      typedefing
        using rabbits_t = Rabbits;

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
