#include <vector>

#include "sb64/is_valid_b64.h"
#include "sb64/detail/utility/iterable_reader.h"
#include "specs_is_valid_b64/string_is_valid_b64.h"

namespace specs_is_valid_b64
{
    bool string_is_valid_b64(const std::vector<unsigned char>& input)
    {
        return sb64::is_valid_b64(
            sb64::detail::utility::iterable_reader<unsigned char>(input.cbegin(), input.cend())
        );
    };
};
