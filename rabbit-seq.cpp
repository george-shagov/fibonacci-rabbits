//!////////////////////////////////////////////////////
//!
//! @file           rabbit-seq.cpp
//! @brief          Main file
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
#include "generators.h"
#include "processor.hpp"
#include "ctx.h"

using namespace std;
using namespace fibra;


//! \fn
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr
            << argv[0]
            << " Usage: <input r-seq file>"
            << endl
            ;
        exit(1);
    }

    const Context ctx(argv[1]);

    try
    {
        //////////////////////////////////////////////////////////////////
        // Input Stream Initialization
        //
        //! this is our input stream of rabbit seq
        /// unique pointer is going to be used here
        ifstrm_ptr inFileStream = getInputFStream(ctx);

        //////////////////////////////////////////////////////////////////
        // Output Stream Initialization
        //
        //! this is our output stream for rabbit seq
        /// unique pointer is going to be used here
        ofstrm_ptr outFileStream = getOutputFStream(ctx);

        cout << "Growing "
             << ctx.getInputFileName()
             << " to: "
             << ctx.getOutputFileName()
             << " ... "
             ;

        /////////////////////////////////////////////////////////////////
        //! this is an Entry Point for Rabbit Generator
        //! two state machine
        // processor<gens::st2::gen>(inFileStream, outFileStream);
        //! three state machine algo A
        processor<gens::st3::gen_a>(inFileStream, outFileStream);
        //! three state machine algo B
        // processor<gens::st3::gen_b>(inFileStream, outFileStream);

        cout << "Done." << endl;
    }
    catch (ifstream::failure& e)
    {
        cerr << "File Error: " << e.what() << endl;
        exit (1);
    }
    catch (exception& e)
    {
        cerr << "General Error: " << e.what() << endl;
        exit (1);
    }

    return 0;
}

