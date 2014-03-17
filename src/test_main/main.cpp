#define BOOST_TEST_MODULE atutils
#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>

/*
    This file is to compile and link this huge header
    just once to get main(), so the much smaller
    <boost/test/unit_test.hpp> can be used in all
    other test files.
*/
