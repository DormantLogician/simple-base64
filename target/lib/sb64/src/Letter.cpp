#include <string>
#include <vector>
#include <bitset>
#include <functional>
#include <stdexcept>

#include "sb64/Letter.h"
#include "sb64/detail/utility/iterable_reader.h"
#include "sb64/detail/utility/write_stream.h"

namespace sb64
{
    std::vector<bool> Letter::truncate_bits(const std::vector<bool>& input)
    {
        std::vector<bool> as_bits{};
        auto binary_digit{input.crbegin()};
        for (long long count{0}; ((count < max_size) && (binary_digit != input.crend())); ++count, ++binary_digit)
        {
            as_bits.insert(as_bits.cbegin(), *binary_digit);
        };

        return as_bits;
    };

    std::vector<Letter> Letter::by_bits(const std::vector<Letter>& bit_groups, const long long group_max_size)
    {
        const long long word_size{(group_max_size > Letter::max_size) ? Letter::max_size : group_max_size};

        if (word_size <= 0)
        {
            throw std::invalid_argument{"Max size of string groups must be greater than zero."};
        };

        std::vector<bool> in_bits{Letter::concat_bits(bit_groups)};

        std::vector<Letter> in_letters{};
        const std::function add_letter{[&in_letters](const std::vector<bool>& output) -> bool
        {
            in_letters.push_back(Letter{output});
            return true;
        }};

        const std::function bit_reader{detail::utility::iterable_reader<bool>(in_bits.cbegin(), in_bits.cend())};
        detail::utility::write_stream(word_size, bit_reader, add_letter);

        return in_letters;
    };

    const unsigned char Letter::max_size{8};

    std::vector<unsigned char> Letter::as_uchars(const std::vector<Letter>& input)
    {
        std::vector<unsigned char> characters{};
        for (auto letter{input.cbegin()}; letter < input.cend(); ++letter)
        {
            characters.push_back(letter->to_uchar());
        };

        return characters;
    };

    std::vector<bool> Letter::concat_bits(const std::vector<Letter>& input)
    {
        std::vector<bool> as_bits{};
        for (auto letter{input.cbegin()}; letter != input.cend(); ++letter)
        {
            for (auto binary_digit{letter->bits().cbegin()}; binary_digit < letter->bits().cend(); ++binary_digit)
            {
                as_bits.push_back(*binary_digit);
            };
        };

        return as_bits;
    };

    std::vector<Letter> Letter::by_eight_bits(const std::vector<Letter>& bit_groups)
    {
        return by_bits(bit_groups, 8);
    };

    std::vector<Letter> Letter::by_six_bits(const std::vector<Letter>& bit_groups)
    {
        return by_bits(bit_groups, 6);
    };

    Letter::Letter(const unsigned char init_stored)
        : stored{}
    {
        const std::bitset<max_size> as_uchar{init_stored};
        const std::string as_string{as_uchar.to_string()};
        std::vector<bool> as_bits{};
        for (auto character{as_string.cbegin()}; character < as_string.cend(); ++character)
        {
            as_bits.push_back((*character == '0') ? false : true);
        };

        stored = truncate_bits(as_bits);
    };

    Letter::Letter(const std::vector<bool>& init_stored)
        : stored{truncate_bits(init_stored)}
    {};

    const std::vector<bool>& Letter::bits() const
    {
        return stored;
    };

    unsigned char Letter::to_uchar() const
    {
        std::string as_string{};
        for (auto binary_digit{stored.cbegin()}; binary_digit < stored.cend(); ++binary_digit)
        {
            as_string.push_back((*binary_digit == false) ? '0' : '1');
        };

        const std::bitset<max_size> as_bits{as_string};
        return as_bits.to_ullong();
    };
};
