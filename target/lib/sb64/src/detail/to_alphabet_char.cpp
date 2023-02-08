#include <stdexcept>

#include "sb64/detail/to_alphabet_char.h"
#include "sb64/detail/constant/alphabet.h"

namespace sb64::detail
{
    std::optional<unsigned char> to_alphabet_char(const long long index)
    {
        try
        {
            return constant::alphabet.at(index);
        }
        catch(const std::out_of_range& err)
        {
            return std::nullopt;
        };
    };
};
