set(ATUTILS_INCLUDE_DIR ${CMAKE_SOURCE_DIR})

add_subdirectory(test_main) # Test runner 'main()' function
create_check_target()

add_subdirectory(core)
