#include <boost/test/unit_test.hpp>
#include <optional>

#include "sb64/detail/to_original_char.h"

BOOST_AUTO_TEST_SUITE(to_original_char);

BOOST_AUTO_TEST_CASE(Base64_alphabet_number_associations_are_correct)
{
    BOOST_TEST(sb64::detail::to_original_char('A').value() == 0);
    BOOST_TEST(sb64::detail::to_original_char('B').value() == 1);
    BOOST_TEST(sb64::detail::to_original_char('C').value() == 2);
    BOOST_TEST(sb64::detail::to_original_char('D').value() == 3);
    BOOST_TEST(sb64::detail::to_original_char('E').value() == 4);
    BOOST_TEST(sb64::detail::to_original_char('F').value() == 5);
    BOOST_TEST(sb64::detail::to_original_char('G').value() == 6);
    BOOST_TEST(sb64::detail::to_original_char('H').value() == 7);
    BOOST_TEST(sb64::detail::to_original_char('I').value() == 8);
    BOOST_TEST(sb64::detail::to_original_char('J').value() == 9);
    BOOST_TEST(sb64::detail::to_original_char('K').value() == 10);
    BOOST_TEST(sb64::detail::to_original_char('L').value() == 11);
    BOOST_TEST(sb64::detail::to_original_char('M').value() == 12);
    BOOST_TEST(sb64::detail::to_original_char('N').value() == 13);
    BOOST_TEST(sb64::detail::to_original_char('O').value() == 14);
    BOOST_TEST(sb64::detail::to_original_char('P').value() == 15);
    BOOST_TEST(sb64::detail::to_original_char('Q').value() == 16);
    BOOST_TEST(sb64::detail::to_original_char('R').value() == 17);
    BOOST_TEST(sb64::detail::to_original_char('S').value() == 18);
    BOOST_TEST(sb64::detail::to_original_char('T').value() == 19);
    BOOST_TEST(sb64::detail::to_original_char('U').value() == 20);
    BOOST_TEST(sb64::detail::to_original_char('V').value() == 21);
    BOOST_TEST(sb64::detail::to_original_char('W').value() == 22);
    BOOST_TEST(sb64::detail::to_original_char('X').value() == 23);
    BOOST_TEST(sb64::detail::to_original_char('Y').value() == 24);
    BOOST_TEST(sb64::detail::to_original_char('Z').value() == 25);
    BOOST_TEST(sb64::detail::to_original_char('a').value() == 26);
    BOOST_TEST(sb64::detail::to_original_char('b').value() == 27);
    BOOST_TEST(sb64::detail::to_original_char('c').value() == 28);
    BOOST_TEST(sb64::detail::to_original_char('d').value() == 29);
    BOOST_TEST(sb64::detail::to_original_char('e').value() == 30);
    BOOST_TEST(sb64::detail::to_original_char('f').value() == 31);
    BOOST_TEST(sb64::detail::to_original_char('g').value() == 32);
    BOOST_TEST(sb64::detail::to_original_char('h').value() == 33);
    BOOST_TEST(sb64::detail::to_original_char('i').value() == 34);
    BOOST_TEST(sb64::detail::to_original_char('j').value() == 35);
    BOOST_TEST(sb64::detail::to_original_char('k').value() == 36);
    BOOST_TEST(sb64::detail::to_original_char('l').value() == 37);
    BOOST_TEST(sb64::detail::to_original_char('m').value() == 38);
    BOOST_TEST(sb64::detail::to_original_char('n').value() == 39);
    BOOST_TEST(sb64::detail::to_original_char('o').value() == 40);
    BOOST_TEST(sb64::detail::to_original_char('p').value() == 41);
    BOOST_TEST(sb64::detail::to_original_char('q').value() == 42);
    BOOST_TEST(sb64::detail::to_original_char('r').value() == 43);
    BOOST_TEST(sb64::detail::to_original_char('s').value() == 44);
    BOOST_TEST(sb64::detail::to_original_char('t').value() == 45);
    BOOST_TEST(sb64::detail::to_original_char('u').value() == 46);
    BOOST_TEST(sb64::detail::to_original_char('v').value() == 47);
    BOOST_TEST(sb64::detail::to_original_char('w').value() == 48);
    BOOST_TEST(sb64::detail::to_original_char('x').value() == 49);
    BOOST_TEST(sb64::detail::to_original_char('y').value() == 50);
    BOOST_TEST(sb64::detail::to_original_char('z').value() == 51);
    BOOST_TEST(sb64::detail::to_original_char('0').value() == 52);
    BOOST_TEST(sb64::detail::to_original_char('1').value() == 53);
    BOOST_TEST(sb64::detail::to_original_char('2').value() == 54);
    BOOST_TEST(sb64::detail::to_original_char('3').value() == 55);
    BOOST_TEST(sb64::detail::to_original_char('4').value() == 56);
    BOOST_TEST(sb64::detail::to_original_char('5').value() == 57);
    BOOST_TEST(sb64::detail::to_original_char('6').value() == 58);
    BOOST_TEST(sb64::detail::to_original_char('7').value() == 59);
    BOOST_TEST(sb64::detail::to_original_char('8').value() == 60);
    BOOST_TEST(sb64::detail::to_original_char('9').value() == 61);
    BOOST_TEST(sb64::detail::to_original_char('+').value() == 62);
    BOOST_TEST(sb64::detail::to_original_char('/').value() == 63);
};

BOOST_AUTO_TEST_CASE(Empty_output_when_input_character_is_out_of_range)
{
    const std::optional<unsigned char> not_in_alphabet{sb64::detail::to_original_char(-1)};
    BOOST_TEST(!not_in_alphabet.has_value());
};

BOOST_AUTO_TEST_SUITE_END();
