//!////////////////////////////////////////////////////
//!
//! @file           generators.cpp
//! @brief          Generator's static data
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

#include "deps.h"
#include "generators.hpp"

using namespace std;
using namespace fibra;
using namespace fibra::gens;

const st2::gen::arr st2::gen::s_states = { st2::State::JUNIOR, st2::State::MATURE };
const st3::gen::arr st3::gen::s_states = { st3::State::JUNIOR, st3::State::MATURE, st3::State::DECEASED };
