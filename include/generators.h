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
    //! @brief      Generators
    namespace gens
    {
        //! \namespace
        //! @brief          two state machine
        namespace st2
        {
            //! \enum
            //! @brief          this should keep the values of
            //!                 Fibonacci Rabbits
            //! @details        Possible values: '0' '1'
            //!                 where:
            //!                     '0' - junior pair of rabbits
            //!                     '1' - mature pair or rabbits
            enum class State : uint8_t
            {
                    JUNIOR = '0'
                ,   FIRST  = JUNIOR
                ,   MATURE = '1'
                ,   LAST   = MATURE
            };

            //! \enum
            //! @brief          this should keep the indexes of
            //!                 Fibonacci Rabbits
            //! @details        Possible values: 0 1
            //!                 where
            //!                     0 - junior pair of rabbits
            //!                     1 - mature pair or rabbits
            enum class Index : std::size_t
            {
                    JUNIOR = 0
                ,   FIRST  = JUNIOR
                ,   MATURE = 1
                ,   LAST   = MATURE
            };

            //! \class
            //! @brief          generator class for two state
            //!                 Fibonacci Rabbit's machine
            struct gen
            {
                //! @brief      this is a return type of newly generated
                //!             pairs of rabbits
                using arr = std::array<State, 2>;

                //! @brief      A functor to generate new pairs or Rabbits
                //! @param[in]  in_char
                //!             incoming pair of Rabbits
                //! @param[in]  vals
                //!             generated pairs of Rabbits
                std::size_t operator() (const uint8_t in_char
                                            , arr& vals) const;

                //! @brief      static array to keep the values of
                //!             Juniors and Mature Rabbits
                static const arr s_states;
            };
        }

        //! \namespace
        //! @brief          three state machine
        namespace st3
        {
            //! \class
            //! @bried          this should keep the values of
            //!                 Fibonacci Rabbits
            //! @details        Possible States:
            //!                 '0' '1' '2'
            //!                 where:
            //!                     '0' - junior pair of rabbits
            //!                     '1' - mature pair or rabbits
            //!                     '2' - deceased pair or rabbits
            enum class State : uint8_t
            {
                    JUNIOR = '0'
                ,   FIRST  = JUNIOR
                ,   MATURE = '1'
                ,   DECEASED = '2'
                ,   LAST   = DECEASED
            };

            //! \class
            //! @brief          this should keep the indexes of
            //!                 Fibonacci Rabbits
            //! @details        Possible Values: 0 1
            //!                 where
            //!                     0 - junior pair of rabbits
            //!                     1 - mature pair or rabbits
            //!                     2 - deceased pair or rabbits
            enum class Index : std::size_t
            {
                    JUNIOR = 0
                ,   FIRST  = JUNIOR
                ,   MATURE = 1
                ,   DECEASED = 2
                ,   LAST   = DECEASED
            };

            //! \class
            //! @brief          Generator for three state machine
            struct gen
            {
                //! @brief      this is a return type of newly generated
                //!             pairs of rabbits
                using arr = std::array<State, 3>;

                //          //! \fn
                //          //! @brief      A functor to generate new pairs or Rabbits
                //          //! @param[in]  in_char
                //          //!             incoming pair of Rabbits
                //          //! @param[in]  vals
                //          //!             generated pairs of Rabbits
                //          virtual std::size_t operator() (const uint8_t in_char
                //                                         , arr& vals) const = 0;

                //! @brief      Static member to keep the state values
                //!             for generator
                static const arr s_states;
            };
            //! \class
            //! @brief          Generator for three state machine
            //!                 algorithm A
            struct gen_a : gen
            {
                //! @brief      A functor to generate new pairs or Rabbits
                //! @param[in]  in_char
                //!             incoming pair of Rabbits
                //! @param[in]  vals
                //!             generated pairs of Rabbits
                std::size_t operator() (const uint8_t in_char
                                       , arr& vals) const;
            };
            //! \class
            //! @brief          Generator for three state machine
            //!                 algorithm B
            struct gen_b : gen
            {
                //! @brief      A functor to generate new pairs or Rabbits
                //! @param[in]  in_char
                //!             incoming pair of Rabbits
                //! @param[in]  vals
                //!             generated pairs of Rabbits
                std::size_t operator() (const uint8_t in_char
                                        , arr& vals) const;
            };
        }
    } // namespace gens
} // namespace fibra
