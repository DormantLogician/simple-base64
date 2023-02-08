#include <vector>
#include <functional>
#include <stdexcept>

#include "sb64/decode_b64.h"
#include "sb64/Letter.h"
#include "sb64/detail/utility/iterable_reader.h"
#include "sb64/is_valid_b64.h"
#include "sb64/constant/common.h"
#include "sb64/detail/to_original_char.h"
#include "sb64/detail/utility/write_stream.h"

namespace sb64
{
    void decode_b64(const std::function<std::optional<unsigned char>()>& reader,
                    const std::function<void(const std::vector<unsigned char>& output_text)>& writer)
    {
        const std::function word_decoder{[&writer](const std::vector<unsigned char>& word) -> bool
        {
            if (!is_valid_b64(detail::utility::iterable_reader<unsigned char>(word.cbegin(), word.cend())))
            {
                throw std::invalid_argument{"Arguments to decoder must be valid base 64 encoded data."};
            };

            // Read word six bits at a time first.
            std::vector<Letter> by_six_bits{};
            for (auto character{word.cbegin()}; character < word.cend(); ++character)
            {
                if (*character != constant::padd_char)
                {
                    const Letter as_original_char{*detail::to_original_char(*character)};
                    std::vector<bool> as_bits{as_original_char.bits()};

                    for (long long index{0}; index < 2; ++index)
                    {
                        as_bits.erase(as_bits.cbegin());
                    };

                    by_six_bits.push_back(Letter{as_bits});
                };
            };

            std::vector<Letter> in_eight_bits{Letter::by_eight_bits(by_six_bits)};

            // Remove trailing bits after operation.
            const bool has_trailing_bits{!in_eight_bits.empty() && (in_eight_bits.back().bits().size() < 8)};
            if (has_trailing_bits)
            {
                in_eight_bits.pop_back();
            };

            const std::vector<unsigned char> in_uchars{Letter::as_uchars(in_eight_bits)};
            writer(in_uchars);

            return true;
        }};

        detail::utility::write_stream(constant::decoder_word_size, reader, word_decoder);
    };
};
