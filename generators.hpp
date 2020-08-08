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
            std::size_t gen::operator() (const uint8_t in_char
                                        , arr& vals) const
            {
                switch (static_cast<State>(in_char))
                {
                    //! Mature's Breed
                    case State::MATURE:
                        vals[0] = s_states[static_cast<std::size_t>(Index::MATURE)];
                        vals[1] = s_states[static_cast<std::size_t>(Index::JUNIOR)];
                        return 2;
                    //! Junior's Breed
                    case State::JUNIOR:
                        vals[0] = s_states[static_cast<std::size_t>(Index::MATURE)];
                        return 1;
                    default:
                        /*! this practically means we do ignore
                        *! all "non-valid" characters
                        */
                        return 0;
                }
            }
        }
        namespace st3
        {
            std::size_t gen_a::operator() (const uint8_t in_char
                                        , arr& vals) const
            {
                switch (static_cast<State>(in_char))
                {
                    //! Mature's Breed
                    case State::MATURE:
                        vals[0] = s_states[static_cast<std::size_t>(Index::DECEASED)];
                        vals[1] = s_states[static_cast<std::size_t>(Index::MATURE)];
                        vals[2] = s_states[static_cast<std::size_t>(Index::JUNIOR)];
                        return 3;
                    //! Junior's Breed
                    case State::JUNIOR:
                        vals[0] = s_states[static_cast<std::size_t>(Index::MATURE)];
                        return 1;
                    //! Deceased's Breed
                    case State::DECEASED:
                        return 0;
                    default:
                        /*! this practically means we do ignore
                        *! all "non-valid" characters
                        */
                        return 0;
                }
            }
            std::size_t gen_b::operator() (const uint8_t in_char
                                        , arr& vals) const
            {
                switch (static_cast<State>(in_char))
                {
                    //! Mature's Breed
                    case State::MATURE:
                        vals[0] = s_states[static_cast<std::size_t>(Index::DECEASED)];
                        vals[1] = s_states[static_cast<std::size_t>(Index::JUNIOR)];
                        return 2;
                    //! Junior's Breed
                    case State::JUNIOR:
                        vals[0] = s_states[static_cast<std::size_t>(Index::MATURE)];
                        vals[1] = s_states[static_cast<std::size_t>(Index::JUNIOR)];
                        return 2;
                    //! Deceased's Breed
                    case State::DECEASED:
                        return 0;
                    default:
                        /*! this practically means we do ignore
                        *! all "non-valid" characters
                        */
                        return 0;
                }
            }
        }
    }
} // namespace fibra
