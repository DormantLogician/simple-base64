#include <optional>

#include "sb64/detail/to_original_char.h"
#include "sb64/detail/to_alphabet_char.h"
#include "sb64/detail/constant/alphabet.h"

namespace sb64::detail
{
    std::optional<unsigned char> to_original_char(const unsigned long long character)
    {
        for (long long index{0}; index < constant::alphabet.size(); ++index)
        {
            if (*to_alphabet_char(index) == character)
            {
                return index;
            };
        };

        return std::nullopt;
    };
};
