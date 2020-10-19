set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
set(DOXYGEN_GENERATE_LATEX  YES)

doxygen_add_docs(docs
                ctx.h
                rabbits.h
                rabbits.hpp
                generators.h
                generators.hpp
                processor.h
                processor.hpp
                "${CMAKE_CURRENT_SOURCE_DIR}/mainpage.md"
                WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/include"
                )
