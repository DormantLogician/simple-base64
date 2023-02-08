#include <boost/test/unit_test.hpp>
#include "sb64/Letter.h"

BOOST_AUTO_TEST_SUITE(Letter);

BOOST_AUTO_TEST_CASE(Bits_correct_when_constructing_from_unsigned_char)
{
    const sb64::Letter output{'A'};
    const std::vector<bool> expected{false, true, false, false, false, false, false, true};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.bits().cbegin(),
        output.bits().cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Bits_correct_when_constructing_from_vector_of_bool)
{
    const sb64::Letter output{
        std::vector<bool>{false, true, false, false, false, false, false, true}
    };

    const std::vector<bool> expected{false, true, false, false, false, false, false, true};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.bits().cbegin(),
        output.bits().cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Bits_correct_when_constructing_from_empty_vector_of_bool)
{
    const sb64::Letter output{std::vector<bool>{}};
    const std::vector<bool> expected{};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.bits().cbegin(),
        output.bits().cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Truncates_bits_when_given_vector_of_bool_with_size_more_than_eight)
{
    const sb64::Letter output{
        std::vector<bool>{false, true, false, false, false, false, false, true, true, false, true}
    };

    const std::vector<bool> expected{false, false, false, false, true, true, false, true};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.bits().cbegin(),
        output.bits().cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Bits_correct_when_constructing_from_vector_of_bool_with_size_less_than_eight)
{
    const sb64::Letter output{
        std::vector<bool>{false, true, true}
    };

    const std::vector<bool> expected{false, true, true};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.bits().cbegin(),
        output.bits().cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_SUITE_END();
