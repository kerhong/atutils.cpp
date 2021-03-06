enable_testing()
function(create_check_target)
    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} -j8 -V)
endfunction()
function(create_test name files)
    add_executable(${name} EXCLUDE_FROM_ALL ${files})
    add_test(${name} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${name})
    add_dependencies(check ${name})
endfunction()
