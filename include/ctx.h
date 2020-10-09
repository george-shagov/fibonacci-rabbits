//!////////////////////////////////////////////////////
//!
//! @file           ctx.h
//! @brief          Context Declaration
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

namespace fibra
{
    //! \struct Context
    //! Context struct is being used
    //! to keep the config/context parameters
    class Context
    {
    private:
        //! \var m_inputFileName
        //! Input/Start File Name
        const std::string m_inputFileName;

        //! \var m_inputFileNameNoExt
        //! Input/Start File Name no Extension
        mutable std::string m_inputFileNameNoExt;

        //! \var m_startingNumber
        //! Starting Number to start withal
        mutable uint8_t m_startingNumber = 0;

    public:
        //! \fn Context::Context
        //! Context Constructor / Initialization
        //! @param inputFileName    input file with Rabbit Sequence
        //!                         to start withal
        Context( char const* inputFileName) ;

        std::string getInputFileName() const { return m_inputFileName; }

        //! \fn             Context::getOutputFileName
        //! @returns        Output File Name
        //! @brief          Compiles and returns Output File Name
        //!                 of Rabbit Sequnce to follow
        std::string getOutputFileName() const;
    };

    //! \fn             getInputFStream
    //! @param[in]      ctx - Context
    //! @returns        Input File Stream of Rabbit Sequence
    //! @brief          Helper Function, that Opens and returns Input File Stream
    //!                 of Rabbit Sequnce to Read
    ifstrm_ptr getInputFStream(Context const& ctx);

    //! \fn             getOutputFStream
    //! @param[in]      ctx - Context
    //! @returns        Output File Stream of Rabbit Sequence
    //! @brief          Helper Function, that Opens and returns Output File Stream
    //!                 of Rabbit Sequnce to Write
    ofstrm_ptr getOutputFStream(Context const& ctx);
}
