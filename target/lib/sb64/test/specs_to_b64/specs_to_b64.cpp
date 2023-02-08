#include <boost/test/unit_test.hpp>
#include <vector>

#include "sb64/constant/common.h"
#include "sb64/to_b64.h"
#include "specs_to_b64/encode_to_uchars.h"

BOOST_AUTO_TEST_SUITE(to_b64);

BOOST_AUTO_TEST_CASE(Empty_output_on_empty_input)
{
    BOOST_TEST(specs_to_b64::encode_to_uchars(std::vector<unsigned char>{}).empty());
};

BOOST_AUTO_TEST_CASE(Encodes_single_regular_character_with_two_padds)
{
    const unsigned char padd{sb64::constant::padd_char};

    const std::vector<unsigned char> output{
        specs_to_b64::encode_to_uchars(std::vector<unsigned char>{'A'})
    };

    const std::vector<unsigned char> expected{'Q', 'Q', padd, padd};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Encodes_single_regular_character_with_one_padd)
{
    const unsigned char padd{sb64::constant::padd_char};

    const std::vector<unsigned char> output{
        specs_to_b64::encode_to_uchars(std::vector<unsigned char>{'A', 'A'})
    };

    const std::vector<unsigned char> expected{'Q', 'U', 'E', padd};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Encodes_single_regular_character_with_no_padds)
{
    const std::vector<unsigned char> output{
        specs_to_b64::encode_to_uchars(std::vector<unsigned char>{'A', 'A', 'A'})
    };

    const std::vector<unsigned char> expected{'Q', 'U', 'F', 'B'};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Encodes_single_null_character)
{
    const unsigned char padd{sb64::constant::padd_char};

    const std::vector<unsigned char> output{
        specs_to_b64::encode_to_uchars(std::vector<unsigned char>{'\0'})
    };

    const std::vector<unsigned char> expected{'A', 'A', padd, padd};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Encodes_single_all_one_bits_character)
{
    const unsigned char padd{sb64::constant::padd_char};

    const std::vector<unsigned char> output{
        specs_to_b64::encode_to_uchars(std::vector<unsigned char>{0b11111111})
    };

    const std::vector<unsigned char> expected{'/', 'w', padd, padd};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Encodes_multiple_null_characters)
{
    const std::vector<unsigned char> output{
        specs_to_b64::encode_to_uchars(std::vector<unsigned char>{'\0', '\0', '\0'})
    };

    const std::vector<unsigned char> expected{'A', 'A', 'A', 'A'};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Encodes_multiple_all_one_bits_characters)
{
    const std::vector<unsigned char> output{
        specs_to_b64::encode_to_uchars(std::vector<unsigned char>{0b11111111, 0b11111111, 0b11111111})
    };

    const std::vector<unsigned char> expected{'/', '/', '/', '/'};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_CASE(Encodes_multiple_words)
{
    const unsigned char padd{sb64::constant::padd_char};

    const std::vector<unsigned char> output{
        specs_to_b64::encode_to_uchars(std::vector<unsigned char>{'w', 'x', 'y', 'w', 'x'})
    };

    const std::vector<unsigned char> expected{'d', '3', 'h', '5', 'd', '3', 'g', padd};

    BOOST_CHECK_EQUAL_COLLECTIONS(
        output.cbegin(),
        output.cend(),
        expected.cbegin(),
        expected.cend()
    );
};

BOOST_AUTO_TEST_SUITE_END();
