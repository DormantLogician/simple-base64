#include <boost/test/unit_test.hpp>

#include "sb64/Letter.h"

BOOST_AUTO_TEST_SUITE(Letter_to_uchar);

BOOST_AUTO_TEST_CASE(Converts_vector_bool_constructed_letter_to_unsigned_character)
{
    const sb64::Letter input{std::vector<bool>{false, true, false, true}};

    BOOST_CHECK_EQUAL(input.to_uchar(), 0b00000101);
};

BOOST_AUTO_TEST_CASE(Converts_unsigned_char_constructed_letter_to_unsigned_character)
{
    const sb64::Letter input{0b10000001};

    BOOST_CHECK_EQUAL(input.to_uchar(), 0b10000001);
};

BOOST_AUTO_TEST_CASE(Converts_empty_letter_to_null_character)
{
    const sb64::Letter input{std::vector<bool>{}};

    BOOST_CHECK_EQUAL(input.to_uchar(), '\0');
};

BOOST_AUTO_TEST_CASE(Converts_letter_with_single_bit_to_unsigned_char)
{
    const sb64::Letter input{std::vector<bool>{true}};

    BOOST_CHECK_EQUAL(input.to_uchar(), 0b00000001);
};

BOOST_AUTO_TEST_SUITE_END();
