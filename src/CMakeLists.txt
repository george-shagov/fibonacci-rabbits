# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${rseq_SOURCE_DIR}/include/*.hpp")
set(HEADER_LIST
    "${rseq_SOURCE_DIR}/include/ctx.h"
    "${rseq_SOURCE_DIR}/include/deps.h"
    "${rseq_SOURCE_DIR}/include/generators.h"
    "${rseq_SOURCE_DIR}/include/generators.hpp"
    "${rseq_SOURCE_DIR}/include/processor.h"
    "${rseq_SOURCE_DIR}/include/processor.hpp"
    )

set(SOURCE_LIST
            generators.cpp
            ctx.cpp
            processor.cpp
    )

# Make an automatic library - will be static or dynamic based on user setting
add_library(rseq_library
            ${SOURCE_LIST}
            ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(rseq_library PUBLIC ../include)

# All users of this library will need at least C++11
target_compile_features(rseq_library PUBLIC cxx_std_17)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
