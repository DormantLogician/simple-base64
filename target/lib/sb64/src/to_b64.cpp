#include <vector>
#include <functional>

#include "sb64/to_b64.h"
#include "sb64/Letter.h"
#include "sb64/detail/to_alphabet_char.h"
#include "sb64/constant/common.h"
#include "sb64/detail/utility/write_stream.h"

namespace sb64
{
    void to_b64(const std::function<std::optional<unsigned char>()>& reader,
                const std::function<void(const std::vector<unsigned char>& output_word)>& writer)
    {
        const unsigned char zero_padd_value{'\0'};
        const std::function word_encoder{[&writer](const std::vector<Letter>& word) -> bool
        {
            // Add zeros to word so we can pad the word later.
            std::vector<Letter> with_padding{word};
            long long padding_amount{0};
            while (with_padding.size() < constant::encoder_word_size)
            {
                with_padding.push_back(zero_padd_value);
                ++padding_amount;
            };

            const std::vector<Letter> in_six_bits{Letter::by_six_bits(with_padding)};
            const std::vector<unsigned char> in_chars{Letter::as_uchars(in_six_bits)};

            std::vector<unsigned char> encoded{};
            for (auto character{in_chars.cbegin()}; character < in_chars.cend(); ++character)
            {
                const unsigned char in_alphabet{*detail::to_alphabet_char(*character)};
                encoded.push_back(in_alphabet);
            };

            // Remove zero pads and replace with pad character.
            for (long long index{0}; index < padding_amount; ++index)
            {
                encoded.pop_back();
            };

            for (long long index{0}; index < padding_amount; ++index)
            {
                encoded.push_back(constant::padd_char);
            };

            writer(encoded);
            return true;
        }};

        detail::utility::write_stream(constant::encoder_word_size, reader, word_encoder);
    };
};
