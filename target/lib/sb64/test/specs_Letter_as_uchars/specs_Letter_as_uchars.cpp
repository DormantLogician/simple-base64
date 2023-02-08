#include <boost/test/unit_test.hpp>

#include "sb64/Letter.h"


BOOST_AUTO_TEST_SUITE(Letter_as_uchar);

BOOST_AUTO_TEST_CASE(Correctly_converts_letters_to_unsigned_characters)
{
    const std::vector<unsigned char> output{
        sb64::Letter::as_uchars(
            std::vector<sb64::Letter>{'A', 'B', 'C', 'D', 'E'}
        )
    };

    const std::vector<unsigned char> expected{'A', 'B', 'C', 'D', 'E'};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Yields_correct_output_with_empty_input_list)
{
    const std::vector<unsigned char> output{
        sb64::Letter::as_uchars(
            std::vector<sb64::Letter>{}
        )
    };

    const std::vector<unsigned char> expected{};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Yields_correct_output_when_input_list_has_single_item)
{
    const std::vector<unsigned char> output{
        sb64::Letter::as_uchars(
            std::vector<sb64::Letter>{'A'}
        )
    };

    const std::vector<unsigned char> expected{'A'};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Yields_correct_output_when_input_list_has_empty_letter)
{
    const std::vector<unsigned char> output{
        sb64::Letter::as_uchars(
            std::vector<sb64::Letter>{sb64::Letter{std::vector<bool>{}}}
        )
    };

    const std::vector<unsigned char> expected{0b00000000};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_SUITE_END();
