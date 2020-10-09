//!////////////////////////////////////////////////////
//!
//! @file           ctx.cpp
//! @brief          Context Implementation
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
#include "ctx.h"

using namespace std;
using namespace fibra;

Context::Context(char const* inputFileName)
        : m_inputFileName(inputFileName)
{
    /*!
     * Checking invariants
     */
    assert(!m_inputFileName.empty());

    const size_t dotFound = m_inputFileName.rfind(".");

    // cout << "dotFound: " << dotFound << endl;

    /*!
     * It is presumed that file extension should be
     * three digits
     * like:
     * file_name.004
     */
    if (string::npos == dotFound
            || dotFound != m_inputFileName.length()-3-1)
    {
        cerr
            << "File extension is not valid:"
            << m_inputFileName
            << endl
            ;
        exit(1);
    }

    /*! getting extension
     */
    const string ext = m_inputFileName.substr(dotFound + 1, 3);

    // cout << "ext: " << ext << endl;

    /*! getting file name without extension
     */
    m_inputFileNameNoExt = m_inputFileName.substr(0, dotFound);

    // cout << "m_inputFileNameNoExt: " << m_inputFileNameNoExt << endl;

    /*! getting starting number
     */
    m_startingNumber = (uint8_t)stoi(ext);

    assert (m_startingNumber > 0);

    // TODO: check for validity of starting number

    // cout << "m_startingNumber: " << (int)m_startingNumber << endl;
}

string Context::getOutputFileName() const
{
    char buff[8];
    sprintf(buff, ".%03d", m_startingNumber+1);
    string outFileName = m_inputFileNameNoExt + string(buff);
    return outFileName;
}

//! TODO
/// investigate and refactor
template <class TFS>
inline ios_base::iostate setExceptionMask(fstrm_ptr<TFS>& fileStream)
{
    const ios_base::iostate exceptionMaskOrig = fileStream->exceptions();
    fileStream->exceptions(exceptionMaskOrig
                | ios::failbit | ifstream::badbit);
    return exceptionMaskOrig;
}


ifstrm_ptr fibra::getInputFStream(Context const& ctx)
{
    //////////////////////////////////////////////////////////////////
    // Input Stream Initialization
    //
    //! \var this is our input stream with rabbit seq
    /// we do using unique pointer here
    ifstrm_ptr inFileStream(new ifstream());

    //! prepare inFileStream to throw if failbit or badbit get set
    const ios_base::iostate inExceptionMaskOrig = setExceptionMask(inFileStream);

    //! opening input stream for reading
    /// in case of error the exception should be thrown
    inFileStream->open(ctx.getInputFileName()
            , std::ifstream::in
                /*!
                    * we want 010101001
                    * not 0 1 0 1 0 1
                    */
                | std::ifstream::binary);

    //! restoring original mask
    inFileStream->exceptions(inExceptionMaskOrig);

    return inFileStream;
}

ofstrm_ptr fibra::getOutputFStream(Context const& ctx)
{
    //////////////////////////////////////////////////////////////////
    // Output Stream Initialization
    //
    //! \var this is our output stream for rabbit seq
    /// we do using unique pointer here
    ofstrm_ptr outFileStream(new ofstream());

    //! prepare inFileStream to throw if failbit or badbit get set
    const ios_base::iostate outExceptionMaskOrig = setExceptionMask(outFileStream);

    //! opening input stream for reading
    /// in case of error the exception should be thrown
    outFileStream->open(ctx.getOutputFileName()
            , std::ofstream::out
                | std::ofstream::binary);

    //! restoring original mask
    outFileStream->exceptions(outExceptionMaskOrig);

    return outFileStream;
}
