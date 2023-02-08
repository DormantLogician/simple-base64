#include <boost/test/unit_test.hpp>

#include "sb64/Letter.h"

BOOST_AUTO_TEST_SUITE(Letter_bits);


BOOST_AUTO_TEST_CASE(Outputs_correct_view_of_bits_within_letter)
{
    const sb64::Letter output{
        std::vector<bool>{true, false, false, false, false, false, false, true}
    };

    const std::vector<bool> expected{true, false, false, false, false, false, false, true};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.bits().cbegin(),
        output.bits().cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_SUITE_END();
