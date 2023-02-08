#include <boost/test/unit_test.hpp>
#include <vector>

#include "sb64/constant/common.h"
#include "sb64/detail/utility/iterable_reader.h"
#include "specs_is_valid_b64/string_is_valid_b64.h"

BOOST_AUTO_TEST_SUITE(is_valid_b64);

BOOST_AUTO_TEST_CASE(Outputs_true_when_given_a_single_valid_base64_word_without_padds)
{
    const std::vector<unsigned char> input{'a', 'b', 'u', 'b'};
    BOOST_TEST(specs_is_valid_b64::string_is_valid_b64(input));
};

BOOST_AUTO_TEST_CASE(Outputs_true_when_given_a_single_valid_base64_word_with_one_padd)
{
    const unsigned char padd{sb64::constant::padd_char};
    const std::vector<unsigned char> input{'a', 'b', 'u', padd};

    BOOST_TEST(specs_is_valid_b64::string_is_valid_b64(input));
};

BOOST_AUTO_TEST_CASE(Outputs_true_when_given_a_single_valid_base64_word_with_two_padds)
{
    const unsigned char padd{sb64::constant::padd_char};
    const std::vector<unsigned char> input{'a', 'b', padd, padd};

    BOOST_TEST(specs_is_valid_b64::string_is_valid_b64(input));
};

BOOST_AUTO_TEST_CASE(Outputs_true_when_given_a_multiple_valid_base64_words)
{
    const unsigned char padd{sb64::constant::padd_char};
    const std::vector<unsigned char> input{'a', 'b', 'u', 'b', 'a', 'b', 'u', padd, 'a', 'b', padd, padd};

    BOOST_TEST(specs_is_valid_b64::string_is_valid_b64(input));
};

BOOST_AUTO_TEST_CASE(Outputs_false_on_single_non_b64_character)
{
    const std::vector<unsigned char> input{'Q', ' ', 'Q', 'Q'};
    BOOST_TEST(!specs_is_valid_b64::string_is_valid_b64(input));
};

BOOST_AUTO_TEST_CASE(Outputs_false_on_non_b64_word)
{
    const std::vector<unsigned char> input{'Q', 'Q', '=', '=', 'Q', 'Q', 'Q', ' '};
    BOOST_TEST(!specs_is_valid_b64::string_is_valid_b64(input));
};

BOOST_AUTO_TEST_CASE(Outputs_false_on_extra_padd)
{
    const std::vector<unsigned char> input{'Q', '=', '=', '='};
    BOOST_TEST(!specs_is_valid_b64::string_is_valid_b64(input));
};

BOOST_AUTO_TEST_CASE(Outputs_false_on_padd_in_wrong_position)
{
    const std::vector<unsigned char> input{'=', 'Q', 'Q', 'Q'};
    BOOST_TEST(!specs_is_valid_b64::string_is_valid_b64(input));
};

BOOST_AUTO_TEST_CASE(Outputs_true_on_empty_input)
{
    const std::vector<unsigned char> input{};
    BOOST_TEST(specs_is_valid_b64::string_is_valid_b64(input));
};

BOOST_AUTO_TEST_CASE(Outputs_false_for_single_characters)
{
    const std::vector<unsigned char> input{'Q'};
    BOOST_TEST(!specs_is_valid_b64::string_is_valid_b64(input));
};

BOOST_AUTO_TEST_SUITE_END();
