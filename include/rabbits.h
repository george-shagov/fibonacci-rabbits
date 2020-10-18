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

/*! \namespace
 *! @brief      Fibonacci Rabbits
 */
namespace fibra
{
    //! \namespace
    //! @brief          Rabbits
    namespace rabbits
    {
        //! \enum
        //! @brief          this should keep the values of Fibonacci Rabbits
        //!
        //! @details        Possible values: '0' '1'
        //!                 where:
        //!                     '0' - junior pair of rabbits
        //!                     '1' - mature pair or rabbits
        //!                     '2' - deceased pair or rabbits
        enum class RABBIT : uint8_t
        {
                JUNIOR   = '0'
            ,   FIRST    = JUNIOR
            ,   MATURE   = '1'
            ,   DECEASED = '2'
            ,   LAST     = DECEASED
            ,   INVALID  = 'X'
        };

        using Rabbit = RABBIT;

        //! @biref      Could/Should be classes
        const Rabbit Junior   = RABBIT::JUNIOR;
        const Rabbit Mature   = RABBIT::MATURE;
        const Rabbit Deceased = RABBIT::DECEASED;

        enum class STATE { ST2, ST3 };

        Rabbit translate(const uint8_t);

    } // namespace rabbits
} // namespace fibra
