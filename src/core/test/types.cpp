#include <boost/test/unit_test.hpp>
#include <atutils/core/types.hpp>

BOOST_AUTO_TEST_SUITE(core_types)

BOOST_AUTO_TEST_CASE(type_sizes)
{
    BOOST_CHECK_EQUAL(sizeof(bool), 1);
    BOOST_CHECK_EQUAL(sizeof(::atutils::int8_t), 1);
    BOOST_CHECK_EQUAL(sizeof(::atutils::uint8_t), 1);
    BOOST_CHECK_EQUAL(sizeof(::atutils::int16_t), 2);
    BOOST_CHECK_EQUAL(sizeof(::atutils::uint16_t), 2);
    BOOST_CHECK_EQUAL(sizeof(::atutils::int32_t), 4);
    BOOST_CHECK_EQUAL(sizeof(::atutils::uint32_t), 4);
    BOOST_CHECK_EQUAL(sizeof(::atutils::int64_t), 8);
    BOOST_CHECK_EQUAL(sizeof(::atutils::uint64_t), 8);
    BOOST_CHECK_EQUAL(sizeof(float), 4);
    BOOST_CHECK_EQUAL(sizeof(double), 8);
    BOOST_CHECK_EQUAL(sizeof(void*), 8);
}

BOOST_AUTO_TEST_CASE(packed_struct)
{
#pragma pack(push, 1)
    struct test_packed_struct_t {
        ::atutils::int8_t a;
        ::atutils::int32_t b;
    };
#pragma pack(pop)

    BOOST_CHECK_EQUAL(sizeof(test_packed_struct_t), 5);
}

BOOST_AUTO_TEST_SUITE_END()
