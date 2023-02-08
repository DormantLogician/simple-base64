#include <boost/test/unit_test.hpp>
#include <optional>

#include "sb64/detail/to_alphabet_char.h"

BOOST_AUTO_TEST_SUITE(to_alphabet_char);

BOOST_AUTO_TEST_CASE(Base64_alphabet_character_associations_are_correct)
{
    BOOST_TEST(sb64::detail::to_alphabet_char(0).value() == 'A');
    BOOST_TEST(sb64::detail::to_alphabet_char(1).value() == 'B');
    BOOST_TEST(sb64::detail::to_alphabet_char(2).value() == 'C');
    BOOST_TEST(sb64::detail::to_alphabet_char(3).value() == 'D');
    BOOST_TEST(sb64::detail::to_alphabet_char(4).value() == 'E');
    BOOST_TEST(sb64::detail::to_alphabet_char(5).value() == 'F');
    BOOST_TEST(sb64::detail::to_alphabet_char(6).value() == 'G');
    BOOST_TEST(sb64::detail::to_alphabet_char(7).value() == 'H');
    BOOST_TEST(sb64::detail::to_alphabet_char(8).value() == 'I');
    BOOST_TEST(sb64::detail::to_alphabet_char(9).value() == 'J');
    BOOST_TEST(sb64::detail::to_alphabet_char(10).value() == 'K');
    BOOST_TEST(sb64::detail::to_alphabet_char(11).value() == 'L');
    BOOST_TEST(sb64::detail::to_alphabet_char(12).value() == 'M');
    BOOST_TEST(sb64::detail::to_alphabet_char(13).value() == 'N');
    BOOST_TEST(sb64::detail::to_alphabet_char(14).value() == 'O');
    BOOST_TEST(sb64::detail::to_alphabet_char(15).value() == 'P');
    BOOST_TEST(sb64::detail::to_alphabet_char(16).value() == 'Q');
    BOOST_TEST(sb64::detail::to_alphabet_char(17).value() == 'R');
    BOOST_TEST(sb64::detail::to_alphabet_char(18).value() == 'S');
    BOOST_TEST(sb64::detail::to_alphabet_char(19).value() == 'T');
    BOOST_TEST(sb64::detail::to_alphabet_char(20).value() == 'U');
    BOOST_TEST(sb64::detail::to_alphabet_char(21).value() == 'V');
    BOOST_TEST(sb64::detail::to_alphabet_char(22).value() == 'W');
    BOOST_TEST(sb64::detail::to_alphabet_char(23).value() == 'X');
    BOOST_TEST(sb64::detail::to_alphabet_char(24).value() == 'Y');
    BOOST_TEST(sb64::detail::to_alphabet_char(25).value() == 'Z');
    BOOST_TEST(sb64::detail::to_alphabet_char(26).value() == 'a');
    BOOST_TEST(sb64::detail::to_alphabet_char(27).value() == 'b');
    BOOST_TEST(sb64::detail::to_alphabet_char(28).value() == 'c');
    BOOST_TEST(sb64::detail::to_alphabet_char(29).value() == 'd');
    BOOST_TEST(sb64::detail::to_alphabet_char(30).value() == 'e');
    BOOST_TEST(sb64::detail::to_alphabet_char(31).value() == 'f');
    BOOST_TEST(sb64::detail::to_alphabet_char(32).value() == 'g');
    BOOST_TEST(sb64::detail::to_alphabet_char(33).value() == 'h');
    BOOST_TEST(sb64::detail::to_alphabet_char(34).value() == 'i');
    BOOST_TEST(sb64::detail::to_alphabet_char(35).value() == 'j');
    BOOST_TEST(sb64::detail::to_alphabet_char(36).value() == 'k');
    BOOST_TEST(sb64::detail::to_alphabet_char(37).value() == 'l');
    BOOST_TEST(sb64::detail::to_alphabet_char(38).value() == 'm');
    BOOST_TEST(sb64::detail::to_alphabet_char(39).value() == 'n');
    BOOST_TEST(sb64::detail::to_alphabet_char(40).value() == 'o');
    BOOST_TEST(sb64::detail::to_alphabet_char(41).value() == 'p');
    BOOST_TEST(sb64::detail::to_alphabet_char(42).value() == 'q');
    BOOST_TEST(sb64::detail::to_alphabet_char(43).value() == 'r');
    BOOST_TEST(sb64::detail::to_alphabet_char(44).value() == 's');
    BOOST_TEST(sb64::detail::to_alphabet_char(45).value() == 't');
    BOOST_TEST(sb64::detail::to_alphabet_char(46).value() == 'u');
    BOOST_TEST(sb64::detail::to_alphabet_char(47).value() == 'v');
    BOOST_TEST(sb64::detail::to_alphabet_char(48).value() == 'w');
    BOOST_TEST(sb64::detail::to_alphabet_char(49).value() == 'x');
    BOOST_TEST(sb64::detail::to_alphabet_char(50).value() == 'y');
    BOOST_TEST(sb64::detail::to_alphabet_char(51).value() == 'z');
    BOOST_TEST(sb64::detail::to_alphabet_char(52).value() == '0');
    BOOST_TEST(sb64::detail::to_alphabet_char(53).value() == '1');
    BOOST_TEST(sb64::detail::to_alphabet_char(54).value() == '2');
    BOOST_TEST(sb64::detail::to_alphabet_char(55).value() == '3');
    BOOST_TEST(sb64::detail::to_alphabet_char(56).value() == '4');
    BOOST_TEST(sb64::detail::to_alphabet_char(57).value() == '5');
    BOOST_TEST(sb64::detail::to_alphabet_char(58).value() == '6');
    BOOST_TEST(sb64::detail::to_alphabet_char(59).value() == '7');
    BOOST_TEST(sb64::detail::to_alphabet_char(60).value() == '8');
    BOOST_TEST(sb64::detail::to_alphabet_char(61).value() == '9');
    BOOST_TEST(sb64::detail::to_alphabet_char(62).value() == '+');
    BOOST_TEST(sb64::detail::to_alphabet_char(63).value() == '/');
};

BOOST_AUTO_TEST_CASE(Empty_output_when_input_index_is_out_of_range)
{
    const std::optional<unsigned char> before_first{sb64::detail::to_alphabet_char(-1)};
    const std::optional<unsigned char> after_last{sb64::detail::to_alphabet_char(64)};

    BOOST_TEST(!before_first.has_value());
    BOOST_TEST(!after_last.has_value());
};

BOOST_AUTO_TEST_SUITE_END();
