FILE(GLOB_RECURSE atutils_test_sources *.cpp)
add_library(test_main STATIC EXCLUDE_FROM_ALL
    ${atutils_test_sources}
)

include_directories(SYSTEM
    ${Boost_INCLUDE_DIR}
)
