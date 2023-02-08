#include <boost/test/unit_test.hpp>
#include <vector>

#include "testing_sb64/decode_to_uchars.h"
#include "sb64/constant/common.h"

BOOST_AUTO_TEST_SUITE(decode_b64);

BOOST_AUTO_TEST_CASE(Decodes_whole_b64_word_with_no_padds)
{
    const unsigned char padd{sb64::constant::padd_char};

    const std::vector<unsigned char> input{
        testing_sb64::decode_to_uchars(std::vector<unsigned char>{'d', '3', 'h', '5'})
    };

    const std::vector<unsigned char> expected{'w', 'x', 'y'};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        input.cbegin(),
        input.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Decodes_b64_word_with_single_padd)
{
    const unsigned char padd{sb64::constant::padd_char};

    const std::vector<unsigned char> input{
        testing_sb64::decode_to_uchars(std::vector<unsigned char>{'d', '3', 'g', padd})
    };

    const std::vector<unsigned char> expected{'w', 'x'};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        input.cbegin(),
        input.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Decodes_b64_word_with_two_padds)
{
    const unsigned char padd{sb64::constant::padd_char};

    const std::vector<unsigned char> input{
        testing_sb64::decode_to_uchars(std::vector<unsigned char>{'d', 'w', padd, padd})
    };

    const std::vector<unsigned char> expected{'w'};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        input.cbegin(),
        input.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Empty_output_on_empty_input)
{
    const std::vector<unsigned char> input{
        testing_sb64::decode_to_uchars(std::vector<unsigned char>{})
    };

    const std::vector<unsigned char> expected{};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        input.cbegin(),
        input.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Decodes_single_b64_encoded_null_character)
{
    const unsigned char padd{sb64::constant::padd_char};

    const std::vector<unsigned char> input{
        testing_sb64::decode_to_uchars(std::vector<unsigned char>{'A', 'A', padd, padd})
    };

    const std::vector<unsigned char> expected{'\0'};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        input.cbegin(),
        input.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Decodes_word_composed_of_all_encoded_null_characters)
{
    const unsigned char padd{sb64::constant::padd_char};

    const std::vector<unsigned char> input{
        testing_sb64::decode_to_uchars(std::vector<unsigned char>{'A', 'A', 'A', 'A'})
    };

    const std::vector<unsigned char> expected{'\0', '\0', '\0'};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        input.cbegin(),
        input.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Decodes_word_composed_of_all_encoded_one_bit_characters)
{
    const unsigned char padd{sb64::constant::padd_char};

    const std::vector<unsigned char> input{
        testing_sb64::decode_to_uchars(std::vector<unsigned char>{'/', '/', '/', '/'})
    };

    const std::vector<unsigned char> expected{0b11111111, 0b11111111, 0b11111111};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        input.cbegin(),
        input.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Decodes_b64_word_containing_all_one_bits)
{
    const unsigned char padd{sb64::constant::padd_char};

    const std::vector<unsigned char> input{
        testing_sb64::decode_to_uchars(std::vector<unsigned char>{'/', 'w', padd, padd})
    };

    const std::vector<unsigned char> expected{0b11111111};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        input.cbegin(),
        input.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Decodes_multiple_b64_words)
{
    const unsigned char padd{sb64::constant::padd_char};

    const std::vector<unsigned char> input{
        testing_sb64::decode_to_uchars(std::vector<unsigned char>{'d', '3', 'h', '5', 'd', '3', 'g', padd})
    };

    const std::vector<unsigned char> expected{'w', 'x', 'y', 'w', 'x'};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        input.cbegin(),
        input.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Throws_on_invalid_b64)
{
    BOOST_CHECK_THROW(testing_sb64::decode_to_uchars(std::vector<unsigned char>{'Q', ' ', 'U', 'J'}), std::invalid_argument);
    BOOST_CHECK_THROW(testing_sb64::decode_to_uchars(std::vector<unsigned char>{'=', 'Q', 'U', 'J'}), std::invalid_argument);
    BOOST_CHECK_THROW(testing_sb64::decode_to_uchars(std::vector<unsigned char>{'A', 'Q', '=', 'J'}), std::invalid_argument);
    BOOST_CHECK_THROW(testing_sb64::decode_to_uchars(std::vector<unsigned char>{'A', '=', '=', '='}), std::invalid_argument);
    BOOST_CHECK_THROW(testing_sb64::decode_to_uchars(std::vector<unsigned char>{'=', '=', '=', '='}), std::invalid_argument);
    BOOST_CHECK_THROW(testing_sb64::decode_to_uchars(std::vector<unsigned char>{'A', '=', 'U', 'J'}), std::invalid_argument);
};

BOOST_AUTO_TEST_SUITE_END();
