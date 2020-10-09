//!////////////////////////////////////////////////////
//!
//! @file           deps.h
//! @brief          Dependencies
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

#include <iostream>
#include <fstream>      // std::ifstream
#include <string>
#include <cassert>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <memory>
#include <cstdio>
#include <functional>
#include <array>

#include <inttypes.h>
#include <errno.h>
#include <limits.h>

/*! \namespace Fibonacci Rabbits
 *! these types are not expected to be the subjects
 *! for frequent changes
 */
namespace fibra
{
    template <typename T>
    struct FStrmDeleter
    {
        void operator() (T* fs) { fs->close(); }
    };

    template <typename TFS>
    using fstrm_ptr = std::unique_ptr<TFS, FStrmDeleter<TFS> >;
    using ifstrm_ptr = fstrm_ptr<std::ifstream>;
    using ofstrm_ptr = fstrm_ptr<std::ofstream>;
    using input_it = std::istream_iterator<uint8_t>;
    using output_it = std::ostream_iterator<uint8_t>;
}
