#include <vector>

#include "specs_to_b64/encode_to_uchars.h"
#include "sb64/detail/utility/write_stream.h"
#include "sb64/detail/utility/iterable_reader.h"
#include "sb64/to_b64.h"

namespace specs_to_b64
{
    std::vector<unsigned char> encode_to_uchars(const std::vector<unsigned char>& input)
    {
        std::vector<unsigned char> output{};

        const auto reader{sb64::detail::utility::iterable_reader<unsigned char>(input.cbegin(), input.cend())};
        const auto writer{[&output](const std::vector<unsigned char>& word) -> bool
        {
            for (auto character{word.cbegin()}; character != word.cend(); ++character)
            {
                output.push_back(*character);
            };

            return true;
        }};

        sb64::to_b64(reader, writer);
        return output;
    };
};
