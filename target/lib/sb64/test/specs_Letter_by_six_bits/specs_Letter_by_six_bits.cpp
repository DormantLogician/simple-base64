#include <boost/test/unit_test.hpp>

#include "sb64/Letter.h"

BOOST_AUTO_TEST_SUITE(Letter_by_six_bits);

BOOST_AUTO_TEST_CASE(Empty_list_output_on_empty_list_input)
{
    const std::vector<sb64::Letter> output{sb64::Letter::by_six_bits(std::vector<sb64::Letter>{})};

    BOOST_CHECK_EQUAL(output.size(), 0);
};

BOOST_AUTO_TEST_CASE(Outputs_correct_character_with_list_that_has_single_element)
{
    const std::vector<sb64::Letter> input{0b10000110};

    const std::vector<unsigned char> expected{
        0b00100001,
        0b00000010
    };

    const std::vector<sb64::Letter> output{
        sb64::Letter::by_six_bits(input)
    };

    const std::vector<unsigned char> uchars{
        sb64::Letter::as_uchars(output)
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        uchars.cbegin(),
        uchars.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Outputs_correct_character_with_list_that_has_letter_less_than_eight_bits)
{
    const std::vector<sb64::Letter> input{
        sb64::Letter{std::vector<bool>{true, false, true}}
    };

    const std::vector<unsigned char> expected{
        0b00000101
    };

    const std::vector<sb64::Letter> output{
        sb64::Letter::by_six_bits(input)
    };

    const std::vector<unsigned char> uchars{
        sb64::Letter::as_uchars(output)
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        uchars.cbegin(),
        uchars.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Outputs_correct_character_with_list_that_has_multiple_letters_less_than_eight_bits)
{
    const std::vector<sb64::Letter> input{
        sb64::Letter{std::vector<bool>{true, false, true}},
        sb64::Letter{std::vector<bool>{true, false, true, true}},
        sb64::Letter{std::vector<bool>{false, false, true, true}}
    };

    const std::vector<unsigned char> expected{
        0b00101101,
        0b00010011
    };

    const std::vector<sb64::Letter> output{
        sb64::Letter::by_six_bits(input)
    };

    const std::vector<unsigned char> uchars{
        sb64::Letter::as_uchars(output)
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        uchars.cbegin(),
        uchars.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Outputs_correct_characters_with_list_that_has_multiple_elements)
{
    const std::vector<sb64::Letter> input{
        0b10000110,
        0b00000101,
        0b01110111
    };

    const std::vector<unsigned char> expected{
        0b00100001,
        0b00100000,
        0b00010101,
        0b00110111
    };

    const std::vector<sb64::Letter> output{
        sb64::Letter::by_six_bits(input)
    };

    const std::vector<unsigned char> uchars{
        sb64::Letter::as_uchars(output)
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        uchars.cbegin(),
        uchars.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Outputs_correct_characters_with_list_that_has_empty_letters)
{
    const std::vector<sb64::Letter> input{
        sb64::Letter{std::vector<bool>{}},
        0b10000110,
        0b00000101,
        sb64::Letter{std::vector<bool>{}},
        0b01110111
    };

    const std::vector<unsigned char> expected{
        0b00100001,
        0b00100000,
        0b00010101,
        0b00110111
    };

    const std::vector<sb64::Letter> output{
        sb64::Letter::by_six_bits(input)
    };

    const std::vector<unsigned char> uchars{
        sb64::Letter::as_uchars(output)
    };

    BOOST_CHECK_EQUAL_COLLECTIONS(
        uchars.cbegin(),
        uchars.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_SUITE_END();
