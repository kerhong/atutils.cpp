file(GLOB_RECURSE atutils_core_headers ${ATUTILS_INCLUDE_DIR}/atutils/core/*.hpp)
add_library(core STATIC ${atutils_core_headers})
set_target_properties(core PROPERTIES LINKER_LANGUAGE CXX)

include_directories(
    ${ATUTILS_INCLUDE_DIR}
)

include_directories(SYSTEM
    ${Boost_INCLUDE_DIR}
)

add_subdirectory(test)
