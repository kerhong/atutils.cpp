file(GLOB_RECURSE atutils_core_tests *.cpp *.hpp)

create_test(core_test ${atutils_core_tests})

include_directories(
    ${ATUTILS_INCLUDE_DIR}
)

include_directories(SYSTEM
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(core_test
    test_main
)
