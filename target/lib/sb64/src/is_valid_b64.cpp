#include <vector>
#include <optional>
#include <functional>

#include "sb64/is_valid_b64.h"
#include "sb64/constant/common.h"
#include "sb64/detail/to_original_char.h"
#include "sb64/detail/utility/write_stream.h"

namespace sb64
{
    bool is_valid_b64(const std::function<std::optional<unsigned char>()>& reader)
    {
        const std::function padded_correctly{[](const std::vector<unsigned char>& input) -> bool
        {
            const long long min_padd_index{2};
            if (input.size() == 0)
            {
                return true;
            };

            long long padds_found{0};
            for (long long index{0}; index < input.size(); ++index)
            {
                const unsigned char character{input[index]};
                if (character == constant::padd_char)
                {
                    const bool after_second_element{index >= min_padd_index};
                    if (!after_second_element)
                    {
                        return false;
                    };

                    ++padds_found;
                }
                else if (padds_found > 0)
                {
                    return false;
                };
            };

            const long long size_as_llong{static_cast<long long>(input.size())};
            const long long size_without_padds{size_as_llong - padds_found};
            const bool is_too_short{size_without_padds < min_padd_index};
            const long long expected_padds{constant::decoder_word_size - size_without_padds};
            return (is_too_short ? false : (padds_found == expected_padds));
        }};

        const std::function has_only_b64_letters{[](const std::vector<unsigned char>& input) -> bool
        {
            for (auto character{input.cbegin()}; character < input.cend(); ++character)
            {
                const std::optional<unsigned char> as_original_char{detail::to_original_char(*character)};

                const bool exists_in_alphabet{as_original_char.has_value()};
                if (!exists_in_alphabet && (*character != constant::padd_char))
                {
                    return false;
                };
            };

            return true;
        }};

        bool is_b64{true};
        const std::function valid{[&padded_correctly, &has_only_b64_letters, &is_b64](const std::vector<unsigned char>& output) -> bool
        {
            const bool is_correct_size{output.size() == constant::decoder_word_size};
            is_b64 = (is_correct_size && 
                      padded_correctly(output) && 
                      has_only_b64_letters(output));

            return is_b64;
        }};

        detail::utility::write_stream(constant::decoder_word_size, reader, valid);
        return is_b64;
    };
};
